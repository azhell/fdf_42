/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:27:56 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/01/03 14:27:58 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_scale(t_mat *m, int i, int j)
{
	m->cord[i][j].ox *= m->trf->scale;
	m->cord[i][j].oy *= m->trf->scale;
	m->cord[i][j].oz *= m->trf->scale;
}

void	ft_init_transform(t_mat *m, int i, int j)
{
	m->x = m->local[i][j].ox;
	m->y = m->local[i][j].oy;
	m->z = m->local[i][j].oz;
}

void	ft_transform(t_mat *m)
{
	int	i;
	int	j;

	i = -1;
	while (++i < m->wid)
	{
		j = -1;
		while (++j < m->len)
		{
			ft_init_transform(m, i, j);
			m->cord[i][j].ox = m->x * cos(m->trf->z) - m->y * sin(m->trf->z);
			m->cord[i][j].oy = m->x * sin(m->trf->z) + m->y * cos(m->trf->z);
			m->x = m->cord[i][j].ox;
			m->y = m->cord[i][j].oy;
			m->cord[i][j].oy = m->y * cos(m->trf->x) - m->z * sin(m->trf->x);
			m->cord[i][j].oz = m->y * sin(m->trf->x) + m->z * cos(m->trf->x);
			m->y = m->cord[i][j].oy;
			m->z = m->cord[i][j].oz;
			m->cord[i][j].ox = m->x * cos(m->trf->y) - m->z * sin(m->trf->y);
			m->cord[i][j].oz = m->z * cos(m->trf->y) + m->x * sin(m->trf->y);
			ft_init_scale(m, i, j);
		}
	}
	ft_world_init(m);
}

void	ft_prespt(t_mat *m)
{
	int		i;
	int		j;
	double	r;

	i = 0;
	r = -1.0 / m->zk;
	while (i < m->wid)
	{
		j = 0;
		while (j < m->len)
		{
			m->cord[i][j].ox = m->cord[i][j].ox / (r * m->cord[i][j].oz + 1);
			m->cord[i][j].oy = m->cord[i][j].oy / (r * m->cord[i][j].oz + 1);
			j++;
		}
		i++;
	}
}

void	ft_projection(t_mat *m)
{
	if (abs(m->cord[0][0].ox + m->cord[m->wid - 1][m->len - 1].ox)
	< m->zk - 500)
		m->zk += 500;
	if (m->fl_projection == 1)
		ft_prespt(m);
	ft_draw(m);
}
