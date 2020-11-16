TARGET := hello
INCLUDE := -I/lib/modules/`uname -r`/build/include
CFLAGS := -O2 -Wall -DMODULE -D__KERNEL__ -DLINUX
CC := gcc
${TARGET}.o: ${TARGET}.c
	$(CC)	$(CFLAGS)	${INCLUDE}	-c	${TARGET}.c
