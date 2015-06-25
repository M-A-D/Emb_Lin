/**
 * @file hello.c
 * @brief main file for a simple kernel module example
 * @author m-a-d
 * @date 22.06.2015
 **/

# include <linux/init.h>
# include <linux/module.h>
# include <linux/kernel.h>

/**
 * function that is executed during the launch of the kernel module
 **/
static int __init hello_init(void) {
        printk(KERN_ALERT "Hello, world\n");
        return 0;
}

/**
 * function that is called during the shutdown of the kernel module
 **/
static void __init hello_exit(void) {
        printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);

/**
 * To Remove the licence warning you can specify it like this
 * MODULE_LICENSE("<NAME_OF_LICENCE>")
 **/
MODULE_LICENSE("GPL");

/**
 * You can also specify a driver Author and add a Description like this
 * MODULE_AUTHOR("<NAME <e-mail-adress>>")
 * MODULE_DESCRIPTION("<YOUR_DESCRITION>")
 **/
MODULE_AUTHOR("Matthias Pfitzmayer <mail@something.org>");
MODULE_DESCRIPTION("Just a simple basic kernel module that basically does nothing");

/**
 * With the MODULE_SUPPORTED_DEVICE(<DEVICE_NAME>) you can specify a device the module is
 * used for. Right now it is not used it only adds a line more to the kernel module documentation
 **/
MODULE_SUPPORTED_DEVICE("testdevice");

