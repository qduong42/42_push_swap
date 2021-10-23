/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborgard <dborgard@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 11:10:44 by dborgard          #+#    #+#             */
/*   Updated: 2021/08/15 10:39:05 by dborgard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_initialize_grid(int grid[4][4][5]);
void	ft_initialize_rowb(int grid[4][4][5], int *row);
void	ft_initialize_rowa(int grid[4][4][5], int *row);
void	ft_initialize_colub(int grid[4][4][5], int *column);
void	ft_initialize_colua(int grid[4][4][5], int *column);
void	ft_check_row(int grid[4][4][5]);
void	ft_check_colu(int grid[4][4][5]);
int		ft_fill_possibilities(int grid[4][4][5]);

void	ft_print_grid(int grid[4][4][5])
{
	int i;
	int j;
	char c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = grid[i][j][0] + 48;
			write(1, &c, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

int	ft_get_parameters(char *argv[], int	*column, int *row)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (argv[1][i])
	{
		if (argv[1][i] != ' ' && !(argv[1][i] >= '1' && argv[1][i] <= '4'))
			return (0);
		if (argv[1][i] != ' ' && j < 8)
		{
			column[j] = argv[1][i] - 48;
			j++;
		}
		else if (argv[1][i] != 32 && k < 8)
		{
			row[k] = argv[1][i] - '0';
			k++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int grid[4][4][5];
	int	column[8];
	int row[8];
	int flag;

	if (argc == 2)
	{
		flag = ft_get_parameters(argv, column, row);
		if (!flag)
		{
			write(1, "Error\n", 6);
			return (0);
		}
	}
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
	ft_initialize_grid(grid);
	ft_initialize_rowa(grid, row);
	ft_initialize_rowb(grid, row);
	ft_initialize_colua(grid, column);
	ft_initialize_colub(grid, column);
	flag = 1;
	while (flag)
	{
		ft_check_row(grid);
		ft_check_colu(grid);
		flag = ft_fill_possibilities(grid);
	}
	ft_print_grid(grid);
	return (0);
}
