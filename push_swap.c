/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:18:55 by uschmidt          #+#    #+#             */
/*   Updated: 2025/01/03 18:33:41 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void	clear_circular_list(t_list **list)
{
	t_list	*current;
	t_list	*next;
	int		start;

	start = 0;
	next = *list;
	while (next != *list || !start)
	{
		start = 1;
		current = next;
		next = next->next;
		free(current->content);
		free(current);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		*as_int;
	t_list	*list_a;
	t_list	*list_b;
	t_list	*current;

	list_a = NULL;
	list_b = NULL;
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
	current = ft_lstlast(list_a);
	current->next = list_a;
	push(&list_a, &list_b);
	ft_printf("LA\n");
	print_list(list_a);
	ft_printf("LB\n");
	print_list(list_b);
	clear_circular_list(&list_a);
	clear_circular_list(&list_b);
	return (0);
}
