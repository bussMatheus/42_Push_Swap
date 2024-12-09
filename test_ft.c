#include "./include/push_swap.h"

void	print_list(t_stack_node **a)
{
	t_stack_node *temp;

	if (*a)
	{
		while (*a)
		{
			temp = *a;
			printf("number: %d\nIndex: %d\n=======\n", (*a)->n, (*a)->index);
			*a = temp->next;
		}
	}
	else
		ft_error();
}

void	print_list_info(t_stack_node **lst)
{
	t_stack_node *tmp;

	tmp = *lst;
	if (tmp)
		while (tmp)
		{
			if (tmp->next && tmp->prev)
				printf("node n: %d | prev n %d | next n: %d\n", tmp->n, tmp->prev->n, tmp->next->n);
			else if (!(tmp->prev))
				printf("node n: %d | prev n null | next n: %d\n", tmp->n, tmp->next->n);
			else if (!(tmp->next))
				printf("node n: %d | prev n %d | next n: null\n", tmp->n, tmp->prev->n);
			tmp = tmp->next;
		}
}