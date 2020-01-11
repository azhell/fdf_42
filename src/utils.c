/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unitls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:34:07 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/12/01 15:34:09 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_local_init(t_mat *m)
{
	int		i;
	int		j;

	m->step = HEIGHT / (m->len < m->wid ? m->wid : m->len);
	i = 0;
	while (i < m->wid)
	{
		j = 0;
		while (j < m->len)
		{
			m->local[i][j].ox += m->step * j;
			m->local[i][j].oy += m->step * i;
			m->local[i][j].ox -= m->len / 2 * m->step;
			m->local[i][j].oy -= m->wid / 2 * m->step;
			m->local[i][j].sz = m->local[i][j].oz;
			j++;
		}
		i++;
	}
}

void		ft_world_init(t_mat *m)
{
	int		i;
	int		j;
	int		stepx;
	int		stepy;

	stepx = (WIDTH - m->step * m->len) / 2;
	stepy = (HEIGHT - m->step * (m->wid - 1)) / 2;
	i = 0;
	while (i < m->wid)
	{
		j = 0;
		while (j < m->len)
		{
			m->cord[i][j].ox += m->len / 2 * m->step + stepx + m->trf->wx;
			m->cord[i][j].oy += m->wid / 2 * m->step + stepy + m->trf->wy;
			j++;
		}
		i++;
	}
}

static int	ft_get_num(char ch)
{
	if (ch == 'A' || ch == 'a')
		return (10);
	if (ch == 'B' || ch == 'b')
		return (11);
	if (ch == 'C' || ch == 'c')
		return (12);
	if (ch == 'D' || ch == 'd')
		return (13);
	if (ch == 'E' || ch == 'e')
		return (14);
	if (ch == 'F' || ch == 'f')
		return (15);
	return (0);
}

int			ft_atoi_hex(char *s)
{
	int				i;
	int				res;
	int				len;
	unsigned int	result;

	i = 0;
	result = 0;
	len = 1;
	while ((s[i] >= '0' && s[i] <= '9' && s[i] != '\0' && i < 2) ||
	(s[i] >= 'A' && s[i] <= 'F' && s[i] != '\0' && i < 2) ||
	(s[i] >= 'a' && s[i] <= 'f' && i < 2))
	{
		if ((s[i] >= 'A' && s[i] <= 'F') || (s[i] >= 'a' && s[i] <= 'f'))
			res = ft_get_num(s[i]);
		else
			res = s[i] - '0';
		result += res * pow(16, len - i);
		i++;
	}
	return (result);
}

void		ft_freemap(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
