/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:22:05 by amarchan          #+#    #+#             */
/*   Updated: 2022/04/05 16:22:08 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# define MISSING_ARG -1
# define EMPTY_STR -2
# define FOUND_DUP -3
# define NOT_INT -4
# define OUT_INT -5
# define INVALID_ARG -6
# define MALLOC_FAILURE -7

# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>

typedef struct s_stack
{
	int					num;
	int					index;
	int					sorted;
	int					size;
	int					*sort;
	struct s_stack		*prev;
	struct s_stack		*next;
}	t_stack;

typedef struct s_sort
{
	t_stack	*a;
	t_stack	*b;
}	t_sort;

//parsing
int			ft_strlen(const char *s);
int			ft_atoi(const char *str);
long long	ft_atoll(const char *str);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memcpy(void *s1, const void *s2, size_t n);
void		ft_lstrip(char *s);
void		ft_rstrip(char *s);
int			ft_isspace(int c);
void		ft_putchar(char c, int fd);
void		ft_putstr(char *s, int isend, int fd);
void		ft_putnbr(int n);
int			pile_isvalid(char *s);
int			ft_panic(int errcode);
t_stack		*ft_create_list(int size, char *arg);
t_stack		*ft_parse(int argc, char *arg);
int			ft_checkdup(t_stack *stack, int elt);
int			ft_isdigit(int c);
void		ft_getsorted(t_stack **a, t_stack *copy);
t_stack		*init_sort(t_stack *stack);

//linked list manipulation
void		ft_lstadd_back(t_stack **first_elt, t_stack *new);
void		ft_lstadd_front(t_stack **first_elt, t_stack *new);
void		ft_lstclear_back(t_stack **lst);
void		ft_lstclear(t_stack **lst);
void		ft_lstclear_first(t_stack **elt);
t_stack		*ft_lstnew(int argc, int arg, int index, int sorted);
int			ft_lstsize(t_stack *lst);
t_stack		*ft_lstcopy(t_stack *lst);

//moves
void		ft_sa(t_stack *stack);
void		ft_sb(t_stack *stack);
void		ft_pa(t_stack **a, t_stack **b);
void		ft_pb(t_stack **b, t_stack **a);
void		ft_ra(t_stack *stack, int i);
void		ft_rb(t_stack *stack, int i);
void		ft_rr(t_stack *a, t_stack *b);
void		ft_rra(t_stack *stack, int i);
void		ft_rrb(t_stack *stack, int i);
void		ft_rrr(t_stack *a, t_stack *b);

//push_swap
void		sort_3(t_stack *stack);
int			is_sorted(t_stack *stack);
int			is_complete(t_stack *a);
void		insert(t_stack **a, t_stack **b);
void		insert_elt(int idx_a, int idx_b, t_stack **a, t_stack **b);
void		rotate_ab(int idx_a, int idx_b, t_stack **a, t_stack **b);
void		sort_more(t_stack **a);
int			absolu(int x);
int			get_last_elt(t_stack *lst);

#endif
