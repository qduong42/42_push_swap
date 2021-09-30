/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 10:22:48 by nhaulsen          #+#    #+#             */
/*   Updated: 2021/08/09 12:12:43 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	println(int width, char beginning, char end, char middle)
{
	int	counter;

	counter = 0;
	while (counter < width)
	{
		if (counter == 0)
		{
			ft_putchar(beginning);
		}
		else if (counter == width - 1 && counter > 0)
		{
			ft_putchar(end);
		}
		else
		{
			ft_putchar(middle);
		}
		counter++;
	}
	ft_putchar('\n');
}

void	rush(int width, int height)
{
	int	heightCounter;

	heightCounter = 0;
	while (heightCounter < height)
	{
		if (heightCounter == 0)
		{
			println(width, '/', '\\', '*');
		}
		else if (heightCounter == height - 1 && heightCounter > 0)
		{
			println(width, '\\', '/', '*');
		}
		else
		{
			println(width, '*', '*', ' ');
		}
		heightCounter++;
	}
}
