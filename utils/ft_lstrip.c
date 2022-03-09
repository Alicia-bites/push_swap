/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:48:27 by amarchan          #+#    #+#             */
/*   Updated: 2022/03/09 14:50:31 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

void    ft_lstrip(char *s)
{
    int    i;

    i = 0;
    while (s[i] && (ft_isspace(s[i])))
        i++;
    ft_memmove(s, s + i, ft_strlen(s) - i + 1);
}