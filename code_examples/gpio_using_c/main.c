/**
 * @file main.c
 * @brief main file for a simple gpio example on the BBB
 * @author m-a-d
 * @date 20.06.2015
 **/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "unistd.h"
# include "gpio.h"

/**
 * globals
 **/

unsigned int pin_LED = 30;
unsigned int pin_SWITCH = 31;

/**
 * calculate the pin number:
 * GPIO<REGISTER>_<NUMBER>
 * pin_number := (REGISTER * 32) + NUMBER
 * e.g.
 * pin_number of GPIO1_28 = (1 * 32) + 28 = 60
 * pin_number of GPIO0_5  = (0 * 32) + 5  =  5
 * and so on...
 * !!ATTENTION!!
 * On my test Hardware the led and switch are low active if you decide to thest this on your hardware
 * you may have to change the values of a few variables!
 **/

int main(int argc, char *argv[]) {

	PIN_VALUE value = HIGH;
	unsigned int i;

	printf("%s", "A Simple GPIO Example \n");

	/** export the LED_PIN */
	gpio_export(pin_LED);
	/** export the SWITCH_PIN */
	gpio_export(pin_SWITCH);

	/** the gpio pins need some configuration */
	gpio_set_dir(pin_LED, OUTPUT_PIN);
	gpio_set_dir(pin_SWITCH, INPUT_PIN);

	/** flash LED 5 times */
	for(i = 0; i < 5; i++) {
		printf("%s", "LED switched on \n");
		gpio_write_to_pin(pin_LED, LOW);

		/** sleep for 500 ms */
		usleep(500000);
		printf("%s", "LED switched on \n");
		gpio_write_to_pin(pin_LED, HIGH);

		/** sleep for 500 ms */
		usleep(500000);
	}

	printf("%s", "now press the button \n");

	do {
		gpio_read_from_pin(pin_SWITCH, &value);
		printf("%c", '.');

		/** wait for two milliseconds */
		usleep(2000);
	} while (value != LOW);

	printf("%s", "\n test programm just finished! \n");

	/** delete the pins */
	gpio_delete_pin(pin_LED);
	gpio_delete_pin(pin_SWITCH);

	return 0;
}

