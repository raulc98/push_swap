/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:38:38 by rcabrero          #+#    #+#             */
/*   Updated: 2023/11/18 12:39:19 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	count_words(const char *str, char c)
{
	int i;
	//TODO: CAMBIAR NOMBRE DE TIGGER
	int trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

//word_dup recibe str, donde empieza y donde acaba
static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	//igualamos i a 0;
	i = 0;
	//allocamos el espacio de memoria para word
	word = malloc((finish - start + 1) * sizeof(char));
	//mientras que start sea menor que finish, word en la posicion i es igual a str en la posicion start ++.
	while (start < finish)
		word[i++] = str[start++];
	//ponemos el siguiente carácter a null y retornamos la palabra.
	word[i] = '\0';
	//printf("que guarda el split: %s" , word);
	return (word);
}

char		**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;
	//Si no hay s, o el malloc devuelve null, retorna 0 y para
	if (!s || !(split = malloc((count_words(s, c) + 1) * sizeof(char *))))
		return (0);
	//Si funciona, i = 0 y j = 0;
	i = 0;
	j = 0;
	//Index = -1; Funciona como un booleano.
	index = -1;
	//mientras que i sea menor o igual a la longitud de s:
	while (i <= ft_strlen(s))
	{
		//si s en la posicion i no es c y index es menor que cero: le damos a index el valor de i en ese momento y sumamos 1.
		//PERO si s en la posicion i es igual a c oo i es igual a ft_strlen (ultimo caracter dentro del string)
		// yyy index es mayor o igual a cero quiere decir que el caracter anterior s[i] no era igual a c.
		//Split en la posicion j++ sea el resultado de word_Dup.
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			//guardamos en la posicion split[j] la palabra
			split[j] = word_dup(s, index, i);
			j ++;
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}