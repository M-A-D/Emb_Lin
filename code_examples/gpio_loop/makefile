# @file makefile
# @brief makefile for gpio on BBB
# @author m-a-d
# @date 20.06.2015


VERSION = 0.1
CC      = /usr/bin/gcc
CFLAGS  = -Wall -g -D_REENTRANT -DVERSION=\"$(VERSION)\"
LDFLAGS = -lm -lpthread `gtk-config --cflags` `gtk-config --libs` -lgthread
NAME = gpio

OBJ = main.o gpio.o

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
		$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
		rm -rf $(BIN) $(OBJ) *~

.PHOY: very-clean
very-clean:
		rm -rf $(BIN) $(OBJ) $(NAME) *~

.PHONY: remove
remove:
		rm -rf $(OBJ) *~

