/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:57:12 by rcabrero          #+#    #+#             */
/*   Updated: 2023/12/02 17:17:52 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void		free_init(int argc, char **values);
static t_list	*get_next_min(t_list **stack);
static void		fill_stack_a(t_list **stack, char **values, int argc);

int	init_stack(int argc, char **argv, t_list **stack)
{
	int		i;
	long	tmp;
	char	**values;

	i = 0;
	if (argc == 2)
		values = ft_split(argv[1], ' ');
	else
	{
		values = argv;
		i = 1;
	}
	while (values[i])
	{
		tmp = ft_atoi(values[i]);
		if (!ft_isnum(values[i]) || is_min_or_max(tmp))
		{
			free(stack);
			return (ft_error(values, argc));
		}
		i++;
	}
	fill_stack_a(stack, values, argc);
	free_init(argc, values);
	return (1);
}

static void	fill_stack_a(t_list **stack, char **values, int argc)
{
	int	i;
	int	tmp;

	i = 0;
	if (argc > 2)
		i = 1;
	while (values[i])
	{
		tmp = ft_atoi(values[i]);
		ft_lstadd_back(stack, ft_lstnew(tmp));
		i++;
	}
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

static void	free_init(int argc, char **values)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		i = 0;
		while (values[i])
		{
			free(values[i]);
			i++;
		}
		free(values);
	}
}

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
			if ((head->index == -1)
				&& (!has_min || head->content < min->content))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

// void	init_stack(t_list **stack, int argc, char **argv)
// {
// 	t_list	*new;
// 	char	**args;
// 	int		i;
// 	i = 0;
// 	if (argc == 2)
// 		args = ft_split(argv[1], ' ');
// 	else
// 	{
// 		i = 1;
// 		args = argv;
// 	}
// 	while (args[i])
// 	{
// 		new = ft_lstnew(ft_atoi(args[i]));
// 		ft_lstadd_back(stack, new);
// 		i++;
// 	}
// 	if (argc == 2)
// 	{
// 		i = 0;
// 		while (args[i])
// 		{
// 			free(args[i]);
// 				i++;
// 		}
// 		free(args);
// 	}
// 	index_stack(stack);
// }