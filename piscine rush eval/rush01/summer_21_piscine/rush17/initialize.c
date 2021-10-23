/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborgard <dborgard@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 09:23:11 by dborgard          #+#    #+#             */
/*   Updated: 2021/08/15 10:29:26 by dborgard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_initialize_grid(int grid[4][4][5])
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 5)
			{
				grid[i][j][k] = 0;
				k++;
			}	
			j++;
		}
		i++;
	}
}

void	ft_initialize_rowa(int grid[4][4][5], int *row)
{	
	int i;

	i = 0;
	while (i < 4)
	{
		if (row[i] == 4 && row[i + 4] == 1)
		{
			grid[i][0 + 0][0] = 1;
			grid[i][0 + 1][0] = 2;
			grid[i][0 + 2][0] = 3;
			grid[i][0 + 3][0] = 4;
		}
		else if(row[i] == 1 && row[i + 4] == 4)
		{
			grid[i][0 - 0][0] = 4;
			grid[i][0 + 1][0] = 3;
			grid[i][0 + 2][0] = 2;
			grid[i][0 + 3][0] = 1;
		}
		else if (row[i] == 1)
		{
			grid[i][0 + 0][0] = 4;
			if (row[i + 4] == 2)
				grid[i][3 - 0][0] = 3;
		}
		else if (row[i] == 2 && row[i + 4] == 3)
			grid[i][0 + 1][0] = 4;
		i++;
	}
}

void	ft_initialize_rowb(int grid[4][4][5], int *row)
{
	int i;
	
	i = 0;
	while (i < 4)
	{
		if (row[i + 4] == 4 && row[i - 4] == 1)
		{
			grid[i][3 - 0][0] = 1;
			grid[i][3 - 1][0] = 2;
			grid[i][3 - 2][0] = 3;
			grid[i][3 - 3][0] = 4;
		}
		else if (row[i + 4] == 1 && row[i - 4] == 4)
		{
			grid[i][3 - 0][0] = 4;
			grid[i][3 - 1][0] = 3;
			grid[i][3 - 2][0] = 2;
			grid[i][3 - 3][0] = 1;
		}
		else if (row[i + 4] == 1)
		{
			grid[i][3 - 0][0] = 4;
			if (row[i] == 2)
				grid[i][0 - 0][0] = 3;
		}
		else if (row[i + 4] == 2 && row[i - 4] == 3)
			grid[i][2][0] = 4;
		i++;
	}
}

void	ft_initialize_colua(int grid[4][4][5], int *column)
{	
	int i;

	i = 0;
	while (i < 4)
	{
		if (column[i] == 4 && column[i + 4] == 1)
		{
			grid[0 + 0][i][0] = 1;
			grid[0 + 1][i][0] = 2;
			grid[0 + 2][i][0] = 3;
			grid[0 + 3][i][0] = 4;
		}
		else if(column[i] == 1 && column[i + 4] == 4)
		{
			grid[0 - 0][i][0] = 4;
			grid[0 + 1][i][0] = 3;
			grid[0 + 2][i][0] = 2;
			grid[0 + 3][i][0] = 1;
		}
		else if (column[i] == 1)
		{
			grid[0 + 0][i][0] = 4;
			if (column[i + 4] == 2)
				grid[3 - 0][i][0] = 3;
		}
		else if (column[i] == 2 && column[i + 4] == 3)
			grid[1][i][0] = 4;
		i++;
	}
}

void	ft_initialize_colub(int grid[4][4][5], int *column)
{
	int i;
	
	i = 0;
	while (i < 4)
	{
		if (column[i + 4] == 4 && column[i - 4] == 1)
		{
			grid[3 - 0][i][0] = 1;
			grid[3 - 1][i][0] = 2;
			grid[3 - 2][i][0] = 3;
			grid[3 - 3][i][0] = 4;
		}
		else if (column[i + 4] == 1 && column[i - 4] == 4)
		{
			grid[3 - 0][i][0] = 4;
			grid[3 - 1][i][0] = 3;
			grid[3 - 2][i][0] = 2;
			grid[3 - 3][i][0] = 1;
		}
		else if (column[i + 4] == 1)
		{
			grid[3 - 0][i][0] = 4;
			if (column[i] == 2)
				grid[0 - 0][i][0] = 3;
		}
		else if (column[i + 4] == 2 && column[i - 4] == 3)
			grid[2][i][0] = 4;
		i++;
	}
}
