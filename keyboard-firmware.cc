RealScanner<R,C> scanner(row_pins, col_pins);
RealSender sender;
RealClock clock;
DbgTranslator<R,C> dbg_translator(row_pins, col_pins,
                                  sizeof(layers)/sizeof(layers[0]), layers);
ViTranslator vi_translator(&clock);
Translator* translators[] = {&dbg_translator, &vi_translator};
Layout<R,C> layout(sizeof(layers)/sizeof(layers[0]), layers,
                   sizeof(translators)/sizeof(translators[0]),
                   translators);
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
