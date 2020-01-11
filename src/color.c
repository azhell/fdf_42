/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 03:21:44 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/12/09 03:21:45 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_rgb	*ft_rgb_grad(t_mat *m, t_cor *c)
{
	float	d;
	int		i;
	t_rgb	*rg;
	t_rgb	col;

	i = 0;
	if ((m->cord[c->x1][c->y1].rgb->r != m->cord[c->x2][c->y2].rgb->r) ||
	(m->cord[c->x1][c->y1].rgb->g != m->cord[c->x2][c->y2].rgb->g) ||
	(m->cord[c->x1][c->y1].rgb->b != m->cord[c->x2][c->y2].rgb->b))
	{
		d = sqrt(pow(m->dx, 2) + pow(m->dy, 2));
		rg = (t_rgb*)malloc(sizeof(t_rgb) * (d + 1));
		col.r = m->cord[c->x1][c->y1].rgb->r;
		col.g = m->cord[c->x1][c->y1].rgb->g;
		col.b = m->cord[c->x1][c->y1].rgb->b;
		while (i < (int)d)
		{
			rg[i].r = col.r - (col.r - m->cord[c->x2][c->y2].rgb->r) / d * i;
			rg[i].g = col.g - (col.g - m->cord[c->x2][c->y2].rgb->g) / d * i;
			rg[i].b = col.b - (col.b - m->cord[c->x2][c->y2].rgb->b) / d * i;
			i++;
		}
		return (rg);
	}
	return (NULL);
}

void	ft_key_menu(t_mat *m)
{
	m->menu *= -1;
	mlx_clear_window(m->mlx, m->win);
	ft_transform(m);
	ft_projection(m);
}

void	ft_menu(t_mat *m)
{
	if (m->menu == 1)
	{
		mlx_string_put(m->mlx, m->win, 5, 0, 16777215, "Usage:");
		mlx_string_put(m->mlx, m->win, 5, 20, 16777215, "ESC to exit");
		mlx_string_put(m->mlx, m->win, 5, 40, 16777215, "ARROW move");
		mlx_string_put(m->mlx, m->win, 5, 60, 16777215,
		"O, P - change projection");
		mlx_string_put(m->mlx, m->win, 5, 80, 16777215,
		"Rotate: Q, E - z axis. W, S - x axis. A, D - y axis");
		mlx_string_put(m->mlx, m->win, 5, 100, 16777215,
		"- +  change height");
		mlx_string_put(m->mlx, m->win, 5, 120, 16777215,
		"Num - +  scale ");
		mlx_string_put(m->mlx, m->win, 5, 140, 16777215,
		"H - hide/unhide menu");
	}
}
