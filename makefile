all: controller_test vi_command_test vi_translator_test

INCLUDES=-I/usr/share/arduino-1.6.12/hardware/teensy/avr/cores/teensy \
         -I/usr/share/arduino-1.6.12/hardware/teensy/avr/cores/teensy3

controller_test: controller_test.cc controller.h vi_translator.h \
                 events.h key_map.h layout.h matrix.h \
                 fake_clock.h fake_scanner.h fake_sender.h
	g++ -g -std=c++0x -o $@ $(filter %.cc,$^) ${INCLUDES}

vi_command_test: vi_command_test.cc vi_command.h
	g++ -g -std=c++0x -o $@ $(filter %.cc,$^) ${INCLUDES}

vi_translator_test: vi_translator_test.cc vi_translator.h translator.h \
                    events.h key_map.h \
                    fake_clock.h fake_sender.h
	g++ -g -std=c++0x -o $@ $(filter %.cc,$^) ${INCLUDES}
