/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga <lbraga@student.42lisboa.com>>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 02:53:16 by lbraga            #+#    #+#             */
/*   Updated: 2025/10/30 02:40:23 by lbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_idx(t_stk *nod)
{
	int		i;
	t_stk	*max;

	rst_idx(nod);
	i = size_stk(nod);
	while (i--)
	{
		max = max_nod(nod);
		max->idx = i;
	}
}

t_stk	*max_nod(t_stk *nod)
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

void	rst_idx(t_stk *nod)
{
	while (nod)
	{
		nod->idx = -1;
		nod = nod->nxt;
	}
}

int	size_stk(t_stk *nod)
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

int	min_idx(t_stk *nod)
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
