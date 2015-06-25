/*****************************************************************************************************************
 * @file gpio.c                                                                                                  *
 * @brief implementation of gpio operations on the BBB                                                           *
 * @author m-a-d                                                                                                 *
 * @date 20.06.2015                                                                                              *
 *****************************************************************************************************************/

# include "gpio.h"

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <poll.h>


/**
 * gpio_export
 **/
int gpio_export(unsigned int pin) {
	int fd, len;
	char buf[MAX_BUF];

	fd = open(SYS_FS_DIR "/export", O_WRONLY);
	if (fd < 0) {
		perror("gpio/export");
		return fd;
	}

	len = snprintf(buf, sizeof(buf), "%d", pin);
	write(fd, buf, len);
	close(fd);
	return 0;
}


/**
 * gpio_unexport
 **/
int gpio_unexport(unsigned int pin) {
	int fd, len;
	char buf[MAX_BUF];

	fd = open(SYS_FS_DIR "/unexport", O_WRONLY);
	if (fd < 0) {
		perror("gpio/export");
		return fd;
	}

	len = snprintf(buf, sizeof(buf), "%d", pin);
	write(fd, buf, len);
	close(fd);
	return 0;
}


/**
 * gpio_set_dir
 **/
int gpio_set_dir(unsigned int gpio, PIN_DIRECTION out_flag) {
	int fd;
	char buf[MAX_BUF];

	snprintf(buf, sizeof(buf), SYS_FS_DIR "/gpio%d/direction", gpio);

	fd = open(buf, O_WRONLY);
	if (fd < 0) {
		perror("gpio/direction");
		return fd;
	}

	if (out_flag == OUTPUT_PIN)
		write(fd, "out", 4);
	else
		write(fd, "in", 3);

	close(fd);
	return 0;
}


/**
 * gpio_write_to_pin
 **/
int gpio_write_to_pin(unsigned int pin, PIN_VALUE value) {
	int fd;
	char buf[MAX_BUF];

	snprintf(buf, sizeof(buf), SYS_FS_DIR "/gpio%d/value", pin);

	fd = open(buf, O_WRONLY);
	if (fd < 0) {
		perror("gpio/set-value");
		return fd;
	}

	if (value==LOW)
		write(fd, "0", 2);
	else
		write(fd, "1", 2);

	close(fd);
	return 0;
}


/**
 * gpio_read_from_pin
 **/
int gpio_read_from_pin(unsigned int pin, unsigned int *value) {
	int fd;
	char buf[MAX_BUF];
	char ch;

	snprintf(buf, sizeof(buf), SYS_FS_DIR "/gpio%d/value", pin);

	fd = open(buf, O_RDONLY);
	if (fd < 0) {
		perror("gpio/get-value");
		return fd;
	}

	read(fd, &ch, 1);

	if (ch != '0') {
		*value = 1;
	} else {
		*value = 0;
	}

	close(fd);
	return fd;
}


/**
 * gpio_set_edge
 **/
int gpio_set_edge(unsigned int pin, char *edge) {
	int fd;
	char buf[MAX_BUF];

	snprintf(buf, sizeof(buf), SYS_FS_DIR "/gpio%d/edge", pin);

	fd = open(buf, O_WRONLY);
	if (fd < 0) {
		perror("gpio/set-edge");
		return fd;
	}

	write(fd, edge, strlen(edge) + 1);
	close(fd);
	return 0;
}


/**
 * gpio_init_pin
 **/
int gpio_init_pin(unsigned int pin) {
	int fd;
	char buf[MAX_BUF];

	snprintf(buf, sizeof(buf), SYS_FS_DIR "/gpio%d/value", pin);

	fd = open(buf, O_RDONLY | O_NONBLOCK );
	if (fd < 0) {
		perror("gpio/fd_open");
	}
	return fd;
}

/**
 * gpio_shut_down_pin
 **/
int gpio_delete_pin(int fd)
{
	return close(fd);
}
