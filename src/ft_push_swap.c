#include "../headers/ft_push_swap.h"


//sort a list of max 3 elements
void	sort_3(t_stack *stack)
{
	t_stack *last_elt;

	last_elt = stack;
	while (last_elt->next)
		last_elt = last_elt->next;
	while (!is_sorted(stack))
	{
		if (stack->num > last_elt->num)
		{
			if (stack->num > stack->next->num)
				ft_ra(stack);
			else
				ft_rra(stack);
		}
		else
			ft_sa(stack);
	}
}

void	ft_print_stack(t_stack *stack)
{
	t_stack *iterator;
	iterator = stack;
	while (iterator)
	{
		printf("%d\n", iterator->num);
		iterator = iterator->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *copy;
	int		i;

	i = 1;
	if (argc <= 2)
		return (ft_panic(MISSING_ARG));
	while (argv[i])
		a = ft_parse(argc, argv[i++]);
	copy = ft_lstcopy(a);
	init_sort(copy);
	ft_getsorted(&a, copy);
	if (argc <= 4)
		sort_3(a);
	else
		sort_more(&a);
	ft_print_stack(a);
	//ft_print_stack(b);
	return (0);
}
