/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:54:48 by uschmidt          #+#    #+#             */
/*   Updated: 2025/01/22 11:50:48 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	find_equ(t_obj *sobj, int index)
{
	int	rank;
	int	lowest_in_b;
	int	lowest_idx_in_b;

	rank = get_rank(&sobj->a, sobj->len_a, index);
	lowest_idx_in_b = find_high_low(sobj->b, 0);
	lowest_in_b = get_rank(&sobj->b, sobj->len_b, lowest_idx_in_b);
	if (lowest_in_b > rank)
		return (find_high_low(sobj->b, 1));
	else
		return (find_nxt_lower(sobj->b, rank));
}
int	calc_ops(t_obj *sobj, int index)
{
	int	equ_in_b;

	equ_in_b = find_equ(sobj, index);
	if (index > sobj->len_a / 2)
		index -= sobj->len_a;
	if (equ_in_b > sobj->len_b / 2)
		equ_in_b -= sobj->len_b;
	if (equ_in_b < 0 && index < 0)
	{
		if (index > equ_in_b)
			return (-equ_in_b);
		return (-index);
	}
	else if (equ_in_b > 0 && index > 0)
	{
		if (index > equ_in_b)
			return (index);
		return (equ_in_b);
	}
	else
		return (get_abs(equ_in_b) + get_abs(index));
}

int	find_cheapest(t_obj *sobj)
{
	int	i;
	int	cheapest_i;
	int	ops;
	int	cheapest_ops;

	i = 0;
	cheapest_ops = INT_MAX;
	while (i < sobj->len_a)
	{
		ops = calc_ops(sobj, i);
		if (ops < cheapest_ops)
		{
			cheapest_ops = ops;
			cheapest_i = i;
		}
		if (cheapest_ops == 0)
			break ;
		i++;
	}
	return (cheapest_i);
}
