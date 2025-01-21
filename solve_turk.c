/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:55:01 by uschmidt          #+#    #+#             */
/*   Updated: 2025/01/20 15:55:17 by uschmidt         ###   ########.fr       */
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

int	find_in_list(t_sl **list, int val)
{
	int		i;
	t_sl	*lst;

	i = 0;
	lst = *list;
	while (lst)
	{
		if (lst->rank == val)
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}

int	find_high_low(t_sl *lst, int high)
{
	int		ret_i;
	int		i;
	int		cur;
	t_sl	*next;

	i = 0;
	ret_i = 0;
	next = lst;
	cur = lst->rank;
	while (next)
	{
		if (high)
		{
			if (next->rank > cur)
			{
				ret_i = i;
				cur = next->rank;
			}
		}
		else
		{
			if (next->rank < cur)
			{
				ret_i = i;
				cur = next->rank;
			}
		}
		next = next->next;
		i++;
	}
	return (ret_i);
}

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

void	solve_turk(t_obj *sobj)
{
	int	cheapest;

	call_action("pb", sobj);
	call_action("pb", sobj);
	while (sobj->len_a > 3)
	{
		//ft_printf("A:\n");
		//print_sl(sobj->a);
		//ft_printf("B:\n");
		//print_sl(sobj->b);
		cheapest = find_cheapest_turk(sobj);
		solve_for_idx_turk(sobj, cheapest);
	}
	move_back_a(sobj);
	rotate_to_0(sobj);
}
