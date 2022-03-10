#include "../headers/ft_push_swap.h"

t_stack *ft_create_list(char *arg)
{
	static int	i = 0;
	static t_stack *lst;
	t_stack	*new;
	int	int_arg;
	
	int_arg = ft_atoi(arg);
	if (i == 0)
		lst = ft_lstnew(int_arg);
	else
	{
		new = ft_lstnew(int_arg);
		ft_lstadd_back(&lst, new);
	}	
	i++;
	return (lst);
}

int	main(int argc, char **argv)
{
	int	i;
	t_stack *lst;
	t_stack *iterator;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
			lst = ft_create_list(argv[i++]);
	}
	iterator = lst;
	while (iterator)
	{
		printf("iterator->num = %d\n", iterator->num);
		iterator = iterator->next;
	}
	return (0);
}

// int main(int argc, char **argv)
// {
// 	int	i;
// 	long long test;
	
// 	i = 1;
// 	while (argv[i])
// 	{
// 		ft_strip(argv[i]);
// 		if (ft_strlen(argv[i]) <= 11 && pile_isdigit(argv[i]))
// 		{
// 			test = ft_atoll(argv[i]);
// 			printf("%d\n", ft_is_integer(test));
// 		} 
// 		else
// 		{
// 			puts("error");
// 			exit(1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }