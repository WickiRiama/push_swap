/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:18:46 by mriant            #+#    #+#             */
/*   Updated: 2022/03/16 13:09:06 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

typedef struct s_content
{
	int	value;
	int	index;
}				t_content;
int		ft_checksorted(t_list *list, long int shift);
void	ft_clean_ps(t_list **a_pile, char ***tab, t_list **ops);
void	ft_do_op(t_list **list_start, t_list **list_end, char *s);
void	ft_initindex(t_list *list);
int		ft_parse_args(int ac, char **av, char ***arg, t_list **pile);
int		ft_parse_ops(t_list **ops);
void	ft_printpile(t_list *a_list, t_list *b_list);
int		ft_tablen(char **tab);

#endif
