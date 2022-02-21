/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:58:05 by mriant            #+#    #+#             */
/*   Updated: 2022/02/21 20:23:09 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a_pile;
	t_list	*b_pile;
	char	**arg;
	int		len;

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
	len = ft_tablen(arg);
	if (len == 2)
		ft_sort2(a_pile);
	if (len == 3)
		ft_sort3(a_pile);
	else if (ft_sort(&a_pile, &b_pile))
	{
		ft_fprintf(2, "Error\n");
		ft_clean(&a_pile, &b_pile, &arg);
		return (1);
	}
	ft_clean(&a_pile, &b_pile, &arg);
	return (0);
}
