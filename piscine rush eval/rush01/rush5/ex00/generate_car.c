/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_car.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 15:56:23 by abraskus          #+#    #+#             */
/*   Updated: 2021/08/14 22:58:03 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	generate_car(char linear_ends[16], char car[8][2])
{
	int	i;
	int	sum;

	i = 0;
	while (i < 8)
	{
		sum = linear_ends[i] + linear_ends[i + 4];
		if (sum >= 3 && sum <= 5)
		{
			car[i][0] = linear_ends[i];
			car[i][1] = linear_ends[i + 4];
		}
		else
		{
			return (104);
		}
		i++;
	}
	return (0);
}
