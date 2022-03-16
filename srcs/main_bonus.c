/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:20:30 by mriant            #+#    #+#             */
/*   Updated: 2022/03/16 13:27:59 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap_bonus.h"

int	ft_do_sort(t_list *ops, t_list **a_list)
{
	t_list	*b_list;
	char	*op;

	b_list = NULL;
	while (ops)
	{
		op = (char *)ops->content;
		ft_do_op(a_list, &b_list, op);
		ops = ops->next;
	}
	if (b_list || ft_checksorted(*a_list, -1) == 0)
	{
		ft_lstclear(&b_list, free);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*a_pile;
	t_list	*ops;
	char	**arg;

	a_pile = NULL;
	ops = NULL;
	arg = NULL;
	if (ac == 1)
		return (0);
	if (ft_parse_args(ac, av, &arg, &a_pile) == 1 || ft_parse_ops(&ops) == 1)
	{
		ft_fprintf(2, "Error\n");
		ft_clean_ps(&a_pile, &arg, &ops);
		return (1);
	}
	if (ft_do_sort(ops, &a_pile) == 1)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	ft_clean_ps(&a_pile, &arg, &ops);
	return (0);
}
