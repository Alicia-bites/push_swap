#include "../headers/ft_push_swap.h"

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

int ft_parse(char *arg)
{
	long long test;
	ft_strip(arg);
	if (ft_strlen(arg) <= 11 && stack_isinteger(arg))
	{
		test = ft_atoll(arg);
		if (ft_invalid_int(test))
		{
			ft_putstr("error", 1);
			exit(EXIT_FAILURE);
		}
			
	} 
	else
	{
		ft_putstr("error", 1);
		exit(1);
	}
	return (0);
}