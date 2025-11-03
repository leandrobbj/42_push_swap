/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga <lbraga@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 05:21:58 by lbraga            #+#    #+#             */
/*   Updated: 2025/11/03 19:02:51 by lbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_min(t_stk **a, t_stk **b)
{
	int	idx;
	int	siz;

	index_set(*a);
	idx = index_min(*a);
	siz = stack_size(*a);
	if (idx <= siz / 2)
		while (idx--)
			ra(a);
	else
		while (idx++ < siz)
			rra(a);
	push(b, a, 'b');
}

void	push(t_stk **dst, t_stk **src, char c)
{
	t_stk	*nod;

	nod = *src;
	*src = (*src)->nxt;
	nod->nxt = *dst;
	*dst = nod;
	if (c == 'a')
		ft_printf("pa\n");
	else if (c == 'b')
		ft_printf("pb\n");
}

void	sa(t_stk **a)
{
	t_stk	*head;

	head = *a;
	*a = (*a)->nxt;
	head->nxt = (*a)->nxt;
	(*a)->nxt = head;
	ft_printf("sa\n");
}

void	ra(t_stk **a)
{
	t_stk	*head;
	t_stk	*lst;

	head = *a;
	*a = (*a)->nxt;
	lst = *a;
	while (lst->nxt)
		lst = lst->nxt;
	lst->nxt = head;
	head->nxt = NULL;
	ft_printf("ra\n");
}

void	rra(t_stk **a)
{
	t_stk	*lst;
	t_stk	*prev_lst;

	prev_lst = *a;
	while (prev_lst->nxt->nxt)
		prev_lst = prev_lst->nxt;
	lst = prev_lst->nxt;
	prev_lst->nxt = NULL;
	lst->nxt = *a;
	*a = lst;
	ft_printf("rra\n");
}
