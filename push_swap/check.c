/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:36:57 by qduong            #+#    #+#             */
/*   Updated: 2022/01/07 14:37:24 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//loops through each input and check if each digit in each number input is numeric

#include "push_swap.h"

int	check_digit	(char **argv)
{
	int i;
	int y;

	i = 1;
	while (argv[i])
	{
		y = 0;
		while (argv[i][y])
		{
			if (y == 0 && argv[i][y] == '-')
			{
				y++;
				continue;
			}
			else if (!ft_isdigit(argv[i][y]))
				return (0);
			y++;
		}	
		i++;
	}
	return (1);
}

//check if input is in int range and if its empty input
int	check_int(char **argv)
{
	long long i;
	i = 0;
	int x;
	x = 1;
	while (argv[x])
	{
	i = ft_atoll(argv[x]);
	if (i < -2147483648 || i > 2147483647)
		return (0);
	if (!ft_strlen(argv[x]))
		return (0);
	x++;
	}
	return(1);
}

int check_duplicates(char **argv)
{
	int i;
	int y;

	i = 1;
	while (argv[i + 1])
	{
		y = 1;
		while (argv[i + y])
		{
			if(!ft_strncmp(argv[i], argv[i + y], 11))
				return (0);
			y++;
		}
		i++;
	}
	return (1);
}
