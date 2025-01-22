/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:18:55 by uschmidt          #+#    #+#             */
/*   Updated: 2025/01/22 14:13:50 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "libft/libft.h"

int	handle_error(t_obj *sobj)
{
	if (sobj->a)
		clear_list(&sobj->a);
	if (sobj->b)
		clear_list(&sobj->b);
	free(sobj);
	ft_printf("Error\n");
	return (0);
}

void	print_sl(t_sl *list)
{
	int		start;
	t_sl	*current;

	if (list == NULL)
	{
		ft_printf("LIST EMPTY");
		return ;
	}
	current = list;
	start = 0;
	while (current != list || !start)
	{
		start = 1;
		ft_printf("Val:%d || Rank:%d\n", current->value, current->rank);
		current = current->next;
		if (!current)
			break ;
	}
}

int	main(int argc, char **argv)
{
	t_obj	*sobj;

	sobj = (t_obj *)malloc(sizeof(t_obj));
	if (argc < 2 || !sobj)
		return (handle_error(NULL));
	sobj->a = NULL;
	sobj->b = NULL;
	sobj->len_a = create_list(&sobj->a, argc, argv);
	if (!sobj->len_a)
		return (handle_error(sobj));
	solve_turk(sobj);
	clear_list(&sobj->a);
	clear_list(&sobj->b);
	free(sobj);
	return (0);
}
