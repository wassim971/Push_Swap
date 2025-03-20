/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbaali <wbaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:10:32 by wbaali            #+#    #+#             */
/*   Updated: 2025/02/08 18:23:27 by wbaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_syntax(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int	check_duplicate(t_pile *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_pile(t_pile **pile)
{
	t_pile	*tmp;
	t_pile	*actuel;

	if (!pile)
		return ;
	actuel = *pile;
	while (actuel)
	{
		tmp = actuel->next;
		actuel->nbr = 0;
		free(actuel);
		actuel = tmp;
	}
	*pile = NULL;
}

void	free_errors(t_pile **a)
{
	free_pile(a);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}
