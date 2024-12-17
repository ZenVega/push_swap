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

int	main(int argc, char **argv)
{
	int		i;
	//t_list	**list_a;
	//int		as_int;


	if (argc < 1)
		return (0);
	//list_a = (t_list **)malloc(sizeof(t_list) * 10);
	i = 0;
	while (i++ < argc)
	{
		printf("%s\n", argv[i]);
		//as_int = ft_atoi(split_str[i]);
		//ft_lstadd_back(list_a, ft_lstnew(&as_int));
	}
	//i = 0;
	//while (list_a[i++])
	//{
	//	int current_int = *(int *)list_a[i]->content;
	//	printf("%d\n", current_int);
	//}
	//ft_lstclear(list_a, free);
	i = 0;
	return (0);

}
