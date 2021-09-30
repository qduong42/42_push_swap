/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clues.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelmerd <chelmerd@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 16:38:34 by chelmerd          #+#    #+#             */
/*   Updated: 2021/08/15 19:28:33 by chelmerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_set_col_clue(int idx, int up, int value);
int		ft_get_col_clue(int idx, int up);
int		ft_set_row_clue(int idx, int right, int value);
int		ft_get_row_clue(int idx, int right);
void	ft_init_clues(int *clues);

// first clue for col/row is at index 1
// last clue for col/row is at index 4

/*
first index indicates which coloumn,
second wheter it is the uppper (1) or bottom (0) one
*/
int	ft_set_col_clue(int idx, int up, int value)
{
	static int	col_clue[5][2];
	int			old_value;

	old_value = col_clue[idx][up];
	col_clue[idx][up] = value;
	return (old_value);
}

int	ft_get_col_clue(int idx, int up)
{
	int	value;

	value = ft_set_col_clue(idx, up, 0);
	ft_set_col_clue(idx, up, value);
	return (value);
}

// right is set to 1 when working with the clues on the right hand side
// 0 for the left hand side
int	ft_set_row_clue(int idx, int right, int value)
{
	static int	row_clue[5][2];
	int			old_value;

	old_value = row_clue[idx][right];
	row_clue[idx][right] = value;
	return (old_value);
}

int	ft_get_row_clue(int idx, int right)
{
	int	value;

	value = ft_set_row_clue(idx, right, 0);
	ft_set_row_clue(idx, right, value);
	return (value);
}

/*
takes an array of exactly 16 integers
and distributes them to the corresponding variable
ex: the first four ints are for the up colums 
(colXup - where X is the index from 1 to 4)
*/
void	ft_init_clues(int *clues)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (i < 4)
			ft_set_col_clue(i + 1, 1, clues[i]);
		else
			ft_set_col_clue(i - 4 + 1, 0, clues[i]);
		i++;
	}
	while (i < 16)
	{
		if (i < 12)
			ft_set_row_clue(i - 8 + 1, 0, clues[i]);
		else
			ft_set_row_clue(i - 12 + 1, 1, clues[i]);
		i++;
	}
}
