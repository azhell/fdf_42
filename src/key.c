/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:13:37 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/12/07 14:13:39 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_proj_key(int key, t_mat *m)
{
	if (key == 31)
		m->fl_projection = 0;
	else
		m->fl_projection = 1;
	mlx_clear_window(m->mlx, m->win);
	ft_transform(m);
	ft_projection(m);
}

void	ft_move_key(int key, t_mat *m)
{
	if (key == 123 || key == 124 || key == 125 || key == 126)
	{
		if (key == 123)
			m->trf->wx -= 4;
		else if (key == 124)
			m->trf->wx += 4;
		else if (key == 125)
			m->trf->wy += 4;
		else if (key == 126)
			m->trf->wy -= 4;
		mlx_clear_window(m->mlx, m->win);
		ft_transform(m);
		ft_projection(m);
	}
}

void	ft_scale_key(int key, t_mat *m)
{
	if (key == 78 || key == 69)
	{
		if (key == 69 && m->trf->scale < 3.0)
			m->trf->scale += 0.01;
		else if (key == 78 && m->trf->scale > 0.05)
			m->trf->scale -= 0.01;
		mlx_clear_window(m->mlx, m->win);
		ft_transform(m);
		ft_projection(m);
	}
}

void	ft_transform_key(int key, t_mat *m)
{
	if (key == 13)
		m->trf->x += 0.034;
	else if (key == 1)
		m->trf->x -= 0.034;
	else if (key == 0)
		m->trf->y += 0.034;
	else if (key == 2)
		m->trf->y -= 0.034;
	else if (key == 12)
		m->trf->z += 0.034;
	else if (key == 14)
		m->trf->z -= 0.034;
	mlx_clear_window(m->mlx, m->win);
	ft_transform(m);
	ft_projection(m);
}

int		ft_key(int key, t_mat *m)
{
	if (key == 53)
		exit(4);
	if (key == 78 || key == 69)
		ft_scale_key(key, m);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		ft_move_key(key, m);
	if (key == 13 || key == 0 || key == 1 || key == 2 || key == 12 || key == 14)
		ft_transform_key(key, m);
	if (key == 31 || key == 35)
		ft_proj_key(key, m);
	if (key == 15)
		ft_reset(m);
	if (key == 24 || key == 27)
		ft_z_scale(key, m);
	if (key == 4)
		ft_key_menu(m);
	return (0);
}
