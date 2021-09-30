/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_the_rest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuckluc <skuckluc@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:32:16 by aignacz           #+#    #+#             */
/*   Updated: 2021/02/21 16:13:30 by skuckluc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_check_this_row(int m[4][4], int v[16], int i);
int		ft_check_cols(int m[4][4], int v[16]);
int		ft_fill_row(int m[4][4], int count[5], int i, int v[16]);

void	ft_count_boxes_in_row(int m[4][4], int count[5], int i)
{
	int j;
	int k;

	j = 0;
	while (j < 5)
	{
		count[j] = 0;
		j++;
	}
	j = 0;
	while (j < 4)
	{
		k = m[i][j];
		count[k]++;
		j++;
	}
}

int		ft_fill_next_row(int m[4][4], int v[16], int i)
{
	int count[5];
	int good;

	good = ft_check_this_row(m, v, i);
	if (good)
	{
		i++;
		if (i < 4)
		{
			ft_count_boxes_in_row(m, count, i);
			good = ft_fill_row(m, count, i, v);
		}
		else
		{
			good = ft_check_cols(m, v);
		}
	}
	return (good);
}

int		ft_put_k_in_row(int m[4][4], int count[5], int i, int v[16])
{
	int good;
	int j;
	int	k;

	good = 0;
	k = 1;
	while (k < 5 && !good)
	{
		if (count[k] == 0)
		{
			j = 0;
			while (m[i][j] != 0)
				j++;
			m[i][j] = k;
			count[k] = 1;
			good = ft_fill_row(m, count, i, v);
			if (!good)
			{
				m[i][j] = 0;
				count[k] = 0;
			}
		}
		k++;
	}
	return (good);
}

int		ft_fill_row(int m[4][4], int count[5], int i, int v[16])
{
	int good;

	good = ft_put_k_in_row(m, count, i, v);
	good = ft_fill_next_row(m, v, i);
	return (good);
}

int		ft_fill_the_rest(int m[4][4], int v[16])
{
	int count[5];
	int good;
	int i;

	i = 0;
	ft_count_boxes_in_row(m, count, i);
	good = ft_fill_row(m, count, i, v);
	return (good);
}
