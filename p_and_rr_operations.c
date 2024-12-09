#include "./include/push_swap.h"

void	pa(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*aux;

	if (*b == NULL)
		return ;
	aux = *b;
	*b = (*b)->next;
	if (*b != NULL)
		(*b)->prev = NULL;
	aux->next = NULL;
	aux->prev = NULL;
	if (a && aux)
	{
		aux->next = *a;
		if (*a)
			(*a)->prev = aux;
		*a = aux;
	}
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*aux;

	if (*a == NULL)
		return ;
	aux = *a;
	*a = (*a)->next;
	if (*a != NULL)
		(*a)->prev = NULL;
	aux->next = NULL;
	aux->prev = NULL;
	if (b && aux)
	{
		aux->next = *b;
		if (*b)
			(*b)->prev = aux;
		*b = aux;
	}
	write(1, "pb\n", 3);
}

void	rra(t_stack_node **a, int i)
{
	t_stack_node	*node;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	node = *a;
	while (node->next)
		node = node->next;
	if (node->prev != NULL)
		node->prev->next = NULL;
	node->prev = NULL;
	node->next = *a;
	(*a)->prev = node;
	*a = node;
	if (i == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, int i)
{
	t_stack_node	*node;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	node = *b;
	while (node->next)
		node = node->next;
	if (node->prev != NULL)
		node->prev->next = NULL;
	node->prev = NULL;
	node->next = *b;
	(*b)->prev = node;
	*b = node;
	if (i == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rra(a, 1);
	rrb(b, 1);
	write(1, "rrr\n", 4);
}