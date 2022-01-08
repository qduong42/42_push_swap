#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_list
{
	int				rank;
	int				value;
	struct s_list	*current;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

int		check_digit	(char **argv);

int		check_int(char **argv);

int 	check_duplicates(char **argv);

#endif
