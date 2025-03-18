/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yigsahin <yigsahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:48:59 by yigsahin          #+#    #+#             */
/*   Updated: 2025/03/14 09:33:05 by yigsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./lib/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

long	ft_atol(const char *str, int *arr, int ac, char **tokens);

t_node	*stack_new(int value);
t_node	*build_stack(int *arr, int total);

int		stack_size(t_node *stack);
int		*get_arr(char **tokens, int total, int ac);
int		*copy_arr(t_node *a, int total);
int		is_sorted(t_node *a);
int		is_valid_number(const char *str);

void	error_tokens(char **tokens);
void	free_tokens(char **tokens);
void	free_all(t_node **a, t_node **b);
void	stack_add_back(t_node **stack, t_node *new);
void	free_stack(t_node *stack);
void	sort_and_assign(t_node **a, int total);
void	dup_check(int *arr, int total, int ac, char **tokens);
void	op_pb(t_node **a, t_node **b);
void	op_pa(t_node **a, t_node **b);
void	op_ra(t_node **a);
void	op_sa(t_node **a);
void	op_rra(t_node **a);
void	radix_sort(t_node **a, t_node **b, int size);
void	sort_three(t_node **a, int max);
void	sort_four(t_node **a, t_node **b);
void	error(void);

#endif
