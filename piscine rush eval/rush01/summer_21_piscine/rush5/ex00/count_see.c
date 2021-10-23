/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_see.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:31:11 by coder             #+#    #+#             */
/*   Updated: 2021/08/14 17:48:45 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	count_see_end(char comb[4], char *count);
static int	count_see_start(char comb[4], char *count);

int	count_see(char comb[4], char *count, int inverse)
{
	if (inverse)
	{
		return (count_see_end(comb, count));
	}
	return (count_see_start(comb, count));
}

static int	count_see_end(char comb[4], char *count)
{
	char	revc[4];

	revc[0] = comb[3];
	revc[1] = comb[2];
	revc[2] = comb[1];
	revc[3] = comb[0];
	return (count_see_start(revc, count));
}

static int	count_see_start(char comb[4], char *count)
{
	int	history;
	int	itr;

	history = 0;
	itr = 0;
	*count = 0;
	while (itr < 4)
	{
		if (history == comb[itr])
		{
			return (201);
		}
		else if (history < comb[itr])
		{
			history = comb[itr];
			*count += 1;
		}
		itr++;
	}
	return (0);
}
