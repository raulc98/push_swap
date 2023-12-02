/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:57:12 by rcabrero          #+#    #+#             */
/*   Updated: 2023/12/02 17:54:19 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void		free_init(int argc, char **values);
static t_list	*get_next_min_value(t_list **stack);
static void		fill_stack_a(t_list **stack, char **values, int argc);

int	init_stack(int argc, char **argv, t_list **stack)
{
	int		i;
	long	tmp_number;
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
		tmp_number = ft_atoi(values[i]);
		if (!ft_isnum(values[i]) || is_min_or_max(tmp_number))
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
	int	tmp_number;

	i = 0;
	if (argc > 2)
		i = 1;
	while (values[i])
	{
		tmp_number = ft_atoi(values[i]);
		ft_lstadd_back(stack, ft_lstnew(tmp_number));
		i++;
	}
}

void	set_index(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = get_next_min_value(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min_value(stack);
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

static t_list	*get_next_min_value(t_list **stack)
{
	t_list	*head;
	t_list	*min_value;
	int		has_min;

	min_value = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1)
				&& (!has_min || head->content < min_value->content))
			{
				min_value = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min_value);
}
