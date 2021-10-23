/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschreib <mschreib@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 18:29:59 by nluong            #+#    #+#             */
/*   Updated: 2021/08/15 20:49:51 by mschreib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_set_cell(int col, int row, int block_type);
int		ft_get_cell(int col, int row);
int		ft_col_has(int col, int block_type);
int		ft_row_has(int row, int block_type);
void	ft_init_board(void);

//block-type has value from 1 to 4
//block-type == 0 means no block there

// ft_col_has(1, 1) == 1 means there is a 1-block in column 1
// ft_col_has(1, 2) == 0 means there is no 2-block in column 1 
int	ft_col_has(int col, int block_type)
{
	int	row;
	int	is_block_present;
	int	curr_block;

	is_block_present = 0;
	row = 1;
	while (row < 5)
	{
		curr_block = ft_get_cell(col, row);
		if (curr_block == block_type)
		{
			is_block_present++;
		}
		row++;
	}
	return (is_block_present);
}

// ft_row_has(1, 1) == 1 means there is a 1-block in row 1
// ft_row_has(1, 2) == 0 means there is no 2-block in row 1 
int	ft_row_has(int row, int block_type)
{
	int	col;
	int	is_block_present;
	int	curr_block;

	is_block_present = 0;
	col = 1;
	while (col < 5)
	{
		curr_block = ft_get_cell(col, row);
		if (curr_block == block_type)
		{
			is_block_present++;
		}
		col++;
	}
	return (is_block_present);
}

// ft_set_cell(1, 2, 4) set a 4-block at col=1, row=2 
int	ft_set_cell(int col, int row, int block_type)
{
	static int	board[5][5];
	int			old_value;

	old_value = board[col][row];
	board[col][row] = block_type;
	return (old_value);
}

// ft_get_cell(1, 2) get block type at col=1, row=2 
int	ft_get_cell(int col, int row)
{
	int	old_value;

	old_value = ft_set_cell(col, row, 9);
	ft_set_cell(col, row, old_value);
	return (old_value);
}

// ft_init_board create an empty board (all values are 0)
void	ft_init_board(void)
{
	int	row;
	int	col;

	col = 0;
	while (col < 5)
	{
		row = 0;
		while (row < 5)
		{
			ft_set_cell(0, 0, 0);
			row++;
		}
		col++;
	}
}
