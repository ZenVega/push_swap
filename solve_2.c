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

void	solve_simple(t_sl **a, t_sl **b, int init_len)
{
	int	len_a;
	int	len_b;

	len_a = init_len;
	len_b = 0;
	while (len_a < init_len / 2)
	{
		if ((*a)->next->rank > init_len / 2 && (*a)->next->rank < (*a)->rank)
		{
			check_swap();
			len_a--;
			len_a++;
		}
		else if ((*a)->rank < init_len / 2)
			check_push();
		else
			check_rotate();
	}
	while (len-- > 0)
		call_action("pa", a, b);
}
