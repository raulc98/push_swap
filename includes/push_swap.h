/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:48:41 by rcabrero          #+#    #+#             */
/*   Updated: 2023/11/27 21:09:23 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
#include <stdio.h>

typedef struct t_list
{
	int				index;
    int             content;
    struct t_list   *next;
}               t_list;

// void				init_stack(t_list **stack_a, char **argv);
void				imprimir_lista(t_list *head, int length);
//check_errors:
int					check_errors(int argc, char **argv);
int					check_equals(t_list **head);
int					is_order(t_list **stack_a);

//METODOS DEL LIBFT CON LISTA
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
// void				ft_lstiter(t_list *lst, void (*f)(void *));
// t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
// 						void (*del)(void *));
//SORT_CONTROLLER
void				sort_controller(t_list **stack_a, t_list **stack_b, int argc);
void				sort_2(t_list **stack_a);
void				sort_3(t_list **stack_a);
void				sort_4(t_list **stack,t_list **stack_b, int length);
void				sort_5(t_list **stack_a,t_list **stack_b, int length);

//SWAPS
void				swap(t_list **stack);
void				sa(t_list **stack_a);
void				sb(t_list **stack_b);
void				ss(t_list **stack_a, t_list **stack_b);
//ROTATE
int			rotate(t_list **stack);
void			ra(t_list **stack_a);
//void			rb(t_list **stack_b);
//ROTATE REVERSE
//void			rotate_reverse(t_list **stack_a);
void			rra(t_list **stack_a);
//void			rrb(t_list **stack_a);
//PUSH
int				push(t_list **stack_ini, t_list **stack_fin);
int				pa(t_list **stack_a, t_list **stack_b);
int				pb(t_list **stack_a, t_list **stack_b);

//utils
t_list			*ft_lstlast_prev(t_list *lst);
// t_list	*ft_lstlast(t_list *lst);
int				get_index_min_number(t_list **stack, int length);
int				get_distance(t_list **stack, int index);
void			radix(t_list **stack_a, t_list **stack_b,int argc);
void			index_stack(t_list **stack);

int				ft_isdigit(int c);
char			**ft_split(char const *s, char	 c);
int				ft_atoi(const char *str);
// void			ft_lstclear(t_list **lst, int (*del)(int*));
size_t			ft_strlen(const char *str);
t_list			*ft_lstnew(int content);

int				get_min(t_list **stack, int val);


#endif
