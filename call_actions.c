/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:04:04 by uschmidt          #+#    #+#             */
/*   Updated: 2025/01/06 14:07:48 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	call_action(char	*ID, t_sl **a, t_sl **b)
{
	if (!ft_strncmp("sa", ID, 2))
		swap_list(a, NULL, 'a');
	else if (!ft_strncmp("sb", ID, 2))
		swap_list(b, NULL, 'b');
	else if (!ft_strncmp("ss", ID, 2))
		swap_list(a, b, 's');
	else if (!ft_strncmp("pa", ID, 2))
		push_list(a, b, 'a');
	else if (!ft_strncmp("pb", ID, 2))
		push_list(b, a, 'b');
	else if (!ft_strncmp("rra", ID, 3))
		rotate_list(a, NULL, 'a', -1);
	else if (!ft_strncmp("rrb", ID, 3))
		rotate_list(b, NULL, 'b', -1);
	else if (!ft_strncmp("rrr", ID, 3))
		rotate_list(a, b, 'r', -1);
	else if (!ft_strncmp("ra", ID, 2))
		rotate_list(a, NULL, 'a', 1);
	else if (!ft_strncmp("rb", ID, 2))
		rotate_list(b, NULL, 'b', 1);
	else if (!ft_strncmp("rr", ID, 2))
		rotate_list(a, b, 'r', 1);
	else
		ft_printf("Wrong action code");
}

void	swap_list(t_sl **a, t_sl **b, char list_id)
{
	swap(a);
	if (list_id == 's')
		swap(b);
	ft_printf("s%c\n", list_id);
}

void	rotate_list(t_sl **a, t_sl **b, char list_id, int dir)
{
	rotate(a, dir);
	if (list_id == 'r')
		rotate(b, dir);
	if (dir == -1)
		ft_printf("rr%c\n", list_id);
	else
		ft_printf("r%c\n", list_id);
}

void	push_list(t_sl **dest, t_sl	**src, char list_id)
{
	push(dest, src);
	ft_printf("p%c\n", list_id);
}
