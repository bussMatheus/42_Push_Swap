#include "./include/push_swap.h"

//sa: swap the first two elements at top of the stack a
void	sa(t_stack_node *a, int i)
{
	int tmp;

	if (a == NULL || a->next == NULL)
		return ;
	tmp = a->n;
	a->n = a->next->n;
	a->next->n = tmp;
	if (i == 0)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node *b, int i)
{
	int tmp;

	if (b == NULL || b->next == NULL)
		return ;
	tmp = b->n;
	b->n = b->next->n;
	b->next->n = tmp;
	if (i == 0)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node *a, t_stack_node *b, int i)
{
	sa(a, 1);
	sb(b, 1);
	if (i == 0)
		write(1, "ss\n", 1);
}