#ifndef FAKE_SENDER_H
#define FAKE_SENDER_H

class FakeSender : public Sender {
  public:
    void Send(const Events& events) override {
      auto modifiers = events.modifiers & ~0xE000;
      if (modifiers & MODIFIERKEY_LEFT_CTRL) printf("lC-");
      if (modifiers & MODIFIERKEY_LEFT_SHIFT) printf("lS-");
      if (modifiers & MODIFIERKEY_LEFT_ALT) printf("lA-");
      if (modifiers & MODIFIERKEY_LEFT_GUI) printf("lG-");
      if (modifiers & MODIFIERKEY_RIGHT_CTRL) printf("rC-");
      if (modifiers & MODIFIERKEY_RIGHT_SHIFT) printf("rS-");
      if (modifiers & MODIFIERKEY_RIGHT_ALT) printf("rA-");
      if (modifiers & MODIFIERKEY_RIGHT_GUI) printf("rG-");
      for (int i = 0; i < kMaxEvents; ++i) {
        if (events.keys[i].key == 0) continue;

        int ch;
        for (ch = 0; ch < 256 && key_map[ch] != events.keys[i].key; ++ch);
        if (32 <= ch && ch <= 127) putchar(ch);
        else {
          switch (ch) {
            case ent: printf("ent"); break;
            case esc: printf("esc"); break;
            case del: printf("del"); break;
            case bks: printf("bks"); break;
            case spc: printf("spc"); break;
            case up: printf("up"); break;
            case dn: printf("dn"); break;
            case lt: printf("lt"); break;
            case rt: printf("rt"); break;
            case hom: printf("hom"); break;
            case end: printf("end"); break;
            case pgu: printf("pgu"); break;
            case pgd: printf("pgd"); break;
            default: printf("\\%d", ch); break;
          }
        }
      }
      putchar('\n');

      events_ = events;
    }

    Events events() const { return events_; }

  private:
    Events events_;
};

#endif
