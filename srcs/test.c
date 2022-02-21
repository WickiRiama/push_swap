/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:00:59 by mriant            #+#    #+#             */
/*   Updated: 2022/02/21 11:17:06 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_printpile(t_list *list, char *s)
{
	t_list *temp;
	
	ft_printf("pile %s : \n", s);
	temp = list;
	while(temp)
	{
		ft_printf("%d\n", *(int *)(temp->content));
		temp = temp->next;
	}
}