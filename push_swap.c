/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:18:55 by uschmidt          #+#    #+#             */
/*   Updated: 2024/12/17 16:49:55 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "ft_printf/ft_printf.h"

int	main(int argc, char **argv)
{
	int		i;
	t_list	*list_a;
	t_list	*current;
	int		*as_int;
	int		current_int;

	list_a = NULL;
	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		as_int = (int *)malloc(sizeof(int));
		if (!as_int)
		{
			ft_lstclear(&list_a, free);
			return (1);
		}
		*as_int = ft_atoi(argv[i]);
		ft_lstadd_back(&list_a, ft_lstnew(as_int));
		i++;
	}

	current = list_a;
	i = 0;
	while (current)
	{
		current_int = *(int *)current->content;
		ft_printf("-%d-\n", current_int);
		current = current->next;
	}
	ft_lstclear(&list_a, free);
	return (0);
}
