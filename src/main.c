/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:47:02 by rcabrero          #+#    #+#             */
/*   Updated: 2023/11/27 21:56:01 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_list	*get_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->content < min->content))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

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

static void	init_stack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	if (argc == 2)
	{
		i = 0;
		while (args[i])
		{
			free(args[i]);
				i++;
		}
		free(args);	
	}
	index_stack(stack);
}

void	index_stack(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
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
		return 0;
	if (!check_errors(argc, argv))
		return (0);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	init_stack(stack_a, argc, argv);
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
	// imprimir_lista(*stack_a, argc - 1);
	return(ft_exit(stack_a,stack_b));
}
