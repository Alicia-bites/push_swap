#include "../headers/ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;
	int	i;

	i = 0;
	if (argc != 1)
		return (ft_panic(1));
	stack.size = ft_strlen(argv[1]);
	if (stack.size == 0)
		return (ft_panic(EMPTY_STR));
	while (argv[i])
		ft_parse(argv[i]);
	// ft_create_list(stack);
	return (0);
}
