/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschreib <mschreib@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 09:43:53 by mschreib          #+#    #+#             */
/*   Updated: 2021/08/15 20:10:20 by mschreib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int	ft_get_cell(int col, int row);
extern int	ft_col_has(int col, int block_type);
extern int	ft_row_has(int row, int block_type);

int			get_valid_block_count_for_col(int col);
int			ft_is_col_up_clue_violated(int col, int single_clue_up);
int			is_placeable(int col, int row, int block_type);

int	get_valid_block_count_for_col(int col)
{
	int	row;
	int	valid_block_count;

	row = 1;
	valid_block_count = 0;
	while (row <= 4)
	{
		if (1 <= ft_get_cell(col, row) && ft_get_cell(col, row) <= 4)
		{
			valid_block_count++;
		}
		row++;
	}
	return (valid_block_count);
}

int	get_valid_block_count_for_row(int row)
{
	int	col;
	int	valid_block_count;

	col = 1;
	valid_block_count = 0;
	while (col <= 4)
	{
		if (1 <= ft_get_cell(col, row) && ft_get_cell(col, row) <= 4)
		{
			valid_block_count++;
		}
		col++;
	}
	return (valid_block_count);
}

int	is_placeable(int col, int row, int block_type)
{
	return (
		!ft_row_has(row, block_type) && !ft_col_has(col, block_type)
	);
}
