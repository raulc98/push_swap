/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:06:40 by rcabrero          #+#    #+#             */
/*   Updated: 2023/10/12 11:39:44 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


/*
	lst: el principio de la lista.
	Devuelve: Último nodo de la lista.
	Devuelve el último nodo de la lista.
*/
// t_list	*ft_lstlast(t_list *lst)
// {
// 	if (lst)
// 		while (lst->next)
// 			lst = lst->next;
			
// 	return (lst);
// }

t_list	*ft_lstlast_prev(t_list *lst)
{
	if (lst)
		while (lst->next->next)
			lst = lst->next;
			
	return (lst);
}

//lst: el principio de la lista.
//Valor devuelto: La longitud de la lista.
//Cuenta el número de nodos de una lista.
// int	ft_lstsize(t_list *lst)
// {
// 	int		i;
// 	t_list	*temp;

// 	i = 0;
// 	temp = lst;
// 	while (temp != NULL)
// 	{
// 		i++;
// 		temp = temp->next;
// 	}
// 	return (i);
// }

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(int*))
// {
// 	t_list	*new;
// 	t_list	*begin;

// 	if (lst == NULL || f == NULL)
// 		return (NULL);
// 	begin = 0;
// 	while (lst)
// 	{
// 		new = ft_lstnew(lst->content);
// 		if (!new)
// 		{
// 			ft_lstclear(begin, del);
// 			return (NULL);
// 		}
// 		ft_lstadd_back(&begin, new);
// 		lst = lst->next;
// 	}
// 	return (begin);
// }

void	ft_lstiter(t_list *lst, void (*f)(int*))
{
	t_list	*next;

	if (lst != NULL)
	{
		next = lst;
		while (1)
		{
			(*f)(&next->content);
			next = next->next;
			if (next == NULL)
				return ;
		}
	}
}