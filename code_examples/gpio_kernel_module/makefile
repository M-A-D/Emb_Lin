# @file makefile
# @brief makefile for a gpio kernel object on the BBB
# @author m-a-d
# @date 24.06.2015

obj-m += main.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm -rf *~ *.o

