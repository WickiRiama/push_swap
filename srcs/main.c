/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:58:05 by mriant            #+#    #+#             */
/*   Updated: 2022/03/03 13:23:10 by mriant           ###   ########.fr       */
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
	if (ac == 1)
		return (0);
	if (ft_parse(ac, av, &arg, &a_pile) == 1)
	{
		ft_fprintf(2, "Error\n");
		ft_clean(&a_pile, &b_pile, &arg);
		return (1);
	}
	if (ft_sort(&a_pile, &b_pile) == 1)
	{
		ft_fprintf(2, "Error\n");
		ft_clean(&a_pile, &b_pile, &arg);
		return (1);
	}
	ft_clean(&a_pile, &b_pile, &arg);
	return (0);
}
