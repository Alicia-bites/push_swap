/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:45:04 by amarchan          #+#    #+#             */
/*   Updated: 2022/03/25 16:00:53 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

//convert each argument to from char to int and put it in the a linked list
t_stack	*ft_create_list(int argc, char *arg)
{
	static int		i = 0;
	static t_stack	*lst;
	t_stack			*new;
	int				int_arg;

	int_arg = ft_atoi(arg);
	if (i == 0)
		lst = ft_lstnew(argc - 1, int_arg, i, 0);
	else
	{
		new = ft_lstnew(argc - 1, int_arg, i, 0);
		ft_lstadd_back(&lst, new);
		ft_checkdup(lst, new->num);
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
			ft_panic(NOT_INT);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (1);
}

//get rid of extra spaces before argument
static void	ft_strip(char *s)
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
t_stack	*ft_parse(int argc, char *arg)
{
	long long	num;
	t_stack		*lst;

	ft_strip(arg);
	if (ft_strlen(arg) == 0)
	{
		ft_panic(EMPTY_STR);
		exit(EXIT_FAILURE);
	}
	else if (ft_strlen(arg) <= 11 && stack_isinteger(arg))
	{
		num = ft_atoll(arg);
		if (ft_invalid_int(num))
		{
			ft_panic(OUT_INT);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		ft_panic(INVALID_ARG);
		exit(EXIT_FAILURE);
	}
	lst = ft_create_list(argc, arg);
	return (lst);
}
