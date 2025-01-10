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

int	get_next_in_a(t_sl *init_a, int init_len)
{
	int		next_in_a;
	int		current;
	t_sl	*a;

	a = init_a;
	next_in_a = 0;
	while (a->rank >= init_len / 2)
	{
		next_in_a++;
		a = a->next;
	}
	a = init_a;
	current = init_len;
	while (get_rank_index(&a, current) >= init_len / 2)
		current--;
	if (init_len - current < next_in_a)
		next_in_a = current;
	return (next_in_a);
}

void	check_rotate(t_obj *sobj, int init_len)
{
	int		next_in_a;

	next_in_a = get_next_in_a(sobj->a, init_len);
	ft_printf("NEXT_IN_A %d\n", next_in_a);
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
	check_rotate(sobj, init_len);
}
