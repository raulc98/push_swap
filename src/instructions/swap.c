/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:46:59 by rcabrero          #+#    #+#             */
/*   Updated: 2023/11/11 15:36:45 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void swap(t_list **stack_a)
{
	int position;
	t_list *current;
	
	current = *stack_a;
	position = 1;
    while (current != NULL && position > 0) {
        current = current->next;
        position--;
    }
	if (position == 0 && current != NULL)
	{
		(*stack_a)->next = current->next;
		current->next = (*stack_a);
		*stack_a = current;
	}
}

void sa(t_list **stack_a)
{
	swap(stack_a);
	write(1, "sa ", 3);
}

void sb(t_list **stack_b)
{
	swap(stack_b);
	write(1, "sb ", 3);
}

void ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "sb ", 3);
}

