/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:18:55 by uschmidt          #+#    #+#             */
/*   Updated: 2025/01/08 11:03:27 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

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
	t_sl	*list_a;
	t_sl	*list_b;

	list_a = NULL;
	list_b = NULL;
	if (argc < 2 || !create_list(&list_a, argc, argv))
		return (log_error());
	ft_printf("LA");
	print_sl(list_a);
	solve_simple(&list_a, &list_b);
	clear_list(&list_a);
	clear_list(&list_b);
	return (0);
}
