/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:01:21 by mriant            #+#    #+#             */
/*   Updated: 2022/03/03 12:01:24 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_minmax(t_moves **moves, t_list *list, int index)
{
	int	min;
	int	max;

	*max = 0;
	*min = 2147483647;
	while (list)
	{
		if (*max < ((t_content *)list->content)->index)
			*max = ((t_content *)list->content)->index;
		if (*min > ((t_content *)list->content)->index)
			*min = ((t_content *)list->content)->index;
		list = list->next;
	}
	if (index < min || index > max)
	{
		while (((t_content *)list->content)->index != min)
		{
			(*moves)->rb ++;
			list = list->next;
		}
		return (1);
	}
	return (0);
}

void	ft_firstlast(t_moves **moves, t_list *list, int index)
{
	int	first;
	int	last;

	last = ((t_content *)ft_lstlast(list)->content)->index;
	first = ((t_content *)list->content)->index;
	while (index < last || index > first)
	{
		(*moves)->rb ++;
		last = ((t_content *)list->content)->index;
		list = list->next;
		first = ((t_content *)list->content)->index;
	}
}

void	ft_optimized_r(t_moves **moves)
{
	(*moves)->rr = ft_min((*moves)->ra, (*moves)->rb);
	(*moves)->rrr = ft_min((*moves)->rra, (*moves)->rrb);
	if (ft_min((*moves)->ra, (*moves)->rb) == (*moves)->ra)
		(*moves)->ra = 0;
	else
		(*moves)->rb = 0;
	if (ft_min((*moves)->rra, (*moves)->rrb) == (*moves)->rra)
		(*moves)->rra = 0;
	else
		(*moves)->rrb = 0;
}

void	ft_setscore(t_moves **moves)
{
	int	s1;
	int	s2;
	int	s3;
	int	s4;

	s1 = (*moves)->ra + (*moves)->rb + (*moves)->rr;
	s2 = (*moves)->rra + (*moves)->rrb + (*moves)->rrr;
	s3 = (*moves)->ra + (*moves)->rrb;
	s4 = (*moves)->rra + (*moves)->rb;
	(*moves)->score = ft_min(ft_min(s1, s2), ft_min(s3, s4));
}

t_moves	*ft_setmove(int index, t_list *list, int i)
{
	t_moves	*moves;
	int		len;

	len = ft_lstsize(list);
	moves = malloc(sizeof(t_moves));
	if (!moves)
		return (NULL);
	moves->ra = i;
	moves->rra = len - i;
	moves->rb = 0;
	if (ft_minmax(&moves, list, index) == 0)
		ft_firstlast(&moves, list, index);
	moves->rrb = len - moves->rb;
	ft_optimized_r(&moves);
	ft_setscore(&moves);
	return (moves);
}
