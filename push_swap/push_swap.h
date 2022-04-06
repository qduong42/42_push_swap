#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct ps_list
{
	int				value;
	int				rank;
	struct ps_list	*next;
	struct ps_list	*previous;
}					pst_list;

pst_list	*ft_lstnew(int value, int rank);

pst_list	*ft_lstlast(pst_list *lst);

int			ft_lstsize(pst_list *lst);

void		ft_lstadd_back(pst_list **lst, pst_list *new);

void		ft_lstclear(pst_list **lst);

int			check_digit	(char **argv);

int			check_int(char **argv);

int			check_duplicates(char **argv);

int			check_sorted(int argc, char ** argv);

#endif
