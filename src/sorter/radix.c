/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:24:52 by rcabrero          #+#    #+#             */
/*   Updated: 2023/12/02 18:06:27 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max_value_index;
	int		max_bits;

	head = *stack;
	max_value_index = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max_value_index)
			max_value_index = head->index;
		head = head->next;
	}
	while ((max_value_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;
	t_list	*head_a;

	i = 0;
	size = ft_lstsize(*stack_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
