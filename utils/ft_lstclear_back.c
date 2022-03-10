/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:19:20 by amarchan          #+#    #+#             */
/*   Updated: 2022/03/10 12:23:23 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

//clear the list starting from the LAST element
void	ft_lstclear_back(t_stack **lst)
{
	t_stack	*iterator;
	t_stack	*prev;

	if (*lst == NULL)
		return ;
	iterator = *lst;
	prev = NULL;
	while (iterator->prev)
	{
		prev = iterator;
		iterator = iterator->prev;
		free(prev);
	}
	free(iterator);
	*lst = NULL;
}
