/********************************************************************************************************
 * @file gpio.h
 * @brief definitions of gpio operations on the BBB
 * @author m-a-d
 * @date 20.06.2015
 ********************************************************************************************************/

# ifndef GPIO_H_
# define GPIO_H_

/**
 * defines
 **/

# define SYS_FS_DIR "/sys/class/gpio"
# define POLL_TIMEOUT (3 * 1000) /* 3 seconds */
# define MAX_BUF 64
# define LED        "GPIO05"
# define TASTER     "GPIO04"

/**
 * enumerations and structs
 **/

typedef enum {
	INPUT_PIN=0,
	OUTPUT_PIN=1
} PIN_DIRECTION;

typedef enum {
	LOW=0,
	HIGH=1
} PIN_VALUE;

/**
 * functions
 **/

int gpio_export(unsigned int gpio);
int gpio_unexport(unsigned int gpio);
int gpio_set_dir(unsigned int gpio, PIN_DIRECTION out_flag);
int gpio_write_to_pin(unsigned int pin, PIN_VALUE value);
int gpio_read_from_pin(unsigned int pin, unsigned int *value);

int gpio_set_edge(unsigned int pin, char *edge);
int gpio_init_pin(unsigned int gpio);
int gpio_delete_pin(int fd);

# endif /* GPIO_H_ */

