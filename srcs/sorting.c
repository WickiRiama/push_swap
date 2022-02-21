/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:22:26 by mriant            #+#    #+#             */
/*   Updated: 2022/02/21 16:27:25 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_sort2(t_list *list)
{
	if (*(int *)list->content > *(int *)list->next->content)
		ft_printf("sa\n");
}

void	ft_sort3(t_list *list)
{
	if (*(int *)list->content < *(int *)list->next->content)
	{
		if (*(int *)list->next->content > *(int *)list->next->next->content)
		{
			ft_printf("rra\n");
			if (*(int *)list->content < *(int *)list->next->next->content)
				ft_printf("sa\n");
		}
	}
	else
	{
		if (*(int *)list->next->content < *(int *)list->next->next->content)
		{
			if (*(int *)list->content < *(int *)list->next->next->content)
				ft_printf("sa\n");
			else
				ft_printf("ra\n");
		}
		else
			ft_printf("sa\nrra\n");
	}
}
