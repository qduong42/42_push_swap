/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluong <nluong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 15:37:50 by chelmerd          #+#    #+#             */
/*   Updated: 2021/08/15 23:31:18 by nluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int	ft_handle_input(int argc, char **argv, int *clues, int clue_count);

extern void	ft_init_clues(int *clues);

extern void	ft_init_board(void);
extern int	ft_get_cell(int col, int row);

extern int	ft_find_solution(int col, int row);

extern void	ft_putchar(char c);
extern void	ft_putstr(const char *str, int f_newline);
extern void	ft_putnbr(int n);

int			main(int argc, char **argv);
void		ft_print_solution(void);

int	main(int argc, char **argv)
{
	int	clues[16];
	int	error;
	int	solution_found;

	solution_found = 0;
	error = ft_handle_input(argc, argv, clues, 16);
	if (!error)
	{
		ft_init_clues(clues);
		ft_init_board();
		solution_found = ft_find_solution(1, 1);
	}
	if (error || !solution_found)
		ft_putstr("Error\n", 0);
	else
		ft_print_solution();
	return (solution_found == 0);
}

void	ft_print_solution(void)
{
	int	col;
	int	row;

	row = 1;
	while (row <= 4)
	{
		col = 1;
		ft_putnbr(ft_get_cell(col, row));
		col++;
		while (col <= 4)
		{
			ft_putchar(' ');
			ft_putnbr(ft_get_cell(col, row));
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
