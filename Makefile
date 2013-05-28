obj-m += pony.o

all:
	make -C /usr/src/linux-`uname -r` SUBDIRS=$(PWD) modules
    
clean:
	make -C /usr/src/linux-`uname -r` SUBDIRS=$(PWD) clean
