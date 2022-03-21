/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:40:57 by mriant            #+#    #+#             */
/*   Updated: 2022/03/21 14:17:00 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap_bonus.h"

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

void	ft_do_op(t_list **a_list, t_list **b_list, char *s)
{
	if (ft_strcmp(s, "sa\n") == 0)
		ft_swap(a_list);
	if (ft_strcmp(s, "sb\n") == 0)
		ft_swap(b_list);
	if (ft_strcmp(s, "pa\n") == 0)
		ft_push(b_list, a_list);
	if (ft_strcmp(s, "pb\n") == 0)
		ft_push(a_list, b_list);
	if (ft_strcmp(s, "ra\n") == 0 || ft_strcmp(s, "rr\n") == 0)
		ft_rotate(a_list);
	if (ft_strcmp(s, "rb\n") == 0 || ft_strcmp(s, "rr\n") == 0)
		ft_rotate(b_list);
	if (ft_strcmp(s, "rra\n") == 0 || ft_strcmp(s, "rrr\n") == 0)
		ft_rrotate(a_list);
	if (ft_strcmp(s, "rrb\n") == 0 || ft_strcmp(s, "rrr\n") == 0)
		ft_rrotate(b_list);
}
