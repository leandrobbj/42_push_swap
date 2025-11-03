/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga <lbraga@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:09:32 by lbraga            #+#    #+#             */
/*   Updated: 2025/11/03 19:01:41 by lbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "src/libft/libft.h"

typedef struct s_stk
{
	int				nbr;
	int				idx;
	struct s_stk	*nxt;
}					t_stk;

// parsing
void	check_parse_stack(t_stk **a, int ac, char **av);
void	parse_stack(t_stk **a, t_stk *new, int nbr);
int		check_number(char *av);
int		check_duplicate(t_stk *nod, int nbr);
int		check_sort(t_stk *nod);
// exit
void	exit_routine(t_stk *nod, int ac, char **words, int err);
void	printf_error(int err);
void	free_all(t_stk *nod, int ac, char **words);
// index
int		stack_size(t_stk *nod);
void	index_set(t_stk *nod);
void	index_reset(t_stk *nod);
int		index_min(t_stk *nod);
t_stk	*node_max(t_stk *nod);
// sort
void	sort_stack(t_stk **a, t_stk **b);
void	sort_two(t_stk **a);
void	sort_three(t_stk **a);
void	sort_size(t_stk **a, t_stk **b, int size);
void	radix_sort(t_stk **a, t_stk **b, int size);
// moves
void	pb_min(t_stk **a, t_stk **b);
void	push(t_stk **dst, t_stk **src, char c);
void	sa(t_stk **a);
void	ra(t_stk **a);
void	rra(t_stk **a);

#endif