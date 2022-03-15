#include "../headers/ft_push_swap.h"

static void	init_sort(t_stack *stack)
{
	int	temp;
	int	size;

	size = stack->size - 1;
	while (stack->next)
	{	
		while (size > 0)
		{
			if (stack->num > stack->next->num)
			{
				temp = stack->num;
				stack->num = stack->next->num;
				stack->next->num = temp;
			}
			stack = stack->next;			
		}
		size--;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	t_stack *a;
	t_stack *b;
	t_stack *iterator;

	i = 1;
	if (argc > 2)
	{
		while (argv[i])
			a = ft_create_list(argc, argv[i++]);

		iterator = a;
		while (iterator)
		{
			printf("iterator->num = %d\n", iterator->num);
			iterator = iterator->next;
		}
		init_sort(a);
		puts("----------------------------------------");
		iterator = a;
		while (iterator)
		{
			printf("iterator->num = %d\n", iterator->num);
			iterator = iterator->next;
		}
	}
	return (0);
}