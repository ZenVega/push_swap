/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:55:01 by uschmidt          #+#    #+#             */
/*   Updated: 2025/01/09 13:12:31 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	check_swap(t_obj *sobj)
{
	if (sobj->len_b >= 2 && sobj->b->rank < sobj->b->next->rank)
		call_action("ss", sobj);
	else
		call_action("sa", sobj);
}

int	abs_dst(int a, int b)
{
	a -= b;
	if (a < 0)
		a = -a;
	return (a);
}

int	find_closest(t_obj *sobj, int val, int dir)
{
	int	i;
	int	min_dif;
	int	min_i;
	int	current;

	i = 0;
	min_dif = INT_MAX;
	if (dir < 0)
	{
		while (i >= dir)
		{
			current = get_rank(&sobj->b, sobj->len_b, i);
			if (abs_dst(val, current) < min_dif)
			{
				min_i = i;
				min_dif = abs_dst(val, current);
			}
			i--;
		}
	}
	else
	{
		while (i <= dir)
		{
			current = get_rank(&sobj->b, sobj->len_b, i);
			if (abs_dst(val, current) < min_dif)
			{
				min_i = i;
				min_dif = abs_dst(val, current);
			}
			i++;
		}
	}
	return (min_i);
}

void	check_rotate(t_obj *sobj, int target)
{
	int		nxt;
	int		nxt_back;

	nxt = 0;
	nxt_back = sobj->len_a - 1;
	while (get_rank(&sobj->a, sobj->len_a, nxt) >= target)
		nxt++;
	while (nxt_back > 0
		&& get_rank(&sobj->a, sobj->len_a, nxt_back) >= target)
		nxt_back--;
	nxt_back = nxt_back - sobj->len_a;
	if (!nxt || nxt_back > -nxt)
		nxt = nxt_back;
	nxt_back = get_rank(&sobj->a, sobj->len_a, nxt);
	nxt_back = find_closest(sobj, nxt_back, nxt);
	if (nxt > 0)
	{
		while (nxt > 0)
		{
			if (nxt_back > 0)
			{
				call_action("rr", sobj);
				nxt_back--;
			}
			else
				call_action("ra", sobj);
			nxt--;
		}
	}
	else
	{
		while (nxt < 0)
		{
			if (nxt_back < 0)
			{
				call_action("rrr", sobj);
				nxt_back++;
			}
			else
				call_action("rra", sobj);
			nxt++;
		}
	}
}

void	solve_50_50(t_obj *sobj)
{
	int	init_len;
	int	i;

	i = 0;
	init_len = sobj->len_a;
	call_action("pb", sobj);
	call_action("pb", sobj);
//	PUSH to b either 50% or all but three
	while (sobj->len_b < init_len - 3)
	{
		if (sobj->a->rank < init_len - 3)
			call_action("pb", sobj);
		else if (sobj->a->next->rank < sobj->a->rank)
			check_swap(sobj);
		else
			check_rotate(sobj, init_len - 3);
		i++;
	}
	// if 50%
	// sort_both();
	//
	// if all but 3
	// sort_b_back
	ft_printf("A:\n");
	print_sl(sobj->a);
	ft_printf("B:\n");
	print_sl(sobj->b);
}
