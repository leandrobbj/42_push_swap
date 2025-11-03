/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga <lbraga@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 22:20:29 by lbraga            #+#    #+#             */
/*   Updated: 2025/11/03 19:03:46 by lbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stk	*a;
	t_stk	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		exit_routine(a, ac, av, 1);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		av = av + 1;
	check_parse_stack(&a, ac, av);
	sort_stack(&a, &b);
	exit_routine(a, ac, av, 0);
}

void	check_parse_stack(t_stk **a, int ac, char **av)
{
	int		i;
	long	nbr;
	t_stk	*new;

	i = 0;
	while (av[i])
	{
		if (!av[i][0] || !check_number(av[i]))
			exit_routine(*a, ac, av, 2);
		nbr = ft_atol_intoverflow(av[i]);
		if (nbr == LONG_MAX)
			exit_routine(*a, ac, av, 3);
		if (!check_duplicate(*a, (int)nbr))
			exit_routine(*a, ac, av, 4);
		new = malloc(sizeof(t_stk));
		if (!new)
			exit_routine(*a, ac, av, 5);
		parse_stack(a, new, nbr);
		i++;
	}
}

void	parse_stack(t_stk **a, t_stk *new, int nbr)
{
	t_stk	*last;

	new->nbr = nbr;
	new->nxt = NULL;
	if (!(*a))
		*a = new;
	else
	{
		last = *a;
		while (last->nxt)
			last = last->nxt;
		last->nxt = new;
	}
}

void	sort_stack(t_stk **a, t_stk **b)
{
	int	size;

	if (!check_sort(*a))
	{
		size = stack_size(*a);
		if (size == 2)
			sort_two(a);
		else if (size == 3)
			sort_three(a);
		else if (size > 3 && size < 50)
			sort_size(a, b, size);
		else
			radix_sort(a, b, size - 1);
	}
}

void	exit_routine(t_stk *nod, int ac, char **words, int err)
{
	printf_error(err);
	if (err == 1)
		exit (1);
	free_all(nod, ac, words);
	if (err)
		exit (1);
	exit (0);
}
