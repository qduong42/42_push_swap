/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelmerd <chelmerd@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 18:06:38 by chelmerd          #+#    #+#             */
/*   Updated: 2021/08/15 21:42:09 by chelmerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_validate_str(const char *str);
int		ft_validate_length(const char *str);
int		ft_validate_clues(const int *clues, int size);
int		ft_handle_input(int argc, char **argv, int *clues, int clue_count);
void	ft_str_to_int_arr(const char *str, int *arr, int size);

/*
takes the parameters from the commandline and converts the argument string
into a an array

return values
0 - okay
1 - argument count is not equal 2
2 - str has the wrong size (expected 31 chars)
3 - unexpected character in str
4 - clue value outside of valid range (1..4)
*/
int	ft_handle_input(int argc, char **argv, int *clues, int clue_count)
{
	int		error;
	char	*clue_str;

	if (argc == 2)
	{
		clue_str = argv[1];
		error = ft_validate_str(clue_str);
		if (error == 0)
			ft_str_to_int_arr(clue_str, clues, clue_count);
	}
	else
	{
		error = 1;
	}
	if (error == 0)
	{
		error = ft_validate_clues(clues, clue_count);
	}
	return (error);
}

/*
parameters 
str - pointer to the start of the string
format: 16 single digit numbers seperated by a single space
arr - pointer to the start of an integer array (output)
size - size of the integer array
*/
void	ft_str_to_int_arr(const char *str, int *arr, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		arr[i] = *str - '0';
		str += 2;
		i++;
	}
}

// validate that the string has the correct format
// returns 2 (wrong length) or 3 (unexpexted char) if str has wrong format
int	ft_validate_str(const char *str)
{
	int	error;
	int	i;

	error = ft_validate_length(str);
	i = 0;
	while (str[i] != '\0' && error == 0)
	{
		if (i % 2 == 0)
		{
			if (!('0' <= str[i] && str[i] <= '9'))
				error = 3;
		}
		else
		{
			if (str[i] != ' ')
				error = 3;
		}
		i++;
	}
	return (error);
}

/*
check if the string has the right length
32 = 16x single digit numbers + 15x whitespaces
returns
0 - okay 
2 - wrong length
*/
int	ft_validate_length(const char *str)
{
	int	len;
	int	error;

	error = 0;
	len = 0;
	while (*str != '\0')
	{
		str++;
		len++;
	}
	if (len != 31)
	{
		error = 2;
	}
	return (error);
}

// validates that all clues are between 1 and 4 (inclusive)
// returns 4 (error) otherwise
int	ft_validate_clues(const int *clues, int size)
{
	int	i;
	int	error;

	error = 0;
	i = 0;
	while (i < size && error == 0)
	{
		if (!(1 <= clues[i] && clues[i] <= 4))
		{
			error = 4;
		}
		i++;
	}
	return (error);
}
