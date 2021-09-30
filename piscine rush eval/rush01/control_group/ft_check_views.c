/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_views.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuckluc <skuckluc@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:56:47 by aignacz           #+#    #+#             */
/*   Updated: 2021/02/21 15:46:06 by skuckluc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_get_col(int m[4][4], int k, int a[4]);
void	ft_get_row(int m[4][4], int k, int a[4]);

int		ft_check_this_view(int v, int a[4])
{
	int	i;
	int	seen;
	int	tallest;
	int	good;

	i = 1;
	seen = 1;
	tallest = a[0];
	while (i < 4)
	{
		if (a[i] > tallest)
		{
			tallest = a[i];
			seen++;
		}
		i++;
	}
	if (seen == v)
		good = 1;
	else
		good = 0;
	return (good);
}

int		ft_check_box_count_in_cols(int a[4])
{
	int	count[5];
	int	j;
	int	k;
	int	good;

	good = 1;
	j = 0;
	while (j < 5)
	{
		count[j] = 0;
		j++;
	}
	j = 0;
	while (j < 4 && good)
	{
		k = a[j];
		count[k]++;
		if (count[k] > 1 || k == 0)
			good = 0;
		j++;
	}
	return (good);
}

int		ft_check_this_row(int m[4][4], int v[16], int i)
{
	int	k;
	int	good;
	int	a[4];

	good = 0;
	k = 8 + i;
	ft_get_row(m, k, a);
	good = ft_check_box_count_in_cols(a);
	if (good)
		good = ft_check_this_view(v[k], a);
	if (good)
	{
		k = 12 + i;
		ft_get_row(m, k, a);
		good = ft_check_box_count_in_cols(a);
		if (good)
			good = ft_check_this_view(v[k], a);
	}
	return (good);
}

int		ft_check_cols(int m[4][4], int v[16])
{
	int	k;
	int	good;
	int	a[4];

	good = 1;
	k = 0;
	while (k < 8 && good)
	{
		ft_get_col(m, k, a);
		good = ft_check_box_count_in_cols(a);
		if (good)
			good = ft_check_this_view(v[k], a);
		k++;
	}
	return (good);
}
