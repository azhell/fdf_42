/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:31:01 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/11/26 16:53:01 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_variable(t_mat *mat)
{
	t_transform	*tr;

	tr = (t_transform*)malloc(sizeof(t_transform));
	mat->mlx = mlx_init();
	mat->win = mlx_new_window(mat->mlx, WIDTH, HEIGHT, "FDF");
	tr->x = 0.9;
	tr->y = 0.6;
	tr->z = 0.0;
	tr->scale = 1;
	tr->wx = 0;
	tr->wy = 0;
	mat->zk = 5000;
	mat->trf = tr;
	mat->fl_projection = 0;
	mat->menu = 1;
}

int		main(int ac, char **av)
{
	t_mat	*mat;

	if (ac != 2)
		ft_error(0);
	mat = (t_mat*)malloc(sizeof(t_mat));
	mat->local = ft_read_file(av[1], mat);
	ft_init_variable(mat);
	ft_local_init(mat);
	ft_world_memory(mat);
	ft_transform(mat);
	ft_projection(mat);
	mlx_hook(mat->win, 2, 5, ft_key, mat);
	mlx_loop(mat->mlx);
	return (0);
}
