/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluong <nluong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 23:16:32 by chelmerd          #+#    #+#             */
/*   Updated: 2021/08/15 23:28:27 by nluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(const char *str, int f_newline);
void	ft_putinttab(const int *inttab, int size);
void	ft_putnbr(int num);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *str, int f_newline)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	if (f_newline)
	{
		ft_putchar('\n');
	}
}

// prints the integers from the array in a line seperated by comma
void	ft_putinttab(const int *inttab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putchar(inttab[i] + '0');
		i++;
		if (i < size)
			ft_putchar(',');
	}
	ft_putchar('\n');
}

void	ft_putnbr(int num)
{
	if (num == -2147483648)
	{
		ft_putnbr(num / 10);
		ft_putchar('8');
	}
	else if (num < 0)
	{
		ft_putchar('-');
		ft_putnbr(-num);
	}
	else
	{
		if (num > 9)
		{
			ft_putnbr(num / 10);
		}
		ft_putchar('0' + num % 10);
	}
}
