#include "../headers/ft_push_swap.h"

// void	ft_pb(t_stack **b, t_stack **a)
// {
// 	if (b)
// 	{
// 		ft_lstadd_front(b, *a);
// 		ft_putstr("pb", 1, 1);
// 	}
// }

// void	ft_lstadd_front(t_stack **first_elt, t_stack *new)
// {
// 	if (first_elt && new)
// 	{
// 		new->next = *first_elt;
// 		*first_elt = new;
// 		new->next->prev = *first_elt;
// 	}	
// }
void	ft_rra(t_stack *stack)
{
	int tmp;

	if (stack)
	{
		while(stack->next)
			stack = stack->next;
		tmp = stack->num;
		while (stack->prev)
		{
			stack->num = stack->prev->num;
			stack = stack->prev;
		}
		stack->num = tmp;
	}
	ft_putstr("rra", 1, 1);
}
// t_stack *ft_create_list(char *arg)
// {
// 	static int	i = 0;
// 	static t_stack *lst;
// 	t_stack	*new;
// 	int	int_arg;
	
// 	int_arg = ft_atoi(arg);
// 	if (i == 0)
// 		lst = ft_lstnew(int_arg);
// 	else
// 	{
// 		new = ft_lstnew(int_arg);
// 		ft_lstadd_back(&lst, new);
// 		ft_checkdup(lst, new->num);
// 	}	
// 	i++;
// 	return (lst);
// }

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
			a = ft_create_list(argv[i++]);
		iterator = a;
		while (iterator)
		{
			printf("iterator->num = %d\n", iterator->num);
			iterator = iterator->next;
		}
		ft_rra(a);
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