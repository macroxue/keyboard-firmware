all: controller_test vi_command_test

INCLUDES=-I/usr/share/arduino-1.6.12/hardware/teensy/avr/cores/teensy \
         -I/usr/share/arduino-1.6.12/hardware/teensy/avr/cores/teensy3

controller_test: controller_test.cc controller.h key_map.h layout.h matrix.h
	g++ -g -std=c++0x -o $@ $(filter %.cc,$^) ${INCLUDES}

vi_command_test: vi_command_test.cc vi_command.h
	g++ -g -std=c++0x -o $@ $(filter %.cc,$^) ${INCLUDES}
