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

t_list	*ft_lstlast_prev(t_list *lst)
{
	if (lst)
	{
		while (lst->next->next)
			lst = lst->next;
	}
	return (lst);
}

// t_list	*ft_lstlast_prev(t_list *lst)
// {
// 	if (lst)
// 		while (lst->next->next)
// 			lst = lst->next;		
// 	return (lst);
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
