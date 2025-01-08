/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:08:20 by uschmidt          #+#    #+#             */
/*   Updated: 2025/01/07 15:53:30 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	find_lowest(t_sl	*list)
{
	int		i;
	int		i_lowest;
	int		lowest_val;
	int		current_val;

	i = 0;
	lowest_val = INT_MAX;
	while (list)
	{
		current_val = list->value;
		if (current_val < lowest_val)
		{
			lowest_val = current_val;
			i_lowest = i;
		}
		i++;
		list = list->next;
	}
	return (i_lowest);
}

void	solve_simple(t_sl **a, t_sl **b, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		while ((*a)->rank != i)
		{
			call_action("ra", a, b);
		}
		call_action("pb", a, b);
		i++;
	}
	while (len-- > 0)
		call_action("pa", a, b);
}
