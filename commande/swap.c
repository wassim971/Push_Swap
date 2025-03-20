/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbaali <wbaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:28:50 by wbaali            #+#    #+#             */
/*   Updated: 2025/01/25 14:55:29 by wbaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_pile **pile)
{
	if (!*pile || !(*pile)->next)
		return ;
	*pile = (*pile)->next;
	(*pile)->prev->prev = *pile;
	(*pile)->prev->next = (*pile)->next;
	if ((*pile)->next)
		(*pile)->next->prev = (*pile)->prev;
	(*pile)->next = (*pile)->prev;
	(*pile)->prev = NULL;
}

void	sa(t_pile **a, bool print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_pile **b, bool print)
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}
