/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:27:45 by rcabrero          #+#    #+#             */
/*   Updated: 2023/11/11 22:04:29 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

void ra(t_list **stack_a)
{
	rotate(stack_a);
	write(1, "ra ", 3);
}

void rb(t_list **stack_b)
{
	rotate(stack_b);
	write(1, "rb ", 3);
}

void rr(t_list **stack_a,t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr ", 3);
}
