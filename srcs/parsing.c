/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:52:59 by mriant            #+#    #+#             */
/*   Updated: 2022/02/28 19:16:44 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_checkint(char *s)
{
	char	*max;

	max = "2147483647";
	if (!s)
		return (1);
	while (ft_isspace(*s))
		s++;
	if (*s == '+' && *(s + 1) != '\0')
		s++;
	else if (*s == '-' && *(s + 1) != '\0')
	{
		max = "2147483648";
		s++;
	}
	while (*s == '0')
		s ++;
	if (ft_strlen(s) > 10 || (ft_strlen(s) == 10 && ft_strncmp(s, max, 10) > 0))
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

void	ft_setrank(t_list *pile)
{
	int	i;
	int	min;
	t_list	*temp;

	i = 0;
	temp = pile;
	while (temp)
	{
		temp->index = -1;
		temp = temp->next;
	}
	while (i < ft_lstsize(pile))
	{
		temp = pile;
		min = 2147483647;
		while (temp)
		{
			if (temp->index == -1 && *(int *)temp->content < min)
				min = *(int *)temp->content;
			temp = temp->next;
		}
		temp = pile;
		while (*(int *)temp->content != min)
			temp = temp->next;
		temp->index = i;
		i++;
	}
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
	ft_setrank(*pile);
	return (0);
}
