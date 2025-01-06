/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:04:04 by uschmidt          #+#    #+#             */
/*   Updated: 2025/01/06 11:51:04 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	call_action(char	*ID, t_list **a, t_list **b)
{
	if (!ft_strncmp("sa", ID, 2))
		swap_list(a, 'a');
	else if (!ft_strncmp("sb", ID, 2))
		swap_list(b, 'b');
	else if (!ft_strncmp("ra", ID, 2))
		rotate_list(a, 'a', 1);
	else if (!ft_strncmp("rb", ID, 2))
		rotate_list(b, 'b', 1);
	else if (!ft_strncmp("rra", ID, 2))
		rotate_list(a, 'a', -1);
	else if (!ft_strncmp("rrb", ID, 2))
		rotate_list(b, 'b', -1);
}

void	swap_list(t_list **list, char list_id)
{
	swap(list);
	ft_printf("s%c\n", list_id);
}

void	rotate_list(t_list **list, char list_id, int dir)
{
	rotate(list, dir);
	if (dir == -1)
		ft_printf("rr%c\n", list_id);
	else
		ft_printf("r%c\n", list_id);
}
