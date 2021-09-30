/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 16:43:29 by coder             #+#    #+#             */
/*   Updated: 2021/08/15 22:04:29 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_valid(char comb[4]);
static int	is_the_one(int index, char comb[4], int *itr);

int	combination(int index, char comb[4])
{
	int	itr;

	itr = 0;
	comb[0] = 0;
	while (++comb[0] <= 4)
	{
		comb[1] = 0;
		while (++comb[1] <= 4)
		{
			comb[2] = 0;
			while (++comb[2] <= 4)
			{
				comb[3] = 0;
				while (++comb[3] <= 4)
				{
					if (is_the_one(index, comb, &itr))
						return (0);
				}
			}
		}
	}
	return (202);
}

static int	is_the_one(int index, char comb[4], int *itr)
{
	if (is_valid(comb))
	{
		if (*itr == index)
		{
			return (1);
		}
		*itr += 1;
	}
	return (0);
}

static int	is_valid(char comb[4])
{
	int	itr[2];

	itr[0] = 0;
	while (itr[0] < 4)
	{
		itr[1] = itr[0] + 1;
		while (itr[1] < 4)
		{
			if (comb[itr[0]] == comb[itr[1]])
			{
				return (0);
			}
			itr[1]++;
		}
		itr[0]++;
	}
	return (1);
}
