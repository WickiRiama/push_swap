/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:58:05 by mriant            #+#    #+#             */
/*   Updated: 2022/02/21 11:35:40 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a_pile;
	t_list	*b_pile;

	a_pile = NULL;
	b_pile = NULL;
	if (ac < 2 || ft_parse(ac, av, &a_pile) == 1)
	{
		ft_fprintf(2, "Error\n");
		ft_lstclear(&a_pile, free);
		return (1);
	}
	ft_printpile(a_pile, "a");
	ft_printpile(b_pile, "b");
	ft_push(&a_pile, &b_pile);
	ft_printpile(a_pile, "a after push");
	ft_printpile(b_pile, "b after push");
	ft_push(&a_pile, &b_pile);
	ft_printpile(a_pile, "a after push");
	ft_printpile(b_pile, "b after push");
	ft_swap(&a_pile);
	ft_printpile(a_pile, "a after swap");
	ft_push(&b_pile, &a_pile);
	ft_printpile(a_pile, "a after push");
	ft_printpile(b_pile, "b after push");
	ft_rotate(&a_pile);
	ft_rotate(&b_pile);
	ft_printpile(a_pile, "a after rotate");
	ft_rrotate(&a_pile);
	ft_rrotate(&a_pile);
	ft_printpile(a_pile, "a after reverse rotate");
	return (0);
}
