/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:27:35 by mriant            #+#    #+#             */
/*   Updated: 2022/03/04 12:02:35 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_moves	*ft_chosepush(t_list **a_list, t_list **b_list)
{
	t_moves	*moves;
	t_moves	*tp_mvs;
	t_list	*temp;
	int		i;

	i = 0;
	moves = NULL;
	temp = *b_list;
	while (temp)
	{
		tp_mvs = ft_setmove(((t_content *)temp->content)->index, *a_list,
				*b_list, i);
		if (!tp_mvs)
			return (NULL);
		if (!moves || moves->score > tp_mvs->score)
		{
			free(moves);
			moves = tp_mvs;
		}
		else
			free(tp_mvs);
		i++;
		temp = temp->next;
	}
	return (moves);
}

void	ft_do_rmoves(t_moves **moves, t_list **a_list, t_list **b_list)
{
	while ((*moves)->rr)
	{
		ft_do_op(b_list, a_list, "rr");
		(*moves)->rr--;;
	}
	while ((*moves)->ra)
	{
		ft_do_op(a_list, NULL, "ra");
		(*moves)->ra--;
	}
	while ((*moves)->rb)
	{
		ft_do_op(b_list, NULL, "rb");
		(*moves)->rb = (*moves)->rb - 1;
	}
}

void	ft_do_rrmoves(t_moves **moves, t_list **a_list, t_list **b_list)
{
	while ((*moves)->rrr)
	{
		ft_do_op(b_list, a_list, "rrr");
		(*moves)->rrr--;
	}
	while ((*moves)->rra)
	{
		ft_do_op(a_list, NULL, "rra");
		(*moves)->rra--;
	}
	while ((*moves)->rrb)
	{
		ft_do_op(b_list, NULL, "rrb");
		(*moves)->rrb--;
	}
}

char	*ft_last_rotate(t_list *list)
{
	t_list	*temp;
	int		min;
	int		i;
	int		imin;

	i = 0;
	min  = ((t_content *)list->content)->index;
	temp = list;
	while(temp)
	{
		if (((t_content *)temp->content)->index < min)
		{
			min = ((t_content *)temp->content)->index;
			imin = i;
		}
		temp = temp->next;
		i++;
	}
	if (imin <= ft_lstsize(list) - imin)
		return ("ra");
	else
		return ("rra");
}

int	ft_insert_b(t_list **a_list, t_list **b_list)
{
	t_moves	*moves;
	char	*last_r;

	while (*b_list)
	{
		moves = ft_chosepush(a_list, b_list);
		if (!moves)
			return (1);
		ft_do_rmoves(&moves, a_list, b_list);
		ft_do_rrmoves(&moves, a_list, b_list);
		ft_do_op(b_list, a_list, "pa");
	}
	last_r = ft_last_rotate(*a_list);
	while (ft_checksorted(*a_list, -1) == 0)
		ft_do_op(a_list, NULL, last_r);
	free(moves);
	return (0);
}
