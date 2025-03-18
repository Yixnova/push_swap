/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yigsahin <yigsahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:41:05 by yigsahin          #+#    #+#             */
/*   Updated: 2025/03/14 17:39:33 by yigsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write (2, "Error\n", 6);
	exit (1);
}

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	if (!tokens)
		return ;
	while (tokens && tokens[i])
		free(tokens[i++]);
	if (tokens)
		free(tokens);
}

static int	count_tokens(char **tokens)
{
	int	count;

	count = 0;
	while (tokens[count])
		count++;
	return (count);
}

static void	init_stacks(t_node **a, int **arr, char **tokens, int ac)
{
	int	total;

	if (ac == 2)
	{
		*arr = get_arr(tokens, count_tokens(tokens), 2);
		total = count_tokens(tokens);
	}
	else
	{
		*arr = get_arr(tokens, ac - 1, 0);
		total = ac - 1;
	}
	dup_check(*arr, total, ac, tokens);
	*a = build_stack(*arr, total);
	free(*arr);
	if (ac == 2)
		free_tokens(tokens);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int		*arr;
	char	**tokens;
	int		total;

	a = NULL;
	b = NULL;
	arr = NULL;
	tokens = NULL;
	if (ac < 2)
		return (0);
	if (ac == 2)
		tokens = ft_split(av[1], ' ');
	else
		tokens = av + 1;
	init_stacks(&a, &arr, tokens, ac);
	total = stack_size(a);
	if (is_sorted(a))
		free_all(&a, &b);
	sort_and_assign(&a, total);
	radix_sort(&a, &b, total);
	free_all(&a, &b);
}
