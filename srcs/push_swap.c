/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:58:17 by mriant            #+#    #+#             */
/*   Updated: 2022/02/28 17:26:53 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_swap(t_list **lst)
{
	t_list	*temp;

	if (!(*lst) || !(*lst)->next)
		return ;
	temp = (*lst)->next;
	(*lst)->next = temp->next;
	temp->next = *lst;
	*lst = temp;
}

void	ft_push(t_list **src, t_list **dest)
{
	t_list	*temp;

	if (!(*src))
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
}

void	ft_rotate(t_list **lst)
{
	t_list	*temp;
	t_list	*last;

	if (!(*lst) || !(*lst)->next)
		return ;
	temp = *lst;
	last = ft_lstlast(*lst);
	*lst = (*lst)->next;
	last->next = temp;
	temp->next = NULL;
}

void	ft_rrotate(t_list **lst)
{
	t_list	*temp;
	t_list	*last;

	if (!*(lst) || !(*lst)->next)
		return ;
	last = ft_lstlast(*lst);
	temp = *lst;
	while (temp->next != last)
		temp = temp->next;
	temp->next = NULL;
	last->next = *lst;
	*lst = last;
}
