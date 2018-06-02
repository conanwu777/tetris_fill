/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 01:49:28 by cwu               #+#    #+#             */
/*   Updated: 2018/04/25 01:49:31 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			error(int fd)
{
	read(fd, g_buf, BUFF_SIZE);
	g_cpc = 0;
	while (g_buf[g_cpc])
	{
		g_pt.r = -1;
		while (++g_pt.r < 4)
		{
			g_pt.c = -1;
			while (++g_pt.c < 4)
			{
				if (g_buf[g_cpc] != '.' && g_buf[g_cpc] != '#')
					return (-1);
				g_cpc++;
			}
			if (g_buf[g_cpc] != '\n')
				return (-1);
			g_cpc++;
		}
		g_pcnum++;
		g_cpc++;
	}
	g_cpc--;
	if (g_buf[g_cpc] != '\0')
		return (-1);
	return (g_pcnum);
}

static int	count_nb(char pc[4][4], t_pt pt)
{
	int i;

	i = 0;
	if (pt.r != 0 && pc[pt.r - 1][pt.c] == '#')
		i++;
	if (pt.c != 0 && pc[pt.r][pt.c - 1] == '#')
		i++;
	if (pt.r != 3 && pc[pt.r + 1][pt.c] == '#')
		i++;
	if (pt.c != 3 && pc[pt.r][pt.c + 1] == '#')
		i++;
	return (i);
}

static t_pt	nb(char pc[4][4], t_pt pt)
{
	t_pt tmp;

	tmp = pt;
	if (pt.r != 0 && pc[pt.r - 1][pt.c] == '#')
		tmp.r--;
	if (pt.c != 0 && pc[pt.r][pt.c - 1] == '#')
		tmp.c--;
	if (pt.r != 3 && pc[pt.r + 1][pt.c] == '#')
		tmp.r++;
	if (pt.c != 3 && pc[pt.r][pt.c + 1] == '#')
		tmp.c++;
	return (tmp);
}

int			verify_pieces(void)
{
	g_cpc = -1;
	while (++g_cpc < g_pcnum)
	{
		g_emp = 0;
		g_pt.r = -1;
		while (++g_pt.r < 4)
		{
			g_pt.c = -1;
			while (++g_pt.c < 4)
			{
				if (g_pcs[g_cpc].p[g_pt.r][g_pt.c] == '#')
				{
					if (count_nb(g_pcs[g_cpc].p, g_pt) == 0)
						return (0);
					if (count_nb(g_pcs[g_cpc].p, g_pt) == 1 &&
						count_nb(g_pcs[g_cpc].p, nb(g_pcs[g_cpc].p, g_pt)) == 1)
						return (0);
					g_emp++;
				}
			}
		}
		if (g_emp != 4)
			return (0);
	}
	return (1);
}
