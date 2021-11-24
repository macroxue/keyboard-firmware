#ifndef FAKE_SENDER_H
#define FAKE_SENDER_H

#include <sstream>

class FakeSender : public Sender {
  public:
    ~FakeSender() {
      assert(events_.modifiers == 0);
      for (int i = 0; i < kMaxEvents; ++i) {
        assert(events_.keys[i].key == 0);
      }
    }

    void Send(const Events& events) override {
      bool key_pressed = false;
      for (int i = 0; i < kMaxEvents; ++i) {
        if (events.keys[i].key == 0) continue;
        if (key_pressed) stream_ << ' ';
        else ShowModifiers(events);
        key_pressed = true;

        int ch;
        for (ch = 0; ch < 256 && key_map[ch] != events.keys[i].key; ++ch);
        if (33 <= ch && ch <= 127) stream_ << char(ch);
        else {
          switch (ch) {
            case ent: stream_ << "ent"; break;
            case esc: stream_ << "esc"; break;
            case del: stream_ << "del"; break;
            case bks: stream_ << "bks"; break;
            case spc: stream_ << "spc"; break;
            case up: stream_ << "up"; break;
            case dn: stream_ << "dn"; break;
            case lt: stream_ << "lt"; break;
            case rt: stream_ << "rt"; break;
            case hom: stream_ << "hom"; break;
            case end: stream_ << "end"; break;
            case pgu: stream_ << "pgu"; break;
            case pgd: stream_ << "pgd"; break;
            default: stream_ << '\\' << ch; break;
          }
        }
      }
      if (key_pressed) stream_ << '\n';

      events_ = events;
    }

    void Send(const char* message) override { puts(message); }
    void Delay(int ms) override {}

    Events events() const { return events_; }
    std::string stream() const { return stream_.str(); }

  private:
    void ShowModifiers(const Events& events) {
      auto modifiers = events.modifiers & ~0xE000;
      if (modifiers & MODIFIERKEY_LEFT_CTRL) stream_ << "lC-";
      if (modifiers & MODIFIERKEY_LEFT_SHIFT) stream_ << "lS-";
      if (modifiers & MODIFIERKEY_LEFT_ALT) stream_ << "lA-";
      if (modifiers & MODIFIERKEY_LEFT_GUI) stream_ << "lG-";
      if (modifiers & MODIFIERKEY_RIGHT_CTRL) stream_ << "rC-";
      if (modifiers & MODIFIERKEY_RIGHT_SHIFT) stream_ << "rS-";
      if (modifiers & MODIFIERKEY_RIGHT_ALT) stream_ << "rA-";
      if (modifiers & MODIFIERKEY_RIGHT_GUI) stream_ << "rG-";
    }

    Events events_;
    std::stringstream stream_;
};

#endif
