/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:05:29 by mely-pan          #+#    #+#             */
/*   Updated: 2024/12/09 19:47:00 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

// !Have a look in this function, if (a && new),
// !for the first concatenation 'a' might be NULL.
int	append(t_stack_node **a, int n)
{
	t_stack_node	*new;

	new = ft_lstnew2(n);
	if (!new)
		return (free_lst(a), 0);
	new->next = *a;
	if (*a)
		(*a)->prev = new;
	*a = new;
	return (1);
}

void	set_targetb(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target;
	long			target_n;

	while (b)
	{
		target_n = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->n > b->n && current_a->n < target_n)
			{
				target_n = current_a->n;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (target_n == LONG_MAX)
			b->target_node = find_min_node(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

void	set_target(t_stack_node *a, t_stack_node *b)
{
	long			target_n;
	t_stack_node	*target;
	t_stack_node	*current_b;

	while (a)
	{
		target_n = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->n < a->n && current_b->n > target_n)
			{
				target_n = current_b->n;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (target_n == LONG_MIN)
			a->target_node = find_max_node(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

void	cost_calc(t_stack_node *node, int len_a, int len_b)
{
	node->cost = node->index;
	if (!node->above_median)
		node->cost = len_a - node->index;
	if (node->target_node != NULL)
	{
		if (node->target_node->above_median)
			node->cost += node->target_node->index;
		else
			node->cost += len_b - node->target_node->index;
	}
}

void	set_cost(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lst_len(a);
	len_b = ft_lst_len(b);
	while (a != NULL)
	{
		cost_calc(a, len_a, len_b);
		a = a->next;
	}
	while (b != NULL)
	{
		cost_calc(b, len_b, len_a);
		b = b->next;
	}
}
