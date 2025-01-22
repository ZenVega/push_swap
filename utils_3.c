/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:32:24 by uschmidt          #+#    #+#             */
/*   Updated: 2025/01/22 11:50:44 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	abs_dst(int a, int b)
{
	a -= b;
	if (a < 0)
		a = -a;
	return (a);
}

int	get_abs(int val)
{
	if (val < 0)
		return (-val);
	return (val);
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

int	find_nxt_higher(t_sl *lst, int target)
{
	int	i;
	int	closest;
	int	closest_i;

	i = 0;
	closest = INT_MAX;
	closest_i = -1;
	while (lst)
	{
		if (lst->rank > target && lst->rank - target < closest)
		{
			closest = lst->rank - target;
			closest_i = i;
		}
		lst = lst->next;
		i++;
	}
	return (closest_i);
}

int	find_nxt_lower(t_sl *lst, int target)
{
	int	i;
	int	closest;
	int	closest_i;

	i = 0;
	closest = INT_MAX;
	while (lst)
	{
		if (lst->rank < target && target - lst->rank < closest)
		{
			closest = target - lst->rank;
			closest_i = i;
		}
		lst = lst->next;
		i++;
	}
	return (closest_i);
}
