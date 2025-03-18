/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yigsahin <yigsahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:55:13 by yigsahin          #+#    #+#             */
/*   Updated: 2025/03/13 21:35:41 by yigsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **a, int max)
{
	if ((*a)->index == max)
		op_ra(a);
	if ((*a)->next->index == max)
		op_rra(a);
	if ((*a)->index > (*a)->next->index)
		op_sa(a);
}

void	sort_four(t_node **a, t_node **b)
{
	int	size_node;

	size_node = stack_size(*a);
	while (size_node > 3 && *a != NULL)
	{
		if (*a && ((*a)->index == 0))
			op_pb(a, b);
		else if (*a)
			op_ra(a);
		size_node = stack_size(*a);
	}
	if (*a && stack_size(*a) == 3)
		sort_three(a, 3);
	op_pa(a, b);
}
