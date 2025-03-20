/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbaali <wbaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:38:48 by wbaali            #+#    #+#             */
/*   Updated: 2025/02/06 13:04:55 by wbaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_pile
{
	int				nbr;
	int				index;
	int				pushcost;
	bool			abovemedian;
	bool			cheap;
	struct s_pile	*target;
	struct s_pile	*prev;
	struct s_pile	*next;
}					t_pile;

char				**ft_splits(char *s, char c);
void				init_pile_a(t_pile **a, char **av);
int					check_syntax(char *str);
int					check_duplicate(t_pile *a, int n);
void				free_errors(t_pile **a);
t_pile				*findlast(t_pile *pile);
t_pile				*findlast(t_pile *pile);
t_pile				*findmax(t_pile *pile);
void				sort_three(t_pile **a);
void				sa(t_pile **a, bool print);
void				ra(t_pile **a, bool print);
void				rra(t_pile **a, bool print);
bool				pile_sorted(t_pile *pile);
int					pile_len(t_pile *pile);
void				pa(t_pile **a, t_pile **b, bool print);
void				pb(t_pile **b, t_pile **a, bool print);
void				init_nodes_a(t_pile *a, t_pile *b);
void				init_nodes_b(t_pile *a, t_pile *b);
void				current_index(t_pile *pile);
void				free_pile(t_pile **pile);
void				sort_pile(t_pile **a, t_pile **b);
t_pile				*get_cheapest(t_pile *pile);
void				prep_push(t_pile **pile, t_pile *high_node, char pilename);
void				rrb(t_pile **b, bool print);
void				rb(t_pile **b, bool print);
void				rr(t_pile **a, t_pile **b, bool print);
void				rrr(t_pile **a, t_pile **b, bool print);
t_pile				*findmin(t_pile *pile);
void				ft_free_split(char **splitted);

#endif