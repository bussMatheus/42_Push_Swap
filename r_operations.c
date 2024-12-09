#include "./include/push_swap.h"

void	ra(t_stack_node **a, int i)
{
	t_stack_node	*aux;
	t_stack_node	*curr_node;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	aux = *a;
	curr_node = *a;
	while (curr_node->next != NULL)
		curr_node = curr_node->next;
	*a = (*a)->next;
	(*a)->prev = NULL;
	curr_node->next = aux;
	aux->prev = curr_node;
	aux->next = NULL;
	if (i == 0)
		write(1, "ra\n",3);
}

void	rb(t_stack_node **b, int i)
{
	t_stack_node	*aux;
	t_stack_node	*curr_node;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	aux = *b;
	curr_node = *b;
	while (curr_node->next != NULL)
		curr_node = curr_node->next;
	*b = (*b)->next;
	(*b)->prev = NULL;
	curr_node->next = aux;
	aux->prev = curr_node;
	aux->next = NULL;
	if (i == 0)
		write(1, "rb\n",3);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	ra(a, 1);
	rb(b, 1);
	write(1, "rr\n", 3);
}
