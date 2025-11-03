/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga <lbraga@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:01:29 by lbraga            #+#    #+#             */
/*   Updated: 2025/11/03 18:57:54 by lbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '-' || av[i] == '+')
		if (!av[++i])
			return (0);
	while (av[i])
		if (!ft_isdigit(av[i++]))
			return (0);
	return (1);
}

int	check_duplicate(t_stk *nod, int nbr)
{
	while (nod)
	{
		if (nod->nbr == nbr)
			return (0);
		nod = nod->nxt;
	}
	return (1);
}

int	check_sort(t_stk *nod)
{
	while (nod && nod->nxt)
	{
		if (nod->nbr > nod->nxt->nbr)
			return (0);
		nod = nod->nxt;
	}
	return (1);
}

void	printf_error(int err)
{
	if (err == 2)
		ft_printf("Error: invalid characters\n");
	else if (err == 3)
		ft_printf("Error: integer overflow\n");
	else if (err == 4)
		ft_printf("Error: number duplicated\n");
	else if (err == 5)
		ft_printf("Error: malloc fail\n");
}

void	free_all(t_stk *nod, int ac, char **words)
{
	int		i;
	t_stk	*tmp;

	if (ac == 2)
	{
		i = 0;
		while (words[i])
			free(words[i++]);
		free(words);
	}
	while (nod)
	{
		tmp = nod;
		nod = nod->nxt;
		free(tmp);
	}
}
