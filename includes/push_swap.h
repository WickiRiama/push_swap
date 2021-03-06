/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:53:52 by mriant            #+#    #+#             */
/*   Updated: 2022/03/04 12:44:44 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_content
{
	int	value;
	int	index;
}				t_content;
typedef struct s_moves
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	rr;
	int	rrr;
	int	score;
}				t_moves;
int		ft_checkb(t_list *list, long int shift);
int		ft_checksorted(t_list *list, long int shift);
void	ft_clean(t_list **a_pile, t_list **b_pile, char ***tab);
void	ft_clean_moves(t_moves **moves, int i);
void	ft_do_op(t_list **list_start, t_list **list_end, char *s);
void	ft_initindex(t_list *list);
void	ft_insert_a(t_list **a_list, t_list **b_list);
int		ft_insert_b(t_list **a_list, t_list **b_list);
int		ft_parse(int ac, char **av, char ***arg, t_list **pile);
void	ft_printpile(t_list *a_list, t_list *b_list);
void	ft_push(t_list **src, t_list **dest);
void	ft_radix(t_list **a_list, t_list **b_list);
void	ft_rotate(t_list **lst);
void	ft_rrotate(t_list **lst);
t_moves	*ft_setmove(int index, t_list *a_list, t_list *b_list, int i);
int		ft_sort(t_list **a_list, t_list **b_list);
void	ft_sort2(t_list *list);
void	ft_sort3(t_list **list, int n0, int n1, int n2);
void	ft_swap(t_list **lst);
int		ft_tablen(char **tab);

#endif
