#include <stdlib.h>
#include <stdio.h>

int main()
{
	int i;
	i = 0;
	int array[500];
	while (i != 500)
	{
		array[i] = rand();
		i++;
	}
	i = 0;
	while (i != 500)
	{
	printf("%d ", array[i]);
	i++;
	}
	return (0);
}
