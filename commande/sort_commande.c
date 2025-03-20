/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_commande.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbaali <wbaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:50:23 by wbaali            #+#    #+#             */
/*   Updated: 2025/02/05 22:37:30 by wbaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_pile **a, t_pile **b, t_pile *cheapest_node, int i)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
	{
		if (i == 1)
			rr(a, b, false);
		if (i == 0)
			rrr(a, b, false);
	}
	current_index(*a);
	current_index(*b);
}

static void	move_a_to_b(t_pile **a, t_pile **b)
{
	t_pile	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->abovemedian && cheapest_node->target->abovemedian)
		rotate_both(a, b, cheapest_node, 1);
	else if (!(cheapest_node->abovemedian)
		&& !(cheapest_node->target->abovemedian))
		rotate_both(a, b, cheapest_node, 0);
	prep_push(a, cheapest_node, 'a');
	prep_push(b, cheapest_node->target, 'b');
	pb(b, a, false);
}

static void	move_b_to_a(t_pile **a, t_pile **b)
{
	prep_push(a, (*b)->target, 'a');
	pa(a, b, false);
}

static void	min_on_top(t_pile **a)
{
	while ((*a)->nbr != findmin(*a)->nbr)
	{
		if (findmin(*a)->abovemedian)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_pile(t_pile **a, t_pile **b)
{
	int	len_a;

	len_a = pile_len(*a);
	if (len_a-- > 3 && !pile_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !pile_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !pile_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
