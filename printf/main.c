#include <stdio.h>
# include "printf.h"
#include <stdarg.h>

int	main(void)
{
	// int a = 5;
	// char a[] = "Hello World";
	//double b = 5;
	 int c = 0;
	 int *p;
	 p = &c;
	// int *p;
	// p = &b;
	// //ft_printf("%s", a);
	// printf("b-X-big:%X\nb-x-small:%x\n", b);
	// printf("Hello, %s, %d, %X\n %p\n %d\n %x\n %X\n", a, b, c, p, p, p, p);
	c = printf("Pointer Value:%p\nPointer-int%i\n",p, &c);
	printf("Return Value:%d\n",c);

	// print_ints(1, 5);
}
