/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:52:12 by rcabrero          #+#    #+#             */
/*   Updated: 2023/11/20 18:54:52 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push(t_list **stack_ini, t_list **stack_fin)
{
	t_list	*temp;
	t_list	*head_ini;
	t_list	*head_fin;

	if (ft_lstsize(*stack_fin) == 0)
		return (-1);
	head_ini = *stack_ini;
	head_fin = *stack_fin;
	temp = head_fin;
	head_fin = head_fin->next;
	*stack_fin = head_fin;
	if (!head_ini)
	{
		head_ini = temp;
		head_ini->next = NULL;
		*stack_ini = head_ini;
	}
	else
	{
		temp->next = head_ini;
		*stack_ini = temp;
	}
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	write(1, "pa\n", 3);
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	write(1, "pb\n", 3);
	return (0);
}