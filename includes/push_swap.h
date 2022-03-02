/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:53:52 by mriant            #+#    #+#             */
/*   Updated: 2022/03/02 10:28:02 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_content
{
	int	value;
	int	index;
}				t_content;
int		ft_checkb(t_list *list, long int shift);
int		ft_checksorted(t_list *list, long int shift);
void	ft_clean(t_list **a_pile, t_list **b_pile, char ***tab);
void	ft_initindex(t_list *list);
void	ft_insert_a(t_list **a_list, t_list **b_list);
int		ft_parse(int ac, char **av, char ***arg, t_list **pile);
void	ft_printpile(t_list *list, char *s);
void	ft_push(t_list **src, t_list **dest);
void	ft_radix(t_list **a_list, t_list **b_list);
void	ft_rotate(t_list **lst);
void	ft_rrotate(t_list **lst);
int		ft_sort(t_list **a_list, t_list **b_list);
void	ft_sort2(t_list *list);
void	ft_sort3(t_list *list);
void	ft_swap(t_list **lst);
int		ft_tablen(char **tab);

#endif
