/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_for_idx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:08:43 by uschmidt          #+#    #+#             */
/*   Updated: 2025/01/20 15:56:59 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_for_idx(t_obj *sobj, int idx_b)
{
	int	idx_a;
	int	cur_rank;

	cur_rank = get_rank(&sobj->b, sobj->len_b, idx_b);
	idx_a = find_nxt_higher(sobj->a, cur_rank);
	ft_printf("solve for b[%d] = %d to a[%d] = %d\n", idx_b, cur_rank, idx_a, get_rank(&sobj->a, sobj->len_a, idx_a));
	if (idx_b > sobj->len_b / 2)
	{
		idx_b -= sobj->len_b;
		idx_a -= sobj->len_a;
		while (idx_b < 0 && idx_a < 0)
		{
			call_action("rrr", sobj);
			idx_b++;
			idx_a++;
		}
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
	}
	else
	{
		while (idx_b > 0 && idx_a > 0)
		{
			call_action("rr", sobj);
			idx_b--;
			idx_a--;
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
	call_action("pa", sobj);
}
