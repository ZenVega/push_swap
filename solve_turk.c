/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_turk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:55:01 by uschmidt          #+#    #+#             */
/*   Updated: 2025/01/22 16:21:25 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	sort_three(t_obj *sobj)
{
	int	first;
	int	second;
	int	third;

	if (sobj->len_a != 3)
		return ;
	first = sobj->a->rank;
	second = sobj->a->next->rank;
	third = sobj->a->next->next->rank;
	if (first > second && second > third)
	{
		call_action("sa", sobj);
		call_action("rra", sobj);
	}
	else if (first > third && third > second)
		call_action("ra", sobj);
	else if (second > first && first > third)
		call_action("rra", sobj);
	else if (second > third && third > first)
		call_action("sa", sobj);
	else if (third > first && first > second)
	{
		call_action("sa", sobj);
		call_action("ra", sobj);
	}
}

void	rotate_to_0(t_obj *sobj)
{
	int	zero;

	zero = find_high_low(sobj->a, 0);
	if (zero > sobj->len_a / 2)
		zero -= sobj->len_a;
	while (zero < 0)
	{
		call_action("rra", sobj);
		zero++;
	}
	while (zero > 0)
	{
		call_action("ra", sobj);
		zero--;
	}
}

void	move_back_a(t_obj *sobj)
{
	int	next_target;

	while (sobj->len_b > 0)
	{
		next_target = -1;
		if (sobj->a->rank == sobj->b->rank + 1)
			next_target = 0;
		if (next_target == -1)
			next_target = find_nxt_higher(sobj->a, sobj->b->rank);
		if (next_target == -1)
			next_target = find_high_low(sobj->a, 0);
		if (next_target > sobj->len_a / 2)
			next_target -= sobj->len_a;
		while (next_target > 0)
		{
			call_action("ra", sobj);
			next_target--;
		}
		while (next_target < 0)
		{
			call_action("rra", sobj);
			next_target++;
		}
		call_action("pa", sobj);
	}
}

int	is_sorted(t_sl *lst)
{
	while (lst->next)
	{
		if (lst->rank > lst->next->rank)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	solve_turk(t_obj *sobj)
{
	int	cheapest;

	if (is_sorted(sobj->a))
		return ;
	if (sobj->len_a > 3)
	{
		call_action("pb", sobj);
		call_action("pb", sobj);
		while (sobj->len_a > 3)
		{
			cheapest = find_cheapest(sobj);
			solve_for_idx(sobj, cheapest);
		}
	}
	sort_three(sobj);
	move_back_a(sobj);
	rotate_to_0(sobj);
}
