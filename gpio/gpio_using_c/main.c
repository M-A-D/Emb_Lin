/**
 * @file main.c
 * @brief main file for a simple gpio example on the BBB
 * @author m-a-d
 * @date 20.06.2015
 **/

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>

# include "gpio.h"

int main() {

	printf("%s", "Hello World! \n");

	return 0;
	char cmd = 4;
	while(cmd) {
		read_from_pin();
		write_to_pin();
	}
}

