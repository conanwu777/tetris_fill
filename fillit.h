/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 01:49:50 by cwu               #+#    #+#             */
/*   Updated: 2018/04/25 01:49:54 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFF_SIZE 550

typedef struct	s_pt
{
	int			r;
	int			c;
}				t_pt;

typedef struct	s_piece
{
	char		p[4][4];
	t_pt		ul;
	t_pt		hw;
}				t_piece;

typedef struct	s_list
{
	int			piece;
	t_pt		pt;
}				t_list;

t_piece			g_pcs[26];
int				g_pcnum;
t_list			**g_poss;
t_list			g_tmp;
t_pt			g_pt;
t_pt			*g_nb;
int				g_cpc;
int				g_emp;
char			g_buf[BUFF_SIZE];

void			get_pieces(void);
int				occupied(t_list poss, t_pt pt);
char			**setup(int size);
void			printtab(char **tab, int size);
void			add_delete(t_list poss, char **tab, int size, int i);
int				error(int fd);
int				verify_pieces(void);

#endif
