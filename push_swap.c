/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:05:42 by mely-pan          #+#    #+#             */
/*   Updated: 2024/12/18 20:15:24 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (!manage_input(argc, argv, &a))
		ft_error();
	if (!sorted_stack(a))
		sort_algo(&a, &b);
	free_lst(&a);
	free_lst(&b);
	return (0);
}
