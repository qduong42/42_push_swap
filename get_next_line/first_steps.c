#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

int main (void)
{
    int fd;
    fd = open("/Users/qduong/Documents/gnl/text1", O_RDONLY);
    static char buf[BUFFER_SIZE + 1];
    int bytes_read1;
    int bytes_read2;
   
    bytes_read1 = read(fd, buf, BUFFER_SIZE);
    printf("First read: %d\n", bytes_read );
    buf[bytes_read1] = '\0';
    int i;
    i = 0;
     char *returnline =  malloc(bytes_read1+1);;
    while (buf[i] != '\0')
    {
        returnline[i] = buf[i];
        i++;
    }
    printf("First buffer: %s\n", buf);
    printf("return line: %s\n", returnline);
    bytes_read2 = read(fd, buf, BUFFER_SIZE);
    printf("Second read: %d\n", bytes_read2);
    printf("Second buffer %s\n", buf);
    realloc(line, )
    close(fd);
    return (0);
}