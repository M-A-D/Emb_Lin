/************************************************************************************************************
 * @file main.c                                                                                             *
 * @brief main file for a simple gpio kernel object example on the BBB                                      *
 * @author m-a-d                                                                                            *
 * @date 20.06.2015                                                                                         *
 ************************************************************************************************************/

# include <stdio.h>
# include <unistd.h>
# include "gpio.h"

/**
 * defines
 **/

# define __KERNEL_
# define MODULE

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

void init_pins(void);
void close_pins(void);


int main(int argc, char *argv[]) {

	PIN_VALUE value_LED = HIGH;
	PIN_VALUE value_SWITCH = HIGH;
	PIN_VALUE temp_val;
	unsigned int i;

	init_pins();

	/** flash LED 5 times */
	for(i = 0; i < 5; i++) {

		/** switch on the LED */
		gpio_write_to_pin(pin_LED, LOW);

		/** sleep for 500 ms */
		usleep(500000);

		/** switch off the LED */
		gpio_write_to_pin(pin_LED, HIGH);

		/** sleep for 500 ms */
		usleep(500000);
	}

	/**
	 * read from the switch and write to the LED every 5 milliseconds
	 * actually it would be better if you would use an interrupt to do so
	 * but for a simple example it should also work like this.
	 **/
	do {
		/** read from switch */
		gpio_read_from_pin(pin_SWITCH, &value_SWITCH);
		
		if(!value_SWITCH) {
			value_LED=!value_LED;
		}
		
		/** write to LED */
		gpio_write_to_pin(pin_LED, value_LED);

		/** wait for five milliseconds */
		usleep(5000);
	} while (1);

	close_pins();
	return 0;
}


/**
 * @brief init_pins
 *
 **/
void init_pins(void) {
	/** export the LED_PIN */
	gpio_export(pin_LED);
	/** export the SWITCH_PIN */
	gpio_export(pin_SWITCH);

	/** the gpio pins need some configuration */
	gpio_set_dir(pin_LED, OUTPUT_PIN);
	gpio_set_dir(pin_SWITCH, INPUT_PIN);
}

/**
 * @brief close_pins
 * 
 **/
void close_pins(void) {
	/** delete the pins */
	gpio_delete_pin(pin_LED);
	gpio_delete_pin(pin_SWITCH);
}

