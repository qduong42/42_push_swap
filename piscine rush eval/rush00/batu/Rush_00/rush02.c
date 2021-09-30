/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 17:40:35 by bkeskint          #+#    #+#             */
/*   Updated: 2021/04/20 09:56:55 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_a(int colum_counter, int c);
void	ft_b(int colum_counter, int c);
void	ft_c(int colum_counter, int c);
void	ft_putchar(char w);

void	rush02(int c, int r)
{
	int row_counter;
	int colum_counter;

	if (c <= 0 || r <= 0)
		write(1, "The value is wrong please make higher than 0 !", 46);
	else
	{
		row_counter = 0;
		colum_counter = 0;
		while (row_counter < r)
		{
			if (row_counter == 0)
				ft_a(colum_counter, c);
			else if (row_counter != 0 && row_counter != r - 1)
				ft_b(colum_counter, c);
			else if (row_counter == r - 1)
				ft_c(colum_counter, c);
			write(1, "\n", 1);
			row_counter++;
		}
	}
}

void	ft_a(int colum_counter, int c)
{
	while (colum_counter < c)
	{
		if (colum_counter == 0 || colum_counter == c - 1)
			ft_putchar('A');
		else
			ft_putchar('B');
		colum_counter++;
	}
}

void	ft_b(int colum_counter, int c)
{
	while (colum_counter < c)
	{
		if (colum_counter == 0 || colum_counter == c - 1)
			ft_putchar('B');
		else
			ft_putchar(' ');
		colum_counter++;
	}
}

void	ft_c(int colum_counter, int c)
{
	while (colum_counter < c)
	{
		if (colum_counter == 0 || colum_counter == c - 1)
			ft_putchar('C');
		else
			ft_putchar('B');
		colum_counter++;
	}
}
