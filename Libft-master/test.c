#include <stdio.h>
int fkt2(char * ptr);

int main()
{
	char a = 'a';
	printf("Char a = %c\n", a);
	fkt2(&a);
	printf("Char a = %c", a);
	return (0);
	
}

int	fkt2(char *ptr)
{
*ptr = 'b';
//*ptr= first value in string a
return (0);
}
