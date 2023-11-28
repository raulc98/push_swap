/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:47:02 by rcabrero          #+#    #+#             */
/*   Updated: 2023/11/28 20:43:19 by rcabrero         ###   ########.fr       */
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

static int ft_exit(t_list **stack_a,t_list **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

// void	imprimir_lista(t_list *head, int length)
// {
// 	printf("\n");
// 	t_list	*current;
// 	int		i;
// 	int		valor;
// 	int		index;

// 	current = head;
// 	i = 1;
// 	while (i <= length && current != NULL)
// 	{
// 		valor = current->content;
// 		index = current->index;
// 		printf("%d, ", valor);
// 		if (i < length)
// 		{
// 			current = current->next;
// 		}
// 		else
// 		{
// 			break;
// 		}
// 		i++;
// 	}
// 	printf("\n");
// }

void leaks()
{
	system("leaks  push_swap");
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	
	atexit(leaks);
	if (argc == 1)
		return (0);
	stack_a = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	if(!init_stack(argc, argv, stack_a))
		return (0);
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_b = NULL;
	if (!check_equals(stack_a))
	{
		if(is_order(stack_a))
			return(ft_exit(stack_a,stack_b));
		sort_controller (stack_a, stack_b, argc);
	}
	else
	{
		write(1, "Error\n", 6);
		ft_exit(stack_a,stack_b);
		return (-1);
	}
	return(ft_exit(stack_a,stack_b));
}
