/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:07:43 by amarchan          #+#    #+#             */
/*   Updated: 2022/03/14 15:48:43 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

int	ft_panic(int errcode)
{
	if (errcode == MISSING_ARG)
		ft_putstr("Error", 1, 2);
	else if (errcode == EMPTY_STR)
		ft_putstr("Error", 1, 2);
	else if (errcode == FOUND_DUP)
		ft_putstr("Error", 1, 2);
	else if (errcode == NOT_INT)
		ft_putstr("Error", 1, 2);
	else if (errcode == OUT_INT)
		ft_putstr("Error", 1, 2);
	else if (errcode == INVALID_ARG)
		ft_putstr("Error", 1, 2);
	else if (errcode == MALLOC_FAILURE)
		ft_putstr("Error", 1, 2);
	// printf("errcode = %d\n", errcode);
	return (errcode);
}

//check if duplicate entry
int	ft_checkdup(t_stack *stack, int elt)
{
	t_stack	*iterator;
	
	if (stack)
	{
		iterator = stack;
		while (iterator->next)
		{
			if (iterator->num == elt)
			{
				ft_panic(FOUND_DUP);
				exit(EXIT_FAILURE);
			}
			iterator = iterator->next;
		}
	}
	return (0);
}