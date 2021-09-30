/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuckluc <skuckluc@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:25:40 by skuckluc          #+#    #+#             */
/*   Updated: 2021/02/21 16:35:38 by skuckluc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_fill_the_rest(int m[4][4], int v[16]);

void	ft_fill_m(int m[4][4])
{
	int i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	ft_print_m(int m[4][4])
{
	int i;
	int j;
	int c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = m[i][j] + 48;
			write(1, &c, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

int		ft_input_length_check(char *str)
{
	int c;

	c = 0;
	while (str[c] != '\0')
		++c;
	return (c);
}

int		ft_check(char *p, int views[16])
{
	int		good;
	int		i;
	char	*t;

	good = 1;
	i = ft_input_length_check(p);
	if (i != 31)
		good = 0;
	i = 0;
	while (i < 31 && good)
	{
		t = &p[i];
		if (i % 2 == 0 && *t > '0' && *t < '5')
			views[i / 2] = *t - 48;
		else if (i % 2 == 1 && *t == ' ')
			good = 1;
		else
			good = 0;
		i++;
	}
	if (good == 0)
		write(1, "Error\n", 6);
	return (good);
}

int		main(int argc, char *argv[])
{
	char	*p;
	int		views[16];
	int		m[4][4];
	int		good;

	if (argc == 2)
	{
		p = argv[1];
		good = ft_check(p, views);
		ft_fill_m(m);
		if (good)
		{
			good = ft_fill_the_rest(m, views);
			if (good)
				ft_print_m(m);
			else
				write(1, "Error\n", 6);
		}
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
