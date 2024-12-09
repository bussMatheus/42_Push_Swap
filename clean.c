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
		//printf("Freeing node: %d\n", (*lst)->n);
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
