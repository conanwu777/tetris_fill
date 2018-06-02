/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defpcs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 01:48:31 by cwu               #+#    #+#             */
/*   Updated: 2018/04/25 01:48:39 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	set_h(void)
{
	g_cpc = -1;
	while (++g_cpc < g_pcnum)
	{
		g_pcs[g_cpc].hw.r = 4;
		g_pt.r = -1;
		while (++g_pt.r < 4)
		{
			g_emp = 1;
			g_pt.c = -1;
			while (++g_pt.c < 4)
				if (g_pcs[g_cpc].p[g_pt.r][g_pt.c] == '#')
					g_emp = 0;
			if (g_emp)
				g_pcs[g_cpc].hw.r--;
		}
	}
}

static void	set_w(void)
{
	g_cpc = -1;
	while (++g_cpc < g_pcnum)
	{
		g_pcs[g_cpc].hw.c = 4;
		g_pt.c = -1;
		while (++g_pt.c < 4)
		{
			g_emp = 1;
			g_pt.r = -1;
			while (++g_pt.r < 4)
				if (g_pcs[g_cpc].p[g_pt.r][g_pt.c] == '#')
					g_emp = 0;
			if (g_emp)
				g_pcs[g_cpc].hw.c--;
		}
	}
}

static void	set_ul_r(void)
{
	g_cpc = -1;
	while (++g_cpc < g_pcnum)
	{
		g_pcs[g_cpc].ul.r = 0;
		g_pt.r = -1;
		g_emp = 1;
		while (++g_pt.r < 4 && g_emp == 1)
		{
			g_pt.c = -1;
			while (++g_pt.c < 4)
			{
				if (g_pcs[g_cpc].p[g_pt.r][g_pt.c] == '#')
					g_emp = 0;
			}
			if (g_emp)
				g_pcs[g_cpc].ul.r++;
		}
	}
}

static void	set_ul_c(void)
{
	g_cpc = -1;
	while (++g_cpc < g_pcnum)
	{
		g_pcs[g_cpc].ul.c = 0;
		g_pt.c = -1;
		g_emp = 1;
		while (++g_pt.c < 4 && g_emp == 1)
		{
			g_pt.r = -1;
			while (++g_pt.r < 4)
			{
				if (g_pcs[g_cpc].p[g_pt.r][g_pt.c] == '#')
					g_emp = 0;
			}
			if (g_emp)
				g_pcs[g_cpc].ul.c++;
		}
	}
}

void		get_pieces(void)
{
	int i;

	i = 0;
	g_cpc = -1;
	while (++g_cpc < g_pcnum)
	{
		g_pt.r = -1;
		while (++g_pt.r < 4)
		{
			g_pt.c = 0;
			while (g_pt.c < 4)
				g_pcs[g_cpc].p[g_pt.r][g_pt.c++] = g_buf[i++];
			i++;
		}
		i++;
	}
	set_h();
	set_w();
	set_ul_r();
	set_ul_c();
}
