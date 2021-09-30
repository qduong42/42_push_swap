/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 15:05:48 by jkarosas          #+#    #+#             */
/*   Updated: 2021/08/09 12:30:04 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a);

void	rush(int x, int y)
{
	int	Height;
	int	Length;

	Height = 0;
	while (++Height <= y)
	{
		Length = 1;
		while (Length <= x)
		{
			if (Height == 1 || Height == y)
				if (Length == 1 || Length == x)
					ft_putchar ('o');
			else
				ft_putchar ('-');
			else
				if (Length == 1 || Length == x)
					ft_putchar ('|');
			else
				ft_putchar (' ');
		Length++;
		}
		ft_putchar('\n');
	}
}
