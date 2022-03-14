#include "../headers/ft_push_swap.h"
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
	t_stack *b;
	
	int	i;

	i = 1;
	if (argc <= 2)
		return (ft_panic(MISSING_ARG));
	while (argv[i])
		a = ft_parse(argv[i++]);
	//ft_sa(a);
	b = ft_lstnew(0);
	ft_print_stack(a);
	//ft_pa(&a, &b);
	//ft_print_stack(a);
	ft_pb(&b, &a);
	puts("------------------");
	ft_print_stack(b);
	return (0);
}
