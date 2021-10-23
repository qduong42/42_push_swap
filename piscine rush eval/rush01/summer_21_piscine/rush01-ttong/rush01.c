#include <unistd.h>

/* Objective : Controlling 16 input parameters as a string/
/ so that inputs will only give result when input parameters are in bound */

char *    check_string(char* str)
{
    int    count;
    int    result;

    count = 0;
    result = 1;
	malloc = (sizeof(char) * 31)
    while (*str)
    {
        if (!(((*str <= '4' && *str >= 1 + '0' )(count % 2 == 1 && *str == ' ' && count < 30))&& count < 31))
        {
            result = 0;
        }
        count++;
        str++;
    }
    if (count != 31  result == 0)
    {
        write(1, "Error\n", 6);
    }
}

#include <unistd.h>
void    check_string(char *str);

int    main(void)
{
	int x;
    check_string("4 3 2 1 1 2 4 2 4 3 2 1 1 2 2 2");
	return (0);
}