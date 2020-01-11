/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 21:02:21 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/12/03 21:02:23 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	ft_put_pixel(t_mat *m, int x, int y, t_rgb color)
{
	int	i;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	i = x * m->bpp + y * m->s_line;
	m->img_ptr[i] = color.b;
	m->img_ptr[++i] = color.g;
	m->img_ptr[++i] = color.r;
}

void	ft_init_mat(t_mat *m, t_cor *c)
{
	m->x = m->cord[c->x1][c->y1].ox;
	m->y = m->cord[c->x1][c->y1].oy;
	m->dx = abs(m->cord[c->x2][c->y2].ox - m->cord[c->x1][c->y1].ox);
	m->dy = abs(m->cord[c->x2][c->y2].oy - m->cord[c->x1][c->y1].oy);
	m->sx = m->cord[c->x1][c->y1].ox < m->cord[c->x2][c->y2].ox ? 1 : -1;
	m->sy = m->cord[c->x1][c->y1].oy < m->cord[c->x2][c->y2].oy ? 1 : -1;
	m->err = m->dx - m->dy;
	ft_put_pixel(m, m->cord[c->x2][c->y2].ox, m->cord[c->x2][c->y2].oy,
	*(m->cord[c->x2][c->y2].rgb));
}

void	ft_draw_line(t_mat *m, t_cor *c)
{
	t_rgb	*nrgb;
	int		i;

	i = 0;
	ft_init_mat(m, c);
	nrgb = ft_rgb_grad(m, c);
	while (m->x != m->cord[c->x2][c->y2].ox || m->y != m->cord[c->x2][c->y2].oy)
	{
		ft_put_pixel(m, m->x, m->y, nrgb != NULL ? nrgb[i]
		: *(m->cord[c->x1][c->y1].rgb));
		m->err2 = m->err * 2;
		if (m->err2 > -m->dy)
		{
			m->err -= m->dy;
			m->x += m->sx;
		}
		if (m->err2 < m->dx)
		{
			m->err += m->dx;
			m->y += m->sy;
		}
		i++;
	}
	free(nrgb);
}

void	init_draw(t_mat *mat)
{
	mat->img = mlx_new_image(mat->mlx, WIDTH, HEIGHT);
	mat->img_ptr = mlx_get_data_addr(mat->img, &mat->bpp, &mat->s_line,
	&mat->endian);
	mat->bpp /= 8;
}

void	ft_draw(t_mat *mat)
{
	t_cor	*cor;
	int		i;
	int		j;

	i = -1;
	cor = (t_cor*)malloc(sizeof(t_cor));
	init_draw(mat);
	while (++i < mat->wid)
	{
		j = -1;
		while (++j < mat->len)
		{
			ft_init_cor(cor, i, j);
			if (j + 1 < mat->len)
				ft_draw_line(mat, cor);
			cor->y2 = j;
			cor->x2 = i + 1;
			if (i + 1 < mat->wid)
				ft_draw_line(mat, cor);
		}
	}
	mlx_put_image_to_window(mat->mlx, mat->win, mat->img, 0, 0);
	mlx_destroy_image(mat->mlx, mat->img);
	ft_menu(mat);
	free(cor);
}
