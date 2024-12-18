/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:04:54 by mely-pan          #+#    #+#             */
/*   Updated: 2024/12/09 19:46:16 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

int	ft_lst_len(t_stack_node *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

t_stack_node	*ft_lstnew2(int n)
{
	t_stack_node	*new;

	new = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new)
		return (NULL);
	new->n = n;
	new->index = 0;
	new->cost = 0;
	new->cheapest = false;
	new->above_median = false;
	new->next = NULL;
	new->prev = NULL;
	new->target_node = NULL;
	return (new);
}

t_stack_node	*find_max_node(t_stack_node *stack)
{
	t_stack_node	*node;
	long			num;

	if (!stack)
		return (NULL);
	num = LONG_MIN;
	while (stack)
	{
		if (stack->n > num)
		{
			num = stack->n;
			node = stack;
		}
		stack = stack->next;
	}
	return (node);
}

t_stack_node	*find_min_node(t_stack_node *stack)
{
	t_stack_node	*node;
	long			num;

	if (!stack)
		return (NULL);
	num = LONG_MAX;
	while (stack)
	{
		if (stack->n < num)
		{
			num = stack->n;
			node = stack;
		}
		stack = stack->next;
	}
	return (node);
}

void	init_b(t_stack_node **a, t_stack_node **b)
{
	if (ft_lst_len(*a) > 4)
		pb(a, b);
	pb(a, b);
}
