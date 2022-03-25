/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:09:36 by amarchan          #+#    #+#             */
/*   Updated: 2022/03/19 14:25:16 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

void	ft_lstadd_front(t_stack **first_elt, t_stack *new)
{
	//printf("new->num : %d\n", new->num);
	if (first_elt && new)
	{
		new->next = *first_elt;
		*first_elt = new;
		new->next->prev = *first_elt;
	}	
}
