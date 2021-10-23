/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sodoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborgard <dborgard@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 09:25:03 by dborgard          #+#    #+#             */
/*   Updated: 2021/08/15 10:49:45 by dborgard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_clear_array(int size, int *array)
{
	int i;

	i = 0;
	while (i < size)
	{
		array[i] = i + 1;
		i++;
	}
}

void	ft_check_row(int grid[4][4][5])
{
	int i;
	int j;
	int k;
	int	temp[4];

	i = 0;
	while (i < 4)
	{
		j = 0;
		ft_clear_array(4, temp);
		while (j < 4)
		{	
			if (grid[i][j][0] != 0)
				temp[grid[i][j][0] - 1] = 0;
			j++;
		}
		j = 0;
		while (j < 4)
		{
			if (grid[i][j][0] == 0)
			{	
				k = 0;
				while (k < 4)
				{	
					grid[i][j][k + 1] = temp[k];
					k++;
				}
			}
			j++;
		}
		i++;
	}
}

void	ft_check_colu(int grid[4][4][5])
{
	int i;
	int j;
	int k;
	int	temp[4];

	j = 0;
	while (j < 4)
	{	
		i = 0;
		ft_clear_array(4, temp);
		while (i < 4)
		{	
			if (grid[i][j][0])
				temp[grid[i][j][0] - 1] = 0;
			i++;
		}
		i = 0;
		while (i < 4)
		{
			if (!grid[i][j][0])
			{	
				k = 0;
				while (k < 4)
				{	
					if (grid[i][j][k + 1] != temp[k])
						grid[i][j][k + 1] = 0;
					k++;
				}
			}
			i++;
		}
		j++;
	}
}

int		ft_fill_possibilities(int grid[4][4][5])
{
	int i;
	int j;
	int k;
	int check;
	int	temp;
	int flag;

	i = 0;
	flag = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			check = 0;
			while (k < 4)
			{
				if (!grid[i][j][0] && grid[i][j][k + 1])
				{
					temp = grid[i][j][k + 1];
					check++;
				}
				k++;
			}
			if (check == 1)
			{
				grid[i][j][0] = temp;
				flag = 1;
			}
			j++;
		}
		i++;
	}
	return (flag);
}
