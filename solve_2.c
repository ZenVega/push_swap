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

void	check_rotate(t_obj *sobj)
{
	int		nxt;
	int		nxt_b;
	int		i;
	int		dif;

	nxt = 0;
	nxt_b = sobj->len_a - 1;
	while (get_rank(&sobj->a, sobj->len_a, nxt) >= sobj->len_a / 2)
		nxt++;
	ft_printf("NXT+: %d\n", nxt);
	ft_printf("NXT-: %d\n", nxt_b);
	while (nxt_b > 0
		&& get_rank(&sobj->a, sobj->len_a, nxt_b) >= sobj->len_a / 2)
		nxt_b--;
	ft_printf("NXT-: %d\n", nxt_b);
	nxt_b = nxt_b - sobj->len_a;
	if (!nxt || nxt_b > -nxt)
		nxt = nxt_b;
	nxt_b = get_rank(&sobj->a, sobj->len_a, nxt);
	i = 0;
	print_sl(sobj->b);
	if (nxt < 0)
	{
		while (i >= nxt)
		{
			dif = nxt_b - get_rank(&sobj->b, sobj->len_b, i);
			if (dif == 1 || dif == -1)
				break ;
			i--;
		}
	}
	else
	{
		while (i <= nxt)
		{
			dif = nxt_b - get_rank(&sobj->b, sobj->len_b, i);
			if (dif == 1 || dif == -1)
				break ;
			i++;
		}
	}
	ft_printf("ShiftIndex: %d\n", i);
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
			call_action("pb", sobj);
		else
			check_rotate(sobj);
	}
	call_action("pb", sobj);
	call_action("pb", sobj);
	call_action("pb", sobj);
	call_action("pb", sobj);
	ft_printf("A:\n");
	print_sl(sobj->a);
	ft_printf("B:\n");
	print_sl(sobj->b);
	check_rotate(sobj);
}
