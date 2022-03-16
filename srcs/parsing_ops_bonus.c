/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ops_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:48:57 by mriant            #+#    #+#             */
/*   Updated: 2022/03/16 13:34:55 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "push_swap_bonus.h"

int	ft_parse_ops(t_list **ops)
{
	char	*str;
	int		err;

	err = 0;
	str = get_next_line(0);
	while (str)
	{
		if (ft_strcmp(str, "sa\n") && ft_strcmp(str, "sb\n")
			&& ft_strcmp(str, "ss\n") && ft_strcmp(str, "pa\n")
			&& ft_strcmp(str, "pb\n") && ft_strcmp(str, "ra\n")
			&& ft_strcmp(str, "rb\n") && ft_strcmp(str, "rr\n")
			&& ft_strcmp(str, "rra\n") && ft_strcmp(str, "rrb\n")
			&& ft_strcmp(str, "rrr\n"))
			err = 1;
		ft_lstadd_back(ops, ft_lstnew(str));
		str = get_next_line(0);
	}
	if (err == 1)
		return (1);
	return (0);
}
