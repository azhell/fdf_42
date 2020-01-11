/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:10:09 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/12/11 15:10:11 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_z_scale(int key, t_mat *m)
{
	int i;
	int j;

	i = 0;
	while (i < m->wid)
	{
		j = 0;
		while (j < m->len)
		{
			if (key == 24 && m->local[i][j].oz > 0)
				m->local[i][j].oz *= 1.1;
			else if (key == 27 && m->local[i][j].oz > m->local[i][j].sz)
				m->local[i][j].oz *= 0.9;
			j++;
		}
		i++;
	}
	mlx_clear_window(m->mlx, m->win);
	ft_transform(m);
	ft_projection(m);
}

void	ft_reset(t_mat *m)
{
	int	i;
	int	j;

	i = 0;
	m->trf->x = 0.9;
	m->trf->y = 0.6;
	m->trf->z = 0.0;
	m->trf->scale = 1.0;
	m->trf->wx = 0;
	m->trf->wy = 0;
	while (i < m->wid)
	{
		j = -1;
		while (++j < m->len)
			m->local[i][j].oz = m->local[i][j].sz;
		i++;
	}
	mlx_clear_window(m->mlx, m->win);
	ft_transform(m);
	ft_projection(m);
}

void	ft_world_memory(t_mat *m)
{
	t_cord	**cord;
	int		i;
	int		j;

	i = 0;
	MALLCHECKF((cord = (t_cord**)malloc(sizeof(t_cord*) * m->wid)));
	while (i < m->wid)
	{
		j = 0;
		MALLCHECKF((cord[i] = (t_cord*)malloc(sizeof(t_cord) * m->len)));
		while (j < m->len)
		{
			if (m->fl_projection == 1)
				ft_prespt(m);
			cord[i][j].rgb = m->local[i][j].rgb;
			j++;
		}
		i++;
	}
	m->cord = cord;
}

void	ft_init_cor(t_cor *cor, int i, int j)
{
	cor->x1 = i;
	cor->y1 = j;
	cor->x2 = i;
	cor->y2 = j + 1;
}
