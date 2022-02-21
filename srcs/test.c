/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:00:59 by mriant            #+#    #+#             */
/*   Updated: 2022/02/21 16:11:38 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_printpile(t_list *list, char *s)
{
	t_list	*temp;

	ft_printf("pile %s : \n", s);
	temp = list;
	while (temp)
	{
		ft_printf("%d\n", *(int *)(temp->content));
		temp = temp->next;
	}
}

void	ft_test_moves(t_list *a_pile, t_list *b_pile)
{
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
}
