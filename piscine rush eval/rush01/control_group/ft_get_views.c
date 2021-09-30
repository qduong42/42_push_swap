/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_views.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuckluc <skuckluc@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 01:50:15 by aignacz           #+#    #+#             */
/*   Updated: 2021/02/21 15:25:22 by skuckluc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_get_col(int m[4][4], int k, int a[4])
{
	int j;
	int i;

	j = k % 4;
	if (k < 4)
	{
		i = 0;
		while (i < 4)
		{
			a[i] = m[i][j];
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < 4)
		{
			a[i] = m[3 - i][j];
			i++;
		}
	}
}

void	ft_get_row(int m[4][4], int k, int a[4])
{
	int j;
	int i;

	i = k % 4;
	if (k < 12)
	{
		j = 0;
		while (j < 4)
		{
			a[j] = m[i][j];
			j++;
		}
	}
	else
	{
		j = 0;
		while (j < 4)
		{
			a[j] = m[i][3 - j];
			j++;
		}
	}
}
