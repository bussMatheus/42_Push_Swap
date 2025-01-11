/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:20:13 by mely-pan          #+#    #+#             */
/*   Updated: 2025/01/07 16:48:30 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_stack_node
{
	int					n;
	int					index;
	int					cost;
	bool				cheapest;
	bool				above_median;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

/*              CHECK FUNCTIONS            */
int						ft_isvalid_n(char *numbers);
int						sorted_stack(t_stack_node *a);
int						check_str_numbers(char **numbers, t_stack_node **a);
int						ft_isdup(char **numbers, int n, int i, int flag_argc);
int						manage_input(int argc, char **argv, t_stack_node **a);
int						check_argv_numbers(int argc, char **argv,
							t_stack_node **a);

/*              CLEAN FUNCTIONS            */
void					ft_error(void);
void					free_splited(char **numbers);
void					free_lst(t_stack_node **lst);

/*					LST FUNCTIONS			*/
int						append(t_stack_node **a, int n);
int						ft_lst_len(t_stack_node *stack);
void					current_index(t_stack_node *stack);
void					set_cost(t_stack_node *a, t_stack_node *b);
void					init_b(t_stack_node **a, t_stack_node **b);
void					indexes(t_stack_node **a, t_stack_node **b);
void					set_target(t_stack_node *a, t_stack_node *b);
void					set_targetb(t_stack_node *a, t_stack_node *b);
void					cost_calc(t_stack_node *node, int len_a, int len_b);
t_stack_node			*ft_lstnew2(int n);
t_stack_node			*get_cheapest(t_stack_node *a);
t_stack_node			*find_max_node(t_stack_node *stack);
t_stack_node			*find_min_node(t_stack_node *stack);

/*              	OPERATIONS					*/
void					sa(t_stack_node *a, int i);
void					sb(t_stack_node *b, int i);
void					ss(t_stack_node *a, t_stack_node *b, int i);
void					pa(t_stack_node **a, t_stack_node **b);
void					pb(t_stack_node **a, t_stack_node **b);
void					ra(t_stack_node **a, int i);
void					rb(t_stack_node **b, int i);
void					rr(t_stack_node **a, t_stack_node **b);
void					rra(t_stack_node **a, int i);
void					rrb(t_stack_node **b, int i);
void					rrr(t_stack_node **a, t_stack_node **b);

/*             		ALGORITHM					*/
void					sort_three(t_stack_node **a);
void					set_top(t_stack_node **stack, t_stack_node *top,
							int flag);
void					set_rr_rrr(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest);
void					min_on_top(t_stack_node **stack);
void					sort_algo(t_stack_node **a, t_stack_node **b);

#endif