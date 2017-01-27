#include "controller.h"
#include "real_clock.h"
#include "real_scanner.h"
#include "real_sender.h"

// Include one and only one keyboard below.
//#include "left_split.h"
//#include "right_split.h"
//#include "geng_yun.h"
#include "geng_yun_vi.h"

RealScanner<R,C> scanner(row_pins, col_pins);
RealSender sender;
RealClock clock;
ViTranslator translator(&clock);
Layout<R,C> layout(sizeof(layers)/sizeof(layers[0]), layers, &translator);
Controller<R,C> controller(&layout, &scanner, &sender);

void setup() {
  Serial.begin(9600);
}

void loop() {
  static const unsigned long kDebounceMs = 15;
  static unsigned long last_scan = 0;
  auto now = millis();
  if (now - last_scan > kDebounceMs) {
    last_scan = now;
    controller.Scan();
  }
}  // End loop
