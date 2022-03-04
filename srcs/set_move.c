/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:01:21 by mriant            #+#    #+#             */
/*   Updated: 2022/03/04 13:48:59 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_minmax(t_moves **moves, t_list *list, int index)
{
	int		min;
	int		max;
	t_list	*temp;

	max = 0;
	min = 2147483647;
	temp = list;
	while (temp)
	{
		if (max < ((t_content *)temp->content)->index)
			max = ((t_content *)temp->content)->index;
		if (min > ((t_content *)temp->content)->index)
			min = ((t_content *)temp->content)->index;
		temp = temp->next;
	}
	if (index < min || index > max)
	{
		while (((t_content *)list->content)->index != min)
		{
			(*moves)->ra ++;
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
		(*moves)->ra ++;
		last = ((t_content *)list->content)->index;
		list = list->next;
		first = ((t_content *)list->content)->index;
	}
}

void	ft_clean_moves(t_moves **moves, int i)
{
	if (i == 1)
	{
		(*moves)->ra = (*moves)->ra - (*moves)->rr;
		(*moves)->rb = (*moves)->rb - (*moves)->rr;
		(*moves)->rrr = 0;
	}
	if (i == 2)
	{
		(*moves)->rrb = (*moves)->rrb - (*moves)->rrr;
		(*moves)->rra = (*moves)->rra - (*moves)->rrr;
		(*moves)->rr = 0;
	}
	if (i == 1 || i == 3)
		(*moves)->rra = 0;
	if (i == 1 || i == 4)
		(*moves)->rrb = 0;
	if (i == 2 || i == 4)
		(*moves)->ra = 0;
	if (i == 2 || i == 3)
		(*moves)->rb = 0;
	if (i == 3 || i == 4)
	{
		(*moves)->rr = 0;
		(*moves)->rrr = 0;
	}
}

void	ft_setscore(t_moves **moves)
{
	int	s1;
	int	s2;
	int	s3;
	int	s4;

	s1 = (*moves)->ra + (*moves)->rb - (*moves)->rr;
	s2 = (*moves)->rra + (*moves)->rrb - (*moves)->rrr;
	s3 = (*moves)->ra + (*moves)->rrb;
	s4 = (*moves)->rra + (*moves)->rb;
	(*moves)->score = ft_min(ft_min(s1, s2), ft_min(s3, s4));
	if ((*moves)->score == s1)
		ft_clean_moves(moves, 1);
	else if ((*moves)->score == s2)
		ft_clean_moves(moves, 2);
	else if ((*moves)->score == s3)
		ft_clean_moves(moves, 3);
	else if ((*moves)->score == s4)
		ft_clean_moves(moves, 4);
}

t_moves	*ft_setmove(int index, t_list *a_list, t_list *b_list, int i)
{
	t_moves	*moves;

	moves = malloc(sizeof(t_moves));
	if (!moves)
		return (NULL);
	moves->rb = i;
	moves->rrb = ft_lstsize(b_list) - i;
	moves->ra = 0;
	if (ft_minmax(&moves, a_list, index) == 0)
		ft_firstlast(&moves, a_list, index);
	moves->rra = ft_lstsize(a_list) - moves->ra;
	moves->rr = ft_min(moves->ra, moves->rb);
	moves->rrr = ft_min(moves->rra, moves->rrb);
	ft_setscore(&moves);
	return (moves);
}
