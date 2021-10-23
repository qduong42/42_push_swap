/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   violations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschreib <mschreib@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 17:43:56 by nluong            #+#    #+#             */
/*   Updated: 2021/08/15 20:09:14 by mschreib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int	ft_get_cell(int col, int row);

extern int	get_valid_block_count_for_col(int col);
extern int	get_valid_block_count_for_row(int row);

extern int	ft_get_row_clue(int idx, int right);
extern int	ft_get_col_clue(int idx, int up);

int			ft_is_col_up_clue_violated(int col, int single_clue_up);
int			ft_is_col_down_clue_violated(int col, int single_clue_down);
int			ft_is_row_left_clue_violated(int row, int single_clue_left);
int			ft_is_row_right_clue_violated(int row, int single_clue_right);
int			ft_are_clues_violated(void);

// check the entire board if any clues are violated
// return 0 if there are no rules violated
int	ft_are_clues_violated(void)
{
	int	idx;
	int	violated;

	idx = 1;
	violated = 0;
	while (idx <= 4)
	{
		violated = violated
			|| ft_is_col_up_clue_violated(idx, ft_get_col_clue(idx, 1));
		violated = violated
			|| ft_is_col_down_clue_violated(idx, ft_get_col_clue(idx, 0));
		violated = violated
			|| ft_is_row_left_clue_violated(idx, ft_get_row_clue(idx, 0));
		violated = violated
			|| ft_is_row_right_clue_violated(idx, ft_get_row_clue(idx, 1));
		idx++;
	}
	return (violated);
}

// return 0 if no rule violation
int	ft_is_col_up_clue_violated(int col, int single_clue_up)
{
	int	row;
	int	min_height;
	int	visible_count;

	visible_count = 0;
	if (1 <= ft_get_cell(col, 1) && ft_get_cell(col, 1) <= 4)
	{
		min_height = ft_get_cell(col, 1);
		visible_count++;
	}
	row = 2;
	while (row <= 4)
	{
		if (1 <= ft_get_cell(col, row) && ft_get_cell(col, row) <= 4)
		{
			if (min_height < ft_get_cell(col, row))
			{
				min_height = ft_get_cell(col, row);
				visible_count++;
			}		
		}
		row++;
	}
	return ((get_valid_block_count_for_col(col) == 4)
		&& (visible_count != single_clue_up));
}

int	ft_is_col_down_clue_violated(int col, int single_clue_down)
{
	int	row;
	int	min_height;
	int	visible_count;

	visible_count = 0;
	if (1 <= ft_get_cell(col, 4) && ft_get_cell(col, 4) <= 4)
	{
		min_height = ft_get_cell(col, 4);
		visible_count++;
	}
	row = 3;
	while (row >= 1)
	{
		if (1 <= ft_get_cell(col, row) && ft_get_cell(col, row) <= 4)
		{
			if (min_height < ft_get_cell(col, row))
			{
				min_height = ft_get_cell(col, row);
				visible_count++;
			}		
		}
		row--;
	}
	return ((get_valid_block_count_for_col(col) == 4)
		&& (visible_count != single_clue_down));
}

int	ft_is_row_left_clue_violated(int row, int single_clue_left)
{
	int	col;
	int	min_height;
	int	visible_count;

	visible_count = 0;
	if (1 <= ft_get_cell(1, row) && ft_get_cell(1, row) <= 4)
	{
		min_height = ft_get_cell(1, row);
		visible_count++;
	}
	col = 2;
	while (col <= 4)
	{
		if (1 <= ft_get_cell(col, row) && ft_get_cell(col, row) <= 4)
		{
			if (min_height < ft_get_cell(col, row))
			{
				min_height = ft_get_cell(col, row);
				visible_count++;
			}		
		}
		col++;
	}
	return ((get_valid_block_count_for_row(row) == 4)
		&& (visible_count != single_clue_left));
}

int	ft_is_row_right_clue_violated(int row, int single_clue_right)
{
	int	col;
	int	min_height;
	int	visible_count;

	visible_count = 0;
	if (1 <= ft_get_cell(4, row) && ft_get_cell(4, row) <= 4)
	{
		min_height = ft_get_cell(4, row);
		visible_count++;
	}
	col = 3;
	while (col >= 1)
	{
		if (1 <= ft_get_cell(col, row) && ft_get_cell(col, row) <= 4)
		{
			if (min_height < ft_get_cell(col, row))
			{
				min_height = ft_get_cell(col, row);
				visible_count++;
			}		
		}
		col--;
	}
	return ((get_valid_block_count_for_row(row) == 4)
		&& (visible_count != single_clue_right));
}
