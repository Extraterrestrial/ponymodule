#define PHRASE_COUNT 8

static int device_open(struct inode *, struct file *);
static int device_release(struct inode *, struct file *);
static ssize_t device_read(struct file *, char *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char *, size_t, loff_t *);

/* some text */
static char * a = "Yay!\n";
static char * b = "Your Linux is now 20% cooler!\n";
static char * c = "NOOOOOOOOO!!!\n";
static char * d = "Friendship is Magic!\n";
static char * e = "What is friendship all about?\n";
static char * f = "Haters gonna hate!\n";
static char * g = "Rainbow Dash is so awesome!\n";
static char * h = "Everything is under control!\n";

