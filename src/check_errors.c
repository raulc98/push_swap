/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:55:45 by rcabrero          #+#    #+#             */
/*   Updated: 2023/11/20 19:16:05 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: ARREGLAR PROBLEMAS NORMINETTE...
#include "../includes/push_swap.h"

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_equals(t_list **head)
{
	t_list* current = head[0];

    while (current != NULL) {
        t_list* temp = current->next;
        while (temp != NULL) {
            if (current->content == temp->content) {
                return (1);
            }
            temp = temp->next;
        }
        current = current->next;
    }

    return 0;
}

int	is_order(t_list **stack_a)
{
	t_list	*current = *stack_a;

    while (current != NULL && current->next != NULL) {
        if (current->content > current->next->content) {
            return (0);  // No están ordenados
        }
        current = current->next;
    }

    return (1);
}

int	check_errors(int argc, char **argv)
{
	int		i;
	long	num_aux;
	char	**values;

	i = 0;
	if (argc <= 2)
	{
		ft_error();
		return (0);
	}
	if (argc == 2)
		values = ft_split(argv[i],' ');
	else
	{
		i = 1;
		values = argv;
	}
	while (values[i])
	{
		num_aux = ft_atoi(values[i]);
		if (!ft_isnum(values[i]))
		{
			ft_error();
			return (0);
		}
		if (num_aux < -2147483648 || num_aux > 2147483647)
		{
			ft_error();
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_error()
{
    write(1, "Error\n", 6);
}
