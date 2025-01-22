/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_for_idx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:08:43 by uschmidt          #+#    #+#             */
/*   Updated: 2025/01/22 11:50:51 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_rotate(int *idx_a, int *idx_b, t_obj *sobj)
{
	while (*idx_b < 0 && *idx_a < 0)
	{
		call_action("rrr", sobj);
		*idx_b += 1;
		*idx_a += 1;
	}
	while (*idx_b > 0 && *idx_a > 0)
	{
		call_action("rr", sobj);
		*idx_b -= 1;
		*idx_a -= 1;
	}
}

void	rotate_to_idx(int idx_a, int idx_b, t_obj *sobj)
{
	double_rotate(&idx_a, &idx_b, sobj);
	while (idx_b < 0)
	{
		call_action("rrb", sobj);
		idx_b++;
	}
	while (idx_a < 0)
	{
		call_action("rra", sobj);
		idx_a++;
	}
	while (idx_b > 0)
	{
		call_action("rb", sobj);
		idx_b--;
	}
	while (idx_a > 0)
	{
		call_action("ra", sobj);
		idx_a--;
	}
}

void	solve_for_idx(t_obj *sobj, int idx_a)
{
	int	idx_b;
	int	lowest_in_b;
	int	cur_rank;

	cur_rank = get_rank(&sobj->a, sobj->len_a, idx_a);
	idx_b = find_nxt_higher(sobj->a, cur_rank);
	lowest_in_b = get_rank(&sobj->b, sobj->len_b, find_high_low(sobj->b, 0));
	if (lowest_in_b > cur_rank)
		idx_b = find_high_low(sobj->b, 1);
	else
		idx_b = find_nxt_lower(sobj->b, cur_rank);
	if (idx_a > sobj->len_a / 2)
		idx_a -= sobj->len_a;
	if (idx_b > sobj->len_b / 2)
		idx_b -= sobj->len_b;
	rotate_to_idx(idx_a, idx_b, sobj);
	call_action("pb", sobj);
}
