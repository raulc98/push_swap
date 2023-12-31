/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:31:29 by rcabrero          #+#    #+#             */
/*   Updated: 2023/12/01 22:03:05 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_reverse(t_list **stack_a)
{
	t_list	*first_position;
	t_list	*last_position;
	t_list	*new_last_position;

	first_position = *stack_a;
	new_last_position = ft_lstlast_prev(*stack_a);
	last_position = ft_lstlast(*stack_a);
	last_position->next = first_position;
	*stack_a = last_position;
	new_last_position->next = NULL;
}

void	rra(t_list **stack_a)
{
	rotate_reverse(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	rotate_reverse(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rotate_reverse(stack_a);
	rotate_reverse(stack_b);
	write(1, "rrr\n", 4);
}
