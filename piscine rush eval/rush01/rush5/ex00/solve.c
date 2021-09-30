/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 23:17:30 by coder             #+#    #+#             */
/*   Updated: 2021/08/15 21:20:44 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	check_empty_solutions(int pos_sul[8][24]);
static void	linear_solutions(char ends[2], int solution[24]);
int			combination(int index, char comb[4]);
int			combine(int pos_sul[8][24], char solution[4][4], char car[8][2]);
int			count_see(char comb[4], char *count, int inverse);

int	solve(char car[8][2], char solution[4][4])
{
	int	pos_sul[8][24];
	int	res;
	int	itr;

	itr = 0;
	while (itr < 8)
	{
		linear_solutions(car[itr], pos_sul[itr]);
		itr++;
	}
	res = check_empty_solutions(pos_sul);
	if (res)
		return (res);
	res = combine(pos_sul, solution, car);
	if (res)
		return (res);
	return (0);
}

static int	check_empty_solutions(int pos_sul[8][24])
{
	int	itr;

	itr = 0;
	while (itr < 8)
	{
		if (pos_sul[itr][0] == -1)
		{
			return (301);
		}
		itr++;
	}
	return (0);
}

static void	linear_solutions(char ends[2], int solution[24])
{
	char	comb[4];
	char	see[2];
	int		itr[2];

	itr[0] = 0;
	itr[1] = 0;
	while (itr[0] < 24)
	{
		combination(itr[0], comb);
		count_see(comb, &see[0], 0);
		count_see(comb, &see[1], 1);
		if (ends[0] == see[0] && ends[1] == see[1])
		{
			solution[itr[1]] = itr[0];
			itr[1]++;
		}
		itr[0]++;
	}
	while (itr[1] < 24)
	{
		solution[itr[1]] = -1;
		itr[1]++;
	}
}
