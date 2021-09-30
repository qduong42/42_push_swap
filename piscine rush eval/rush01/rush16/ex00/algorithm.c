/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 09:44:03 by mschreib          #+#    #+#             */
/*   Updated: 2021/08/16 14:38:40 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int		ft_set_cell(int col, int row, int block_type);
extern int		ft_get_cell(int col, int row);

extern int		ft_set_col_flag(int idx, int block_type, int value);
extern int		ft_set_row_flag(int idx, int block_type, int value);

extern int		ft_col_has(int col, int block_type);
extern int		ft_row_has(int row, int block_type);

extern int		ft_get_col_clue(int idx, int up);
extern int		ft_get_row_clue(int idx, int right);

extern int		ft_are_clues_violated(void);

int				ft_find_solution(int col, int row);
int				ft_get_next_pos(int *p_col, int *p_row);
int				ft_get_prev_pos(int *p_col, int *p_row);
int				ft_try_blocktype(int col, int row, int block_type);


// returns FALSE if col, row is outside the board after calling this function
int	ft_get_next_pos(int *p_col, int *p_row)
{
	if (*p_col >= 4)
	{
		*p_col = 1;
		*p_row = *p_row + 1;
	}
	else
	{
		*p_col = *p_col + 1;
	}
	return (1 <= *p_row && *p_row <= 4 && 1 <= *p_col && *p_col <= 4);
}

// returns FALSE if col, row is outside the board after calling this function
int	ft_get_prev_pos(int *p_col, int *p_row)
{
	if (*p_col <= 1)
	{
		*p_col = 4;
		*p_row = *p_row - 1;
	}
	else
	{
		*p_col = *p_col - 1;
	}
	return (1 <= *p_row && *p_row <= 4 && 1 <= *p_col && *p_col <= 4);
}

// returns 0 == no solution found
// returns != 0 == solution found
int	ft_find_solution(int col, int row)
{
	int	f_solution_found;
	int	block_type;

	if (1 <= ft_get_cell(col, row) && ft_get_cell(col, row) <= 4)
	{
		f_solution_found = !ft_are_clues_violated();
	}
	else
	{
		f_solution_found = 0;
		block_type = 1;
		while (block_type <= 4 && !f_solution_found)
		{
			if (!ft_col_has(col, block_type) && !ft_row_has(row, block_type))
			{
				f_solution_found = ft_try_blocktype(col, row, block_type);
			}
			block_type++;
		}
	}
	return (f_solution_found);
}


int	ft_try_blocktype(int col, int row, int block_type)
{
	int	f_solution_found;

	f_solution_found = 0;
	ft_set_cell(col, row, block_type);
	if (ft_are_clues_violated())
	{
		ft_set_cell(col, row, 0);
	}
	else if (ft_get_next_pos(&col, &row))
	{
		f_solution_found = ft_find_solution(col, row);
		if (!f_solution_found)
		{
			ft_set_cell(col, row, 0);
		}
	}
	else
	{
		f_solution_found = 1;
	}
	return (f_solution_found);
}
