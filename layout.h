#ifndef LAYOUT_H
#define LAYOUT_H

#include "events.h"
#include "matrix.h"
#include "vi_translator.h"

static const int kMaxLayers = 10;

template <int R, int C>
struct Layer {
  const char* name;
  int layer_id;
  int fn_layer_id;
  const char* translator;
  unsigned char keys[R][C];
};

template <int R, int C>
class Layout {
  public:
    Layout(int num_layers, const Layer<R, C>* layers, Translator* translator)
      : num_layers_(num_layers), translator_(translator) {
      for (int i = 0; i < num_layers_; ++i) layers_[i] = &layers[i];
      cur_layer_ = FindLayer(l0);
    }

    Events Interpret(int num_entries, const Entry* entries) {
      UpdateFnState(num_entries, entries);
      const auto* layer = fn_pressed_ ? FindLayer(cur_layer_->fn_layer_id)
                                      : cur_layer_;
      for (int i = 0; i < num_entries; ++i) Interpret(entries[i], layer);
      return events_;
    }

    Translator* translator() {
      if (translator_ &&
          strcmp(cur_layer_->translator, translator_->name()) == 0) {
        return translator_;
      } else {
        return nullptr;
      }
    }

  private:
    void UpdateFnState(int num_entries, const Entry* entries) {
      for (int i = 0; i < num_entries; ++i) {
        int key = key_map[cur_layer_->keys[entries[i].row][entries[i].col]];
        if (key == fn) {
          fn_pressed_ = entries[i].pressed;
          break;
        }
        if (key == fnl && entries[i].pressed) {
          if (cur_layer_->fn_layer_id != cur_layer_->layer_id) {
            const auto* fn_layer = FindLayer(cur_layer_->fn_layer_id);
            base_layer_ = cur_layer_;
            cur_layer_ = fn_layer;
          } else {
            cur_layer_ = base_layer_;
          }
          break;
        }
      }
    }

    void Interpret(const Entry& entry, const Layer<R,C>* layer) {
      int key = key_map[layer->keys[entry.row][entry.col]];
      if (!key || key == fn || key == fnl) return;
      if (l0 <= key && key < l0 + kMaxLayers) {
        RemoveReleasedKey(entry.row, entry.col);
        auto new_layer = FindLayer(key);
        if (new_layer != cur_layer_) {
          cur_layer_ = new_layer;
        }
        return;
      }
      if (mlc <= key && key <= msd) {
        events_.buttons[key - mlc] = entry.pressed;
        return;
      }
      if (IsModifier(key)) {
        if (entry.pressed) events_.modifiers |= key;
        else events_.modifiers &= ~key;
      } else {
        if (entry.pressed) AddPressedKey(key, entry.row, entry.col);
        else RemoveReleasedKey(entry.row, entry.col);
      }
    }

    void AddPressedKey(int key, int row, int col) {
      for (int i = 0; i < kMaxEvents; ++i) {
        if (events_.keys[i].key != 0 &&
            events_.keys[i].row == row && events_.keys[i].col == col) return;
      }
      for (int i = 0; i < kMaxEvents; ++i) {
        if (events_.keys[i].key == 0) {
          events_.keys[i].key = key;
          events_.keys[i].row = row;
          events_.keys[i].col = col;
          return;
        }
      }
      //Keyboard.print(key);
    }

    void RemoveReleasedKey(int row, int col) {
      for (int i = 0; i < kMaxEvents; ++i) {
        if (events_.keys[i].row == row && events_.keys[i].col == col) {
          events_.keys[i].key = 0;
          return;
        }
      }
      //Keyboard.print(-key);
    }

    bool IsModifier(int key) const {
      return MODIFIERKEY_CTRL <= key && key <= MODIFIERKEY_RIGHT_GUI;
    }

    const Layer<R,C>* FindLayer(int layer_id) const {
      for (int i = 0; i < num_layers_; ++i) {
        if (layers_[i]->layer_id == layer_id) return layers_[i];
      }
      return nullptr;
    }

    const int num_layers_ = 0;
    const Layer<R,C>* layers_[kMaxLayers];
    const Layer<R,C>* cur_layer_ = nullptr;
    const Layer<R,C>* base_layer_ = nullptr;
    Translator* const translator_ = nullptr;
    bool fn_pressed_ = false;
    Events events_;
};

#endif
