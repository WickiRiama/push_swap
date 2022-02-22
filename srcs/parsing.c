/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:52:59 by mriant            #+#    #+#             */
/*   Updated: 2022/02/22 10:29:30 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_checkint(char *s)
{
	int	is_pos;

	if (!s)
		return (1);
	while (ft_isspace(*s))
		s++;
	is_pos = *s - '-';
	if (is_pos == -2 || is_pos == 0)
		s++;
	while (*s == '0')
		s ++;
	if (ft_strlen(s) > 10)
		return (1);
	if (ft_strlen(s) == 10 && ft_atoi(s) < 0 && is_pos != 0)
		return (1);
	else if (ft_strlen(s) == 10 && ft_atoi(s) < 0 && ft_atoi(s) > -2147483648)
		return (1);
	while (*s)
	{
		if (ft_isdigit(*s) == 0)
			return (1);
		s++;
	}
	return (0);
}

int	ft_checkdobble(int n, t_list **pile)
{
	t_list	*item;

	item = *pile;
	while (item)
	{
		if (n == *(int *)(item->content))
			return (1);
		item = item->next;
	}
	return (0);
}

int	ft_checkinput(int ac, char **av, t_list **pile)
{
	int		i;
	void	*content;
	t_list	*next;

	i = 0;
	while (i < ac)
	{
		if (ft_checkint(av[i]) == 1)
			return (1);
		content = malloc(sizeof(int));
		if (!content)
			return (1);
		*(int *)content = ft_atoi(av[i]);
		if (ft_checkdobble(*(int *)content, pile) == 1)
			return (1);
		next = ft_lstnew(content);
		if (!next)
			return (1);
		ft_lstadd_back(pile, next);
		i++;
	}
	return (0);
}

int	ft_parse(int ac, char **av, char ***arg, t_list **pile)
{
	int		i;

	*pile = NULL;
	if (!av)
		return (-1);
	if (ac == 2)
		*arg = ft_split(av[1], ' ');
	else
	{
		*arg = malloc(sizeof(char *) * ac);
		i = 0;
		while (i < ac - 1)
		{
			arg[0][i] = ft_strdup(av[i + 1]);
			if (!arg[0][i])
				return (1);
			i ++;
		}
		arg[0][i] = NULL;
	}
	if (ft_checkinput(ft_tablen(*arg), *arg, pile) == 1)
		return (1);
	return (0);
}
