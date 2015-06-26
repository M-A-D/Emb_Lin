#TARGET  := hello
#WARN    := -W -Wall -Wstrict-prototypes -Wmissing-prototypes
#INCLUDE := -isystem /lib/modules/`uname -r`/build/include
#ASM     := -isystem /lib/modules/'uname -r'/build/include/generated
#CFLAGS  := -O2 -DMODULE -D__KERNEL__ ${WARN} ${INCLUDE} ${ASM}
#CC      := gcc-4.9

#${TARGET}.o: ${TARGET}.c

#.PHONY: clean

#clean:
#	rm -rf ${TARGET}.o

obj-m += hello.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm -rf *~ *.o

