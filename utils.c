/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yigsahin <yigsahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:15:39 by yigsahin          #+#    #+#             */
/*   Updated: 2025/03/14 09:34:19 by yigsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	non_int_error(int *arr, int ac, char **tokens)
{
	free(arr);
	if (ac == 2)
		free_tokens(tokens);
	error();
}

int	is_sorted(t_node *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

long	ft_atol(const char *str, int *arr, int ac, char **tokens)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		if (num * sign > 2147483647 || num * sign < -2147483648)
			non_int_error(arr, ac, tokens);
		i++;
	}
	return (num * sign);
}

void	free_all(t_node **a, t_node **b)
{
	free_stack(*a);
	free_stack(*b);
	exit(0);
}

void	error_tokens(char **tokens)
{
	free_tokens(tokens);
	write (2, "Error\n", 6);
	exit (1);
}
