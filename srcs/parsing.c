/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:52:59 by mriant            #+#    #+#             */
/*   Updated: 2022/02/16 17:13:24 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_checknum(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_checkdobble(int n, t_list **pile)
{
	t_list *item;

	item = *pile;
	while (item)
	{
		if (n == *(int *)(item->content))
			return (1);
		item = item->next;
	}
	return (0);
}

int ft_parse(int ac, char **av, t_list **pile)
{
	int		i;
	int		content;
	t_list	*next;

	*pile = NULL;
	if (!av)
		return (-1);
	i = 1;
	while (i < ac)
	{
		if (ft_checknum(av[i]) == 1)
			return (1);
		content = ft_atoi(av[i]);
		if (ft_checkdobble(content, pile) == 1)
			return (1);
		next = ft_lstnew(&content);
		if (!next)
			return (1);
		ft_lstadd_back(pile, next);
		i++;
	}
	return (0);
}