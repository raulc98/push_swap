/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:47:02 by rcabrero          #+#    #+#             */
/*   Updated: 2023/12/02 17:20:32 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

static int	ft_exit(t_list **stack_a, t_list **stack_b)
{
	free_stack (stack_a);
	free_stack (stack_b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc == 1)
		return (0);
	stack_a = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	if (!init_stack(argc, argv, stack_a))
		return (0);
	index_stack (stack_a);
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_b = NULL;
	if (!check_equals(stack_a))
	{
		if (is_order(stack_a))
			return (ft_exit(stack_a, stack_b));
		sort_controller(stack_a, stack_b);
	}
	else
	{
		write (1, "Error\n", 6);
		ft_exit(stack_a, stack_b);
		return (-1);
	}
	return (ft_exit (stack_a, stack_b));
}
