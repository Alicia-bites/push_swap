#include "../headers/ft_push_swap.h"

//check if duplicate entry
int	ft_checkdup(int prev, int elt)
{
	// printf("prev %d\n", prev);
	// printf("elt %d\n", elt);
	if (prev == elt)
	{
		ft_putstr("Found duplicates", 1);
		exit(EXIT_FAILURE);
	}
	return (0);
}
//convert each argument to from char to int and put it in the a linked list
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
		ft_checkdup(new->prev->num, new->num);
	}	
	i++;
	return (lst);
}

//check if argument is integer
static int	stack_isinteger(char *s)
{
	int	i;
	i = 0;
	while (s[i])
	{
		if (s[i] == '-' || s[i] == '+')
			i++;
		if (!ft_isdigit(s[i]))
		{	
			printf("%s\n", s);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (1);
}

//get rid of extra spaces before argument
static void    ft_strip(char *s)
{
    ft_lstrip(s);
    ft_rstrip(s);
}

//check if argument isn't smaller than INT_MIN or bigger than INT_MAX
static int	ft_invalid_int(long long arg)
{
	return (!(arg <= INT_MAX && arg >= INT_MIN));
}

//check if arguments are correct and if so call ft_create_list.
t_stack *ft_parse(char *arg)
{
	long long num;
	t_stack *lst;
	ft_strip(arg);
	if (ft_strlen(arg) <= 11 && stack_isinteger(arg))
	{
		num = ft_atoll(arg);
		if (ft_invalid_int(num))
		{
			ft_putstr("Error", 1);
			exit(EXIT_FAILURE);
		}
	} 
	else
	{
		ft_putstr("error", 1);
		exit(1);
	}
	lst = ft_create_list(arg);
	return (lst);
}