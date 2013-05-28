#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/random.h>
#include <asm/uaccess.h>

#include "pony.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Extraterrestrial");
MODULE_DESCRIPTION("NEED MOAR PONIES!");
MODULE_SUPPORTED_DEVICE("pony");

static int major;
static int is_device_open = 0;
static char * phrase_ptr;

static struct file_operations file_ops =
{
  .read = device_read,
  .write = device_write,
  .open = device_open,
  .release = device_release
};

static int __init pony_init(void) {
	printk(KERN_ALERT "Pony module has been loaded, have fun.\n");
	major = register_chrdev(0, "pony", &file_ops);

  if(major < 0 ) {
    printk("Registering char device failed with %d\n", major);
    return major;
  }

  printk("Now you should create a dev file: 'mknod /dev/pony c %d 0'.\n", major);
	return 0;
}

static void __exit pony_exit( void ) {
	  unregister_chrdev(major, "pony");
    printk(KERN_ALERT "Pony module was unloaded, good luck!\n");
}

module_init(pony_init);
module_exit(pony_exit);

static int device_open(struct inode * inode, struct file * file) {
  int random = 0;
  
	get_random_bytes(&random, 1);
	random = random % 8 + 1;

	switch(random) {
	case 1:
		phrase_ptr = a;
		break;
  case 2:
		phrase_ptr = b;
		break;
	case 3:
		phrase_ptr = c;
		break;
	case 4:
		phrase_ptr = d;
		break;
	case 5:
		phrase_ptr = e;
		break;
	case 6:
		phrase_ptr = f;
		break;
	case 7:
		phrase_ptr = g;
		break;
	case 8:
		phrase_ptr = h;
		break;
	}


  if (is_device_open) {
    return -EBUSY;
  }

  is_device_open++;

  return 0;
}

static int device_release(struct inode * inode, struct file * file) {
  is_device_open--;
  return 0;
}

static ssize_t device_write(struct file *filp, const char *buff, size_t len, loff_t * off)
{
  printk("You must read from me, not write...\n");
  return -EINVAL;
}

static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t * offset)
{
  int byte_read = 0;

  if (*phrase_ptr == 0)
    return 0;

  while (length && *phrase_ptr) {
    put_user(*(phrase_ptr++), buffer++);
    length--;
    byte_read++;
  }

  return byte_read;
}
