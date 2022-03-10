#include "../headers/ft_push_swap.h"


int	main(int argc, char **argv)
{
	t_stack *stack;
	t_stack *iterator;
	int	i;
	int size;

	i = 1;
	if (argc <= 1)
		return (ft_panic(1));
	size = ft_strlen(argv[1]);
	if (size == 0)
		return (ft_panic(EMPTY_STR));
	while (argv[i])
		stack = ft_parse(argv[i++]);
	printf("stack : %p\n", stack);
	iterator = stack;
	while (iterator)
	{
		printf("iterator->num = %d\n", iterator->num);
		iterator = iterator->next;
	}
	return (0);
}
