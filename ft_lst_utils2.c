/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:05:24 by mely-pan          #+#    #+#             */
/*   Updated: 2024/12/09 19:46:05 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = ft_lst_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	min_on_top(t_stack_node **stack)
{
	t_stack_node	*node;
	int				len;
	int				min_index;

	if (stack == NULL || *stack == NULL)
		return ;
	node = find_min_node(*stack);
	if (node == NULL)
		return ;
	len = ft_lst_len(*stack);
	min_index = node->index;
	while ((*stack)->n != node->n)
	{
		if (min_index <= len / 2)
			ra(stack, 0);
		else
			rra(stack, 0);
	}
}

t_stack_node	*get_cheapest(t_stack_node *node)
{
	long			cost;
	t_stack_node	*cheapest;

	if (!node)
		return (NULL);
	cost = LONG_MAX;
	while (node)
	{
		if (node->cost < cost)
		{
			cost = node->cost;
			cheapest = node;
		}
		node = node->next;
	}
	cheapest->cheapest = true;
	return (cheapest);
}

void	set_rr_rrr(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	if (cheapest->above_median && cheapest->target_node->above_median)
	{
		while (*b != cheapest->target_node && *a != cheapest)
			rr(a, b);
		indexes(a, b);
	}
	else if (!(cheapest->above_median)
		&& !(cheapest->target_node->above_median))
	{
		while (*b != cheapest->target_node && *a != cheapest)
			rrr(a, b);
		indexes(a, b);
	}
}

void	set_top(t_stack_node **stack, t_stack_node *top, int flag)
{
	while (*stack != top)
	{
		if (flag == 0)
		{
			if (top->above_median)
				ra(stack, 0);
			else
				rra(stack, 0);
		}
		else if (flag == 1)
		{
			if (top->above_median)
				rb(stack, 0);
			else
				rrb(stack, 0);
		}
	}
}
