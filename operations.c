/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yigsahin <yigsahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:44:35 by yigsahin          #+#    #+#             */
/*   Updated: 2025/03/13 22:56:27 by yigsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pb(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (!*a)
		error();
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "pb\n", 3);
}

void	op_pa(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (!*b)
		error();
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "pa\n", 3);
}

void	op_ra(t_node **a)
{
	t_node	*tmp;
	t_node	*last;

	if (!*a || !(*a)->next)
		error();
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = tmp;
	write(1, "ra\n", 3);
}

void	op_sa(t_node **a)
{
	t_node	*tmp;

	if (!*a || !(*a)->next)
		error();
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "sa\n", 3);
}

void	op_rra(t_node **a)
{
	t_node	*tmp;
	t_node	*prev;

	if (!*a || !(*a)->next)
		error();
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	prev = tmp;
	tmp = tmp->next;
	prev->next = NULL;
	tmp->next = *a;
	*a = tmp;
	write(1, "rra\n", 4);
}
