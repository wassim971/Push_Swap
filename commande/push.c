/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbaali <wbaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:32:08 by wbaali            #+#    #+#             */
/*   Updated: 2025/01/24 11:01:52 by wbaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_pile **pile_dst, t_pile **pile_src)
{
	t_pile	*pile_node;

	if (!*pile_src)
		return ;
	pile_node = *pile_src;
	*pile_src = (*pile_src)->next;
	if (*pile_src)
		(*pile_src)->prev = NULL;
	pile_node->prev = NULL;
	if (!*pile_dst)
	{
		*pile_dst = pile_node;
		pile_node->next = NULL;
	}
	else
	{
		pile_node->next = *pile_dst;
		pile_node->next->prev = pile_node;
		*pile_dst = pile_node;
	}
}

void	pa(t_pile **a, t_pile **b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_pile **b, t_pile **a, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}
