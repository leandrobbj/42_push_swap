/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga <lbraga@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 22:40:08 by lbraga            #+#    #+#             */
/*   Updated: 2025/11/03 19:02:53 by lbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stk **a, t_stk **b, int idx_max)
{
	int	i;
	int	j;
	int	bit_max;

	index_set(*a);
	bit_max = 0;
	while (idx_max >> bit_max)
		bit_max++;
	i = 0;
	while (i < bit_max)
	{
		j = 0;
		while (j <= idx_max)
		{
			if (((*a)->idx >> i) & 1)
				ra(a);
			else
				push(b, a, 'b');
			j++;
		}
		while (*b)
			push(a, b, 'a');
		i++;
	}
}

void	sort_two(t_stk **a)
{
	if ((*a)->nbr > (*a)->nxt->nbr)
		sa(a);
}

void	sort_three(t_stk **a)
{
	t_stk	*max;

	index_reset(*a);
	max = node_max(*a);
	if (max == *a)
		ra(a);
	else if (max == (*a)->nxt)
		rra(a);
	sort_two(a);
}

void	sort_size(t_stk **a, t_stk **b, int size)
{
	int	i;

	i = size;
	while (i-- > 3)
		pb_min(a, b);
	sort_three(a);
	while (size-- > 3)
		push(a, b, 'a');
}
