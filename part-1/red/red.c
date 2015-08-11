// Using these defines with pointer arithmetics to greatly reduce the kernel.img size
#define GPIO_BASE 0x20200000UL
#define GPIO_SEL_1 0x04
#define GPIO_CLR_0 0x28
#define GPIO_SET_0 0x1C


volatile unsigned int* gpio;
volatile unsigned int i;

//int main(void) __attribute__((naked));
int main(void)
{
	gpio = (unsigned int*) (GPIO_BASE);

	// Select(enable) the GPIO16 pin as an output.
	gpio[GPIO_SEL_1] |= 1 << 18;


    while(1)
    {
    	// Clear (0) the GPIO16 pin
		gpio[GPIO_CLR_0] |= 1 << 16;

		// Sleep
		for (i = 0; i < 5000000; ++i);

    	// Clear (0) the GPIO16 pin
		gpio[GPIO_SET_0] |= 1 << 16;

		// Sleep
		for (i = 0; i < 5000000; ++i);
    }
    return 0;
}


