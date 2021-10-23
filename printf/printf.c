/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:50:34 by qduong            #+#    #+#             */
/*   Updated: 2021/10/23 14:05:23 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>
#include <string.h>
// #include <string.h>
// #include <stdio.h>

int	write_character(char c)
{
	write(1, &c, 1);
	return (1);
}

int write_string(char *str)
{
	int i;
	i = 0;
	if (str == NULL)
		{
			write(1, "(null)", 6);
			return(6);
		}
	while(*str)
	{
		write(1, str, 1);
		str++;
		i++;
	}
	return(i);
}

int write_pointer(void *ptr)
{
	unsigned char *p;
	p = (unsigned char *)ptr;
	unsigned long i;
	i = strlen(p);
	while (*p)
	{
		write(1, p, i);	
	}
	return(0);
}

int conversion(va_list args, char format)
	{
		if (format == 'c')
			return(write_character(va_arg(args, int)));
		if (format == 's')
			return(write_string(va_arg(args, char *)));
		if (format == 'p')
			return(write_pointer(va_arg(args, void *)));
		// if (format == 'd')
		// 	return(write_double((va_arg(args, double)));
		// if (format == 'i')
		// 	return(write_int(va_arg(args, int));
		// if (format == 'x')
		// 	return(write_low_hexa(va_arg(args, unsigned int));
		// if (format == 'X')
		// 	return(write_upper_hexa(va_arg(args, unsigned int)));
		// if (format == 'u')
		// 	return(write_unsigned_dec(va_arg(args, unsigned int)));
		if (format == '%')
		{
		write(1, "\%", 1);
		return (1);
		}
		return(0);
		
	}

int	ft_printf(const char *format, ...)
{
	va_list args;
	va_start (args, format);
	int i;
	int is_variable;
	int bytes_written;
	
	i = 0;
	is_variable = 0;
	bytes_written = 0;
	while (format[i]!= '\0')
	{
		if (is_variable)
			{
				bytes_written = conversion(args, format[i]);
				is_variable = 0;
				i++;
			}
		else if(format[i] != '%')
		{
			write(1, &format[i], 1);
			bytes_written++;
			i++;
		}
		else
		{
			is_variable = 1;
			i++;
		}
	}
	va_end(args);
	return (bytes_written);
}

#include <stdio.h>
# include "printf.h"
#include <stdarg.h>

int	main(void)
{
	int b = 5;
	//char a[] = "Hello World";
	int *p;
	p = &b;
	int c = 0;
	//char c = 'a';
	// //ft_printf("%s", a);
	// printf("b-X-big:%X\nb-x-small:%x\n", b);
	// printf("Hello, %s, %d, %X\n %p\n %d\n %x\n %X\n", a, b, c, p, p, p, p);
	// c=ft_printf("abcd%s\n%c", a, c);
	c=ft_printf("abcd%p\n",p);
	
	//printf("%d", c);
	// print_ints(1, 5);
}
