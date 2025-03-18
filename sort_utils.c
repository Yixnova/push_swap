/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yigsahin <yigsahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:44:18 by yigsahin          #+#    #+#             */
/*   Updated: 2025/03/12 14:02:54 by yigsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(int *arr, int n)
{
	int	tmp;
	int	i;
	int	sorted;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < n - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				sorted = 0;
			}
			i++;
		}
	}
}

static void	assign_indices(t_node *a, int *sorted, int n)
{
	int	pos;

	while (a)
	{
		pos = 0;
		while (pos < n)
		{
			if (a->value == sorted[pos])
			{
				a->index = pos;
				break ;
			}
			pos++;
		}
		a = a->next;
	}
}

void	sort_and_assign(t_node **a, int total)
{
	int	*sorted;

	sorted = copy_arr(*a, total);
	sort_array(sorted, total);
	assign_indices(*a, sorted, total);
	free(sorted);
}
