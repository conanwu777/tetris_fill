/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 01:48:50 by cwu               #+#    #+#             */
/*   Updated: 2018/04/25 01:48:53 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	next_poss(char **tab, int size, int count, int i)
{
	int ind;
	int max;

	max = (size - g_pcs[i].hw.r + 1) * (size - g_pcs[i].hw.c + 1) - 1;
	while (count < max)
	{
		count++;
		ind = 1;
		g_pt.r = -1;
		while (++g_pt.r < size)
		{
			g_pt.c = -1;
			while (++g_pt.c < size)
				if (tab[g_pt.r][g_pt.c] != '.' &&
					occupied(g_poss[i][count], g_pt))
					ind = 0;
		}
		if (ind == 1)
			return (count);
	}
	return (-1);
}

static int	solve(int size)
{
	char	**tab;
	int		count[g_pcnum];
	int		t;

	tab = setup(size);
	g_cpc = -1;
	while (++g_cpc < g_pcnum)
		count[g_cpc] = -1;
	g_cpc = 0;
	while (g_cpc < g_pcnum && g_cpc >= 0)
	{
		// system("clear");
		// printtab(tab, size);
		if (count[g_cpc] != -1)
			add_delete(g_poss[g_cpc][count[g_cpc]], tab, size, -1);
		if ((t = next_poss(tab, size, count[g_cpc], g_cpc)) == -1)
			count[g_cpc--] = -1;
		else
		{
			add_delete(g_poss[g_cpc][t], tab, size, g_cpc);
			count[g_cpc++] = t;
		}
	}
	if (g_cpc == -1)
		return (0);
	printtab(tab, size);
	return (1);
}

int			main(int ac, char **av)
{
	int fd;
	int size;

	if (ac != 2)
	{
		write(1, "usage: fillit input_file\n", 25);
		return (-1);
	}
	fd = open(av[1], O_RDONLY);
	g_pcnum = 0;
	g_pcnum = error(fd);
	close(fd);
	get_pieces();
	if (g_pcnum == -1 || g_buf[0] == '\0' || !verify_pieces())
	{
		write(1, "error\n", 6);
		return (-1);
	}
	size = 2;
	while (size * size < g_pcnum * 4)
		size++;
	while (solve(size) != 1)
		size++;
	return (0);
}
