/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yigsahin <yigsahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:40:45 by yigsahin          #+#    #+#             */
/*   Updated: 2025/03/13 21:36:05 by yigsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_pass(t_node **a, t_node **b)
{
	int	i;
	int	size_new;

	i = 0;
	while (stack_size(*a) > 3 && i < 5)
	{
		if ((*a)->index == 0)
			op_pb(a, b);
		else if ((*a)->index == 1)
			op_pb(a, b);
		else
			op_ra(a);
		i++;
	}
	size_new = stack_size(*a);
	if (a && size_new == 3)
		sort_three(a, 4);
	while (stack_size(*b) > 0)
		op_pa(a, b);
	if ((*a) && (*a)->next && ((*a)->index > (*a)->next->index))
		op_sa(a);
}

static int	get_passes(t_node *a)
{
	int		max;
	t_node	*tmp;
	int		bits;

	max = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

static void	process_pass(t_node **a, t_node **b, int pass, int size)
{
	int	j;
	int	orig;
	int	digit;

	j = 0;
	orig = size;
	while (j < orig)
	{
		digit = (((*a)->index >> pass) & 1);
		if (digit == 0)
			op_pb(a, b);
		else
			op_ra(a);
		j++;
	}
	while (*b)
		op_pa(a, b);
}

void	radix_sort(t_node **a, t_node **b, int size)
{
	int	passes;
	int	i;

	if (size == 2 && (*a)->index > (*a)->next->index)
		op_sa(a);
	else if (size == 3)
		sort_three(a, 2);
	else if (size == 4)
		sort_four(a, b);
	else if (size > 4)
		sort_pass(a, b);
	if (is_sorted(*a))
		return ;
	passes = get_passes(*a);
	i = 0;
	while (i < passes)
	{
		process_pass(a, b, i, size);
		i++;
	}
}
