/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga <lbraga@student.42lisboa.com>>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 22:40:08 by lbraga            #+#    #+#             */
/*   Updated: 2025/10/30 04:25:01 by lbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stk **a, t_stk **b, int idx_max)
{
	int	i;
	int	j;
	int	bit_max;

	set_idx(*a);
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
				pu(b, a, 'b');
			j++;
		}
		while (*b)
			pu(a, b, 'a');
		i++;
	}
}

void	sort_two(t_stk **a)
{
	if ((*a)->nbr > (*a)->nxt->nbr)
		sa(a);
}

void	sort_thr(t_stk **a)
{
	t_stk	*max;

	rst_idx(*a);
	max = max_nod(*a);
	if (max == *a)
		ra(a);
	else if (max == (*a)->nxt)
		rra(a);
	sort_two(a);
}

void	sort_siz(t_stk **a, t_stk **b, int size)
{
	int	i;

	i = size;
	while (i-- > 3)
		pb_min(a, b);
	sort_thr(a);
	while (size-- > 3)
		pu(a, b, 'a');
}
