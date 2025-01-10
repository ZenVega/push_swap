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

void	check_swap(t_obj *sobj)
{
	if (sobj->len_b >= 2 && sobj->b->rank < sobj->b->next->rank)
		call_action("ss", sobj);
	else
		call_action("sa", sobj);
}

int	get_next_in_list(t_sl *init_list, int init_len, int dir)
{
	int		next_forward;
	int		next_back;
	t_sl	*a;

	a = init_list;
	next_forward = 0;
	if (dir >= 0)
	{
		while (a->rank >= init_len / 2)
		{
			next_forward++;
			a = a->next;
		}
	}
	if (dir <= 0)
	{
		a = init_list;
		next_back = init_len;
		while (get_rank_index(&a, next_back) >= init_len / 2)
			next_back--;
	}
	if (next_back - init_len > -next_forward)
		return (next_back - init_len - 1);
	return (next_forward);
}

void	check_rotate(t_obj *sobj, int init_len)
{
	int		next_in_a;
	int		next_in_b;

	next_in_a = get_next_in_list(sobj->a, init_len, 0);
	ft_printf("NEXT_IN_A %d\n", next_in_a);
	//TODO: Error in list b???
	next_in_b = get_next_in_list(sobj->b, init_len, next_in_a);
	ft_printf("NEXT_IN_B %d\n", next_in_b);
}

void	solve_50_50(t_obj *sobj)
{
	int	init_len;

	init_len = sobj->len_a;
	while (0 && sobj->len_b < init_len / 2)
	{
		if (sobj->a->next->rank > init_len / 2
			&& sobj->a->next->rank < sobj->a->rank)
			check_swap(sobj);
		else if (sobj->a->rank < init_len / 2)
			call_action("pa", sobj);
		else
			check_rotate(sobj, init_len);
	}
	call_action("pa", sobj);
	call_action("pa", sobj);
	check_rotate(sobj, init_len);
}
