/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:45:04 by amarchan          #+#    #+#             */
/*   Updated: 2022/04/12 18:57:32 by amarchan         ###   ########.fr       */
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
	if (!*s)
		return (NOT_INT);
	while (s[i])
	{
		if (s[i] == '-' || s[i] == '+')
			i++;
		if (!ft_isdigit(s[i]))
			return (NOT_INT);
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
	int			err;
	t_stack		*lst;

	err = -42;
	ft_strip(arg);
	if (ft_strlen(arg) == 0)
		err = EMPTY_STR;
	err = stack_isinteger(arg);
	if (ft_strlen(arg) <= 11 && stack_isinteger(arg))
	{
		num = ft_atoll(arg);
		if (ft_invalid_int(num))
			err = OUT_INT;
	}
	else
		err = INVALID_ARG;
	lst = ft_create_list(argc, arg);
	if (err < -1 && err > -7)
	{
		ft_putstr("Error", 1, 2);
		ft_clear(lst);
		exit(err);
	}
	return (lst);
}
