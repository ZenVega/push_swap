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

void	call_action(char *id, t_obj *sobj)
{
	if (*id == 's')
		swap_list(sobj, id);
	else if (*id == 'p')
		push_list(sobj, id);
	else if (*id == 'r')
		rotate_list(sobj, id);
	else
		ft_printf("Wrong action code");
}

void	swap_list(t_obj *sobj, char *id)
{
	if (id[1] == 'a')
		swap(&sobj->a);
	else if (id[1] == 'b')
		swap(&sobj->b);
	else if (id[1] == 's')
	{
		swap(&sobj->a);
		swap(&sobj->b);
	}
	ft_printf("%s\n", id);
}

void	rotate_list(t_obj *sobj, char *id)
{
	if (id[1] == 'r')
	{
		if (id[2] == 'a')
			rotate(&sobj->a, -1);
		else if (id[2] == 'b')
			rotate(&sobj->b, -1);
		else
		{
			rotate(&sobj->a, -1);
			rotate(&sobj->b, -1);
		}
	}
	else
	{
		if (id[1] == 'a')
			rotate(&sobj->a, 1);
		else if (id[1] == 'b')
			rotate(&sobj->b, 1);
		else
		{
			rotate(&sobj->a, 1);
			rotate(&sobj->b, 1);
		}
	}
	ft_printf("%s\n", id);
}

void	push_list(t_obj *sobj, char *id)
{
	if (id[1] == 'a')
	{
		push(&sobj->a, &sobj->b);
		sobj->len_a++;
		sobj->len_b--;
	}
	else
	{
		push(&sobj->b, &sobj->a);
		sobj->len_b++;
		sobj->len_a--;
	}
	ft_printf("%s\n", id);
}
