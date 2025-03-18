/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yigsahin <yigsahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:42:07 by yigsahin          #+#    #+#             */
/*   Updated: 2025/03/13 21:24:59 by yigsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_arr(char **tokens, int total, int ac)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * total);
	if (!arr)
	{
		error();
	}
	i = 0;
	while (i < total)
	{
		if (!ft_isdigit(tokens[i]))
		{
			free(arr);
			if (ac == 2)
				free_tokens(tokens);
			error();
		}
		arr[i] = ft_atol(tokens[i], arr, ac, tokens);
		i++;
	}
	return (arr);
}

void	dup_check(int *arr, int total, int ac, char **tokens)
{
	int	i;
	int	j;

	i = 0;
	while (i < total)
	{
		j = i + 1;
		while (j < total)
		{
			if (arr[i] == arr[j])
			{
				free(arr);
				if (ac == 2)
					free_tokens(tokens);
				error();
			}
			j++;
		}
		i++;
	}
}

t_node	*build_stack(int *arr, int total)
{
	t_node	*a;
	int		i;

	a = NULL;
	i = 0;
	while (i < total)
	{
		stack_add_back(&a, stack_new(arr[i]));
		i++;
	}
	return (a);
}

int	*copy_arr(t_node *a, int total)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * total);
	i = 0;
	if (!arr)
		error();
	while (i < total)
	{
		arr[i] = a->value;
		a = a->next;
		i++;
	}
	return (arr);
}
