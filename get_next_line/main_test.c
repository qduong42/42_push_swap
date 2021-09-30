#include "get_next_line.h"
#include <stdio.h>

int main (void)
{
    int fd;
    fd = open("/Users/qduong/Documents/projects/gnl_test/longggggtxt", O_RDONLY);
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
