/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga <lbraga@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 02:53:16 by lbraga            #+#    #+#             */
/*   Updated: 2025/11/03 18:59:14 by lbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_set(t_stk *nod)
{
	int		i;
	t_stk	*max;

	index_reset(nod);
	i = stack_size(nod);
	while (i--)
	{
		max = node_max(nod);
		max->idx = i;
	}
}

t_stk	*node_max(t_stk *nod)
{
	t_stk	*max;

	max = NULL;
	while (nod)
	{
		if (nod->idx == -1)
			if (!max || nod->nbr > max->nbr)
				max = nod;
		nod = nod->nxt;
	}
	return (max);
}

void	index_reset(t_stk *nod)
{
	while (nod)
	{
		nod->idx = -1;
		nod = nod->nxt;
	}
}

int	stack_size(t_stk *nod)
{
	int	i;

	i = 0;
	while (nod)
	{
		nod = nod->nxt;
		i++;
	}
	return (i);
}

int	index_min(t_stk *nod)
{
	int	i;

	i = 0;
	while (nod && nod->idx)
	{
		nod = nod->nxt;
		i++;
	}
	return (i);
}
