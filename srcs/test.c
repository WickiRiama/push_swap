/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:00:59 by mriant            #+#    #+#             */
/*   Updated: 2022/03/04 13:46:30 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_printpile(t_list *a_list, t_list *b_list)
{
	t_list	*temp;

	ft_printf("pile a : \n");
	temp = a_list;
	while (temp)
	{
		ft_printf("%d ", *(int *)(temp->content));
		temp = temp->next;
	}
	ft_printf("\npile b : \n");
	temp = b_list;
	while (temp)
	{
		ft_printf("%d ", *(int *)(temp->content));
		temp = temp->next;
	}
	ft_printf("\n");
}
