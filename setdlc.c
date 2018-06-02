/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setdlc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 01:49:06 by cwu               #+#    #+#             */
/*   Updated: 2018/04/25 01:49:11 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	set_poss(int size)
{
	int c;

	if (!(g_poss = (t_list**)malloc(sizeof(t_list*) * g_pcnum)))
		return ;
	g_cpc = -1;
	while (++g_cpc < g_pcnum)
	{
		c = 0;
		if (!(g_poss[g_cpc] = (t_list*)malloc(sizeof(t_list) *
			((size - g_pcs[g_cpc].hw.r + 1) *
				(size - g_pcs[g_cpc].hw.c + 1)) + 1)))
			return ;
		g_pt.r = -1;
		while (++g_pt.r <= size - g_pcs[g_cpc].hw.r)
		{
			g_pt.c = -1;
			while (++g_pt.c <= size - g_pcs[g_cpc].hw.c)
			{
				g_poss[g_cpc][c].pt = g_pt;
				g_poss[g_cpc][c].piece = g_cpc;
				c++;
			}
		}
		g_poss[g_cpc][c].piece = -1;
	}
}

char		**setup(int size)
{
	char **tab;

	if (!(tab = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	g_pt.r = -1;
	while (++g_pt.r < size)
	{
		if (!(tab[g_pt.r] = (char*)malloc(size)))
			return (NULL);
		g_pt.c = -1;
		while (++g_pt.c < size)
			tab[g_pt.r][g_pt.c] = '.';
	}
	set_poss(size);
	return (tab);
}

int			occupied(t_list poss, t_pt pt)
{
	t_piece	p;

	p = g_pcs[poss.piece];
	if (0 <= pt.r - poss.pt.r && pt.r - poss.pt.r <= p.hw.r &&
		0 <= pt.c - poss.pt.c && pt.c - poss.pt.c <= p.hw.c &&
		p.p[p.ul.r + pt.r - poss.pt.r][p.ul.c + pt.c - poss.pt.c] == '#')
		return (1);
	return (0);
}

void		add_delete(t_list poss, char **tab, int size, int i)
{
	g_pt.r = -1;
	if (i != -1)
	{
		while (++g_pt.r < size)
		{
			g_pt.c = -1;
			while (++g_pt.c < size)
			{
				if (occupied(poss, g_pt))
					tab[g_pt.r][g_pt.c] = 'A' + i;
			}
		}
	}
	else
	{
		while (++g_pt.r < size)
		{
			g_pt.c = -1;
			while (++g_pt.c < size)
			{
				if (occupied(poss, g_pt))
					tab[g_pt.r][g_pt.c] = '.';
			}
		}
	}
}

void		printtab(char **tab, int size)
{
	g_pt.r = -1;
	while (++g_pt.r < size)
	{
		write(1, tab[g_pt.r], size);
		write(1, "\n", 1);
		free(tab[g_pt.r]);
	}
	free(tab);
	g_cpc = -1;
	while (++g_cpc < g_pcnum)
		free(g_poss[g_cpc]);
	free(g_poss);
}
