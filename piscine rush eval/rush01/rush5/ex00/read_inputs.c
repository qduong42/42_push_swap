/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 18:18:48 by coder             #+#    #+#             */
/*   Updated: 2021/08/15 21:54:30 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	extract_inputs(char *str, char inputs[16]);
static int	is_valid(char c);
static int	strlen(char *str);

int	read_inputs(int argc, char *str, char inputs[16])
{
	if (argc != 2)
	{
		return (101);
	}
	if (strlen(str) != 31)
	{
		return (105);
	}
	return (extract_inputs(str, inputs));
}

static int	strlen(char *str)
{
	int	itr;

	itr = 0;
	while (str[itr])
	{
		itr++;
	}
	return (itr);
}

static int	extract_inputs(char *str, char inputs[16])
{
	int	itr;
	int	input_itr;

	itr = 0;
	input_itr = 0;
	while (str[itr])
	{
		if (!is_valid(str[itr]))
		{
			return (102);
		}
		if ('1' <= str[itr] && str[itr] <= '4')
		{
			inputs[input_itr] = str[itr] - '0';
			input_itr++;
		}
		itr++;
	}
	if (input_itr != 16)
	{
		return (103);
	}
	return (0);
}

static int	is_valid(char c)
{
	return (('1' <= c && c <= '4') || c == ' ');
}
