/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:54:48 by uschmidt          #+#    #+#             */
/*   Updated: 2025/01/20 15:47:17 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	find_nxt_higher(t_sl *lst, int target)
{
	int	i;
	int	closest;
	int	closest_i;

	i = 0;
	closest = INT_MAX;
	closest_i = -1;
	while (lst)
	{
		if (lst->rank > target && lst->rank - target < closest)
		{
			closest = lst->rank - target;
			closest_i = i;
		}
		lst = lst->next;
		i++;
	}
	return (closest_i);
}

int	find_nxt_lower(t_sl *lst, int target)
{
	int	i;
	int	closest;
	int	closest_i;

	i = 0;
	closest = INT_MAX;
	while (lst)
	{
		if (lst->rank < target && target - lst->rank < closest)
		{
			closest = target - lst->rank;
			closest_i = i;
		}
		lst = lst->next;
		i++;
	}
	return (closest_i);
}

int	calc_ops(t_obj *sobj, int index)
{
	int	rank;
	int	equ_in_a;

	rank = get_rank(&sobj->b, sobj->len_b, index);
	equ_in_a = find_nxt_higher(sobj->a, rank);
	if (index > sobj->len_b / 2)
		index -= sobj->len_b;
	if (equ_in_a > sobj->len_a / 2)
		equ_in_a -= sobj->len_a;
	if (equ_in_a < 0 && index < 0)
	{
		if (index > equ_in_a)
			return (-equ_in_a);
		return (-index);
	}
	else if (equ_in_a > 0 && index > 0)
	{
		if (index > equ_in_a)
			return (index);
		return (equ_in_a);
	}
	else
		return (get_abs(equ_in_a) + get_abs(index));
}

int	calc_ops_turk(t_obj *sobj, int index)
{
	int	rank;
	int	equ_in_b;
	int	lowest_in_b;
	int	lowest_idx_in_b;

	rank = get_rank(&sobj->a, sobj->len_a, index);
	lowest_idx_in_b = find_high_low(sobj->b, 0);
	lowest_in_b = get_rank(&sobj->b, sobj->len_b, lowest_idx_in_b);
	if (lowest_in_b > rank)
		equ_in_b = find_high_low(sobj->b, 1);
	else
		equ_in_b = find_nxt_lower(sobj->b, rank);
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
	while (i < sobj->len_b)
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

int	find_cheapest_turk(t_obj *sobj)
{
	int	i;
	int	cheapest_i;
	int	ops;
	int	cheapest_ops;

	i = 0;
	cheapest_ops = INT_MAX;
	while (i < sobj->len_a)
	{
		ops = calc_ops_turk(sobj, i);
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

int	get_abs(int val)
{
	if (val < 0)
		return (-val);
	return (val);
}
