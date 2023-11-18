/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 00:32:08 by rcabrero          #+#    #+#             */
/*   Updated: 2023/11/11 21:36:14 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_distance(t_list **stack, int index)
{
	t_list	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (head->next)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

int	get_index_min_number(t_list **stack, int length)
{
	t_list	*head;
	int		index;
	int		i;

	head = stack[0];
	index = head->index;
	i = 0;
	while (i < length - 1)
	{
		if (head->content > head->next->content)
		{
			index = head->next->index;
			printf("EL NUEVO VALOR MAS BAJO ES: %d || EL VALOR DEL INDEX ES: %d\n", head->next->content,index);
		}
		head = head->next;
		i ++;
	}
	printf("El index mas bajo es: %d\n",index);
	return (index);
}

int	get_index_max_number(t_list **stack, int length)
{
	t_list	*head;
	int		index;
	int		i;

	head = stack[0];
	index = head->index;
	i = 0;
	while (i < length - 1)
	{
		printf("EL VALOR DEL CONTENT: %d || EL VALOR DEL SIGUIENTE CONTENT: %d\n", head->content, head->next->content);
		if (head->content > head->next->content)
			index = head->next->index;
		head = head->next;
		i ++;
	}
	printf("El index mas alto es: %d\n",index);
	return (index);
}
