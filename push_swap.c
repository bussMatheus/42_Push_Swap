#include "./include/push_swap.h"

int main(int argc, char **argv)
{
	t_stack_node *a;
	t_stack_node *b;

	a = NULL;
	b = NULL;
	if (!manage_input(argc, argv, &a))
		ft_error();
	if (!sorted_stack(a))
		sort_algo(&a, &b);
	free_lst(&a);
	free_lst(&b);
	return(0);
}
