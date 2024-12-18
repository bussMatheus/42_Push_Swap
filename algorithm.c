/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:01:25 by mely-pan          #+#    #+#             */
/*   Updated: 2024/12/18 18:16:42 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*aux;

	aux = find_max_node(*a);
	if (aux == *a)
		ra(a, 0);
	else if (aux == (*a)->next)
		rra(a, 0);
	if ((*a)->n > (*a)->next->n)
		sa(*a, 0);
}

void	sort_it(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	init_b(a, b);
	while (ft_lst_len(*a) > 3)
	{
		indexes(a, b);
		set_target(*a, *b);
		set_cost(*a, *b);
		cheapest = get_cheapest(*a);
		set_rr_rrr(a, b, cheapest);
		set_top(a, cheapest, 0);
		set_top(b, cheapest->target_node, 1);
		pb(a, b);
	}
	sort_three(a);
	while (*b)
	{
		indexes(a, b);
		set_targetb(*a, *b);
		set_cost(*a, *b);
		cheapest = get_cheapest(*b);
		set_top(a, cheapest->target_node, 0);
		pa(a, b);
	}
	min_on_top(a);
}

void	sort_algo(t_stack_node **a, t_stack_node **b)
{
	int	len;

	len = ft_lst_len(*a);
	current_index(*a);
	if (len == 2)
	{
		if ((*a)->n > (*a)->next->n)
			sa(*a, 0);
	}
	else if (len == 3)
		sort_three(a);
	else
		sort_it(a, b);
	current_index(*a);
}

int	sorted_stack(t_stack_node *a)
{
	while (a && a->next)
	{
		if (a->n > a->next->n)
			return (0);
		a = a->next;
	}
	return (1);
}
