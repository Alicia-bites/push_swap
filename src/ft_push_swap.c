#include "../headers/ft_push_swap.h"
//check if list is sorted
//if elt is bigger than next elt, return 0. 
int	is_sorted(t_stack *stack)
{	
	t_stack *iterator;

	iterator = stack;
	while (iterator->next)
	{
		if (iterator->num > iterator->next->num)
			return (0);
		iterator = iterator->next;
	}
	return (1);
}

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
	//t_stack *b;
	
	int	i;

	i = 1;
	if (argc <= 2)
		return (ft_panic(MISSING_ARG));
	while (argv[i])
		a = ft_parse(argc, argv[i++]);
	//ft_sa(a);
	//b = ft_lstnew(0);
	ft_print_stack(a);
	//ft_pa(&a, &b);
	//ft_print_stack(a);
	//ft_pb(&b, &a);
	//ft_ra(a);
	//ft_rb(b);
	//ft_rr(a, b);
	//ft_rra(a);
	sort_3(a);
	puts("------------------");
	ft_print_stack(a);
	//ft_print_stack(b);
	return (0);
}
