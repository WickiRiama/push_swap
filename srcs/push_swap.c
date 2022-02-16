/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:54:27 by mriant            #+#    #+#             */
/*   Updated: 2022/02/16 17:29:53 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a_pile;
	t_list	*b_pile;

	a_pile = NULL;
	(void) b_pile;
	if (ac < 2 || ft_parse(ac, av, &a_pile) == 1)
		{
			ft_fprintf(2, "Error\n");
			ft_lstclear(&a_pile, NULL);
			return (1);
		}
	return (0);
}