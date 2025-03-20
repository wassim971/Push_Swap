/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbaali <wbaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:27:39 by wbaali            #+#    #+#             */
/*   Updated: 2025/01/25 12:15:52 by wbaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r_rotate(t_pile **pile)
{
	t_pile	*last;

	if (!*pile || !(*pile)->next)
		return ;
	last = findlast(*pile);
	last->prev->next = NULL;
	last->next = *pile;
	last->prev = NULL;
	*pile = last;
	last->next->prev = last;
}

void	rra(t_pile **a, bool print)
{
	r_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_pile **b, bool print)
{
	r_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_pile **a, t_pile **b, bool print)
{
	r_rotate(a);
	r_rotate(b);
	if (!print)
		ft_printf("rrr\n");
}
