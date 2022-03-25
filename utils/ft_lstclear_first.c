/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:28:33 by amarchan          #+#    #+#             */
/*   Updated: 2022/03/23 18:08:43 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

//prend l'adresse du pointeur sur l'elt a supprimer
//supprime l'elt
//fait pointer le pointeur de l'ex-elt sur l'elt suivant
void	ft_lstclear_first(t_stack **elt)
{
	t_stack	*iterator;

	//printf("(*elt)->num %d\n", (*elt)->num);
	iterator = *elt;
	free(*elt);
	if (iterator->next)
		*elt = iterator->next;
	else
		*elt = NULL;
	if (iterator->next)
		(*elt)->prev = NULL;
	
}