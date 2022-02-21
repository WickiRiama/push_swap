/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:58:05 by mriant            #+#    #+#             */
/*   Updated: 2022/02/21 16:01:37 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a_pile;
	t_list	*b_pile;
	char	**arg;

	a_pile = NULL;
	b_pile = NULL;
	arg = NULL;
	if (ac < 2 || ft_parse(ac, av, &arg, &a_pile) == 1)
	{
		ft_fprintf(2, "Error\n");
		ft_lstclear(&a_pile, free);
		return (1);
	}
	if (ft_tablen(arg) == 3)
		ft_sort3(a_pile);
	return (0);
}
