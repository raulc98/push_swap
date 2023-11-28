/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:55:45 by rcabrero          #+#    #+#             */
/*   Updated: 2023/11/28 20:12:36 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_error(char **value, int argc)
{
	int i;
    
	write(1, "Error\n", 6);
	if (argc == 2)
	{
		i = 0;
		while (value[i])
		{
			free(value[i]);
			i++;
		}
		free(value);	
	}
	return(0);
}

int	ft_isnum(char *num)
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
