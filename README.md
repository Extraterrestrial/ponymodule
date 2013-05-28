ponymodule
==========

This module generates random phrases from the special character device (/dev/pony).
Type 'make' to compile.

How to use:
Load the module (as root):
insmod pony.ko

Then let's check a major number. Type 'dmesg | tail -2'.

...and create a device as dmesg said.

Done. You can generate a phrase by command 'cat /dev/pony'.

