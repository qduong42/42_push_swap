#include "push_swap.h"
#include <unistd.h>

int	check_digit	(int argc, char**argv)
{

}

int	put_error()
{
	write(STDERR_FILENO, "Error\n", 6);
	return (-1);
}

int main(int argc, char **argv)
{
if(!check_digit)
	return (put_error());
}