/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:08:20 by uschmidt          #+#    #+#             */
/*   Updated: 2025/01/09 13:10:37 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_simple(t_obj *sobj)
{
	int		i;

	i = 0;
	while (i < sobj->len_a)
	{
		while (sobj->a->rank != i)
			call_action("ra", sobj);
		call_action("pb", sobj);
		i++;
	}
	while (sobj->len_a-- > 0)
		call_action("pa", sobj);
}
