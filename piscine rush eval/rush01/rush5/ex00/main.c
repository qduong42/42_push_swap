/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 23:16:01 by coder             #+#    #+#             */
/*   Updated: 2021/08/15 21:44:37 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	read_inputs(int argc, char *str, char inputs[16]);
int	generate_car(char linear_ends[16], char car[8][2]);
int	solve(char car[8][2], char solution[4][4]);
int	view_result(char solution[4][4]);
int	handel_error(int error_code);

int	main(int argc, char **argv)
{
	int		error_code;
	char	inputs[16];
	char	box[8][2];
	char	solution[4][4];

	error_code = read_inputs(argc, argv[1], inputs);
	if (error_code)
		return (handel_error(error_code));
	error_code = generate_car(inputs, box);
	if (error_code)
		return (handel_error(error_code));
	error_code = solve(box, solution);
	if (error_code)
		return (handel_error(error_code));
	error_code = view_result(solution);
	if (error_code)
		return (handel_error(error_code));
	return (error_code);
}
