/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:02:32 by mely-pan          #+#    #+#             */
/*   Updated: 2024/12/09 18:15:12 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

void	free_splited(char **numbers)
{
	int	i;

	i = 0;
	if (numbers)
	{
		while (numbers[i])
			free(numbers[i++]);
		free(numbers);
	}
}

void	free_lst(t_stack_node **lst)
{
	t_stack_node	*aux;

	if (!lst)
		return ;
	while (*lst)
	{
		aux = (*lst)->next;
		(*lst)->n = 0;
		free(*lst);
		*lst = aux;
	}
}

void	indexes(t_stack_node **a, t_stack_node **b)
{
	current_index(*a);
	current_index(*b);
}
