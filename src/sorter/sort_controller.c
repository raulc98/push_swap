/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:47:37 by rcabrero          #+#    #+#             */
/*   Updated: 2023/11/25 13:32:06 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void sort_controller(t_list **stack_a, t_list **stack_b, int argc)
{
	int length;

	length = argc - 1;
	if (length == 2)
		sort_2(stack_a);
	else if (length == 3)
		sort_3(stack_a);
	else if (length == 4)
	{
		sort_4(stack_a, stack_b, length);
	}
	else if (length == 5)
	{
		sort_5(stack_a, stack_b, length);
	}
	else
	{
		radix(stack_a, stack_b, length);
	}
}

void sort_2(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
}

void sort_3(t_list **stack_a)
{
	int p1;
	int p2;
	int p3;

	p1 = (*stack_a)->content;
	p2 = (*stack_a)->next->content;
	p3 = (*stack_a)->next->next->content;
	if (p1 > p2 && p1 < p3 && p2 < p3)
		sa(stack_a);
	else if (p1 < p2 && p1 > p3 && p2 > p3)
		rra(stack_a);
	else if (p1 > p2 && p1 > p3 && p2 < p3)
		ra(stack_a);
	else if (p1 > p2 && p1 > p3 && p2 > p3)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (p1 < p2 && p1 < p3 && p2 > p3)
	{
		rra(stack_a);
		sa(stack_a);
	}
}

void sort_4(t_list **stack_a, t_list **stack_b, int length)
{
	int min_index;
	int	distance;

	min_index = get_index_min_number(stack_a, length);
	distance = get_distance(stack_a,min_index);
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_list **stack_a, t_list **stack_b, int length)
{
	int	distance;

	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (is_order(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b,length-1);
	pa(stack_a, stack_b);
}