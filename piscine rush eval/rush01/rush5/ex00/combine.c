/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 00:16:09 by coder             #+#    #+#             */
/*   Updated: 2021/08/15 22:36:30 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	next_col_indexes(int pos_sul[8][24], int col_i[4]);
static int	validate_comb(char car[8][2], char solution[4][4]);
static int	fill_columns(int pos_sul[8][24], char solution[4][4], int ind_s[4]);
int			combination(int index, char comb[4]);
int			count_see(char comb[4], char *count, int inverse);

int	combine(int pos_sul[8][24], char solution[4][4], char car[8][2])
{
	int	col_i[4];
	int	res;

	col_i[0] = 0;
	col_i[1] = 0;
	col_i[2] = 0;
	col_i[3] = 0;
	res = fill_columns(pos_sul, solution, col_i);
	if (res)
		return (res);
	if (validate_comb(car, solution))
		return (0);
	while (next_col_indexes(pos_sul, col_i))
	{
		res = fill_columns(pos_sul, solution, col_i);
		if (res)
			return (res);
		if (validate_comb(car, solution))
			return (0);
	}
	return (304);
}

static int	next_col_indexes(int pos_sul[8][24], int col_i[4])
{
	col_i[3]++;
	if (pos_sul[3][col_i[3]] != -1)
		return (1);
	col_i[3] = 0;
	col_i[2]++;
	if (pos_sul[2][col_i[2]] != -1)
		return (1);
	col_i[2] = 0;
	col_i[1]++;
	if (pos_sul[1][col_i[1]] != -1)
		return (1);
	col_i[1] = 0;
	col_i[0]++;
	if (pos_sul[0][col_i[0]] != -1)
		return (1);
	return (0);
}

static int	fill_columns(int pos_sul[8][24], char solution[4][4], int ind_s[4])
{
	int		itr[2];
	char	comb[4];
	int		comb_index;
	int		res;

	itr[0] = 0;
	while (itr[0] < 4)
	{
		comb_index = pos_sul[itr[0]][ind_s[itr[0]]];
		res = combination(comb_index, comb);
		if (res)
			return (res);
		itr[1] = 0;
		while (itr[1] < 4)
		{
			solution[itr[1]][itr[0]] = comb[itr[1]];
			itr[1]++;
		}
		itr[0]++;
	}
	return (0);
}

static int	validate_comb(char car[8][2], char solution[4][4])
{
	int		row_i;
	int		counter;
	char	comb[4];
	char	see[2];

	row_i = 0;
	counter = 0;
	while (row_i < 4)
	{
		comb[0] = solution[row_i][0];
		comb[1] = solution[row_i][1];
		comb[2] = solution[row_i][2];
		comb[3] = solution[row_i][3];
		count_see(comb, &see[0], 1);
		count_see(comb, &see[1], 0);
		if (car[row_i + 4][0] == see[0] && car[row_i + 4][1] == see[1])
		{
			counter++;
		}
		row_i++;
	}
	if (counter == 4)
		return (1);
	return (0);
}
