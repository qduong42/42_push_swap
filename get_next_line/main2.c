#include <stdio.h>

// int main (void)
// {
// 	char *test;
// 	test="abcsde";
// 	test[0] = 'g';
// 	printf("%s", test);
// 	return (0);
// }

int main (void)
{
    int fd;
    fd = open("/Users/qduong/Documents/projects/gnl_test/text3", O_RDONLY);
    char *str;
	str = "";
    while (str)
    {
        str = get_next_line(fd);  
        printf("%s", str);
    }
    close(fd);
    return (0);
}
