/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:57:01 by rcabrero          #+#    #+#             */
/*   Updated: 2023/11/18 16:01:56 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

//BONUS
t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->content = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}
/*
int	main(void)
{
	char	str[] = "lorem ipsum dolor sit";
	t_list	*elem;

	elem = ft_lstnew((void *)str);
	//Parsear y tal........
	printf("\nname : %s",(char *)elem->content);
	return (0);
}
*/