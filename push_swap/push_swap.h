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

int			check_stack_if_sorted(pst_list **stacka);

void		swap(pst_list **stack, char i);

void		rotate(pst_list **stack, char i);

void		r_rotate(pst_list **stack, char i);

void		rrr(pst_list **stacka, pst_list **stackb);

void		rr(pst_list **stacka, pst_list **stackb);

int			push(pst_list **stacka, pst_list **stackb, char a);

void		sort3(pst_list **stack);

void		sort5(pst_list **stacka, pst_list **stackb);

void		sort4(pst_list **stacka, pst_list **stackb);

void		push_specific(pst_list **stacka, pst_list **stackb, int rank);

#endif
