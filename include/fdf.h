/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:13:02 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/11/26 18:13:04 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1920
# define HEIGHT 1080
# define FDERROR(fd) if (fd < 0) ft_error(1)
# define MALLCHECKF(x) if (!x) ft_error(4);

# include <math.h>
# include <stdio.h>
# include "mlx.h"
# include "libft.h"

typedef struct	s_rgb
{
	int r;
	int g;
	int b;
}				t_rgb;

typedef struct	s_cord
{
	int		ox;
	int		oy;
	int		oz;
	int		sz;
	t_rgb	*rgb;
}				t_cord;

typedef	struct	s_line
{
	char			*content;
	struct s_line	*next;
}				t_line;

typedef	struct	s_cor
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
}				t_cor;

typedef	struct	s_transform
{
	double	x;
	double	y;
	double	z;
	double	scale;
	int		wx;
	int		wy;
}				t_transform;

typedef struct	s_mat
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_ptr;
	int			bpp;
	int			endian;
	int			s_line;
	int			len;
	int			wid;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			zk;
	int			zp;
	int			err;
	int			err2;
	int			x;
	int			y;
	int			z;
	int			fl_projection;
	int			step;
	int			menu;
	t_cord		**cord;
	t_cord		**local;
	t_transform	*trf;
}				t_mat;

void			ft_error(int i);
void			ft_reset(t_mat *m);
void			ft_z_scale(int key, t_mat *m);
t_cord			**ft_read_file(char *file, t_mat *mat);
void			ft_projection(t_mat *m);
void			ft_local_init(t_mat *m);
void			ft_world_init(t_mat *m);
t_line			*ft_lnewline(char *content);
void			ft_lddline(t_line **list, char *content);
void			ft_ldel(t_line **list);
void			ft_freemap(char **map);
int				ft_atoi_hex(char *str);
void			ft_draw_line(t_mat *mat, t_cor *cor);
void			ft_valid_len(t_line *list, t_mat *mat, int count);
void			ft_valid_color(char *map);
void			ft_init_cor(t_cor *cor, int i, int j);
void			ft_init_draw(t_mat *mat);
int				ft_key(int key, t_mat *m);
void			ft_draw(t_mat *mat);
void			ft_move(int	x, int y, t_mat *m);
t_rgb			*ft_rgb_grad(t_mat *m, t_cor *c);
void			ft_transform(t_mat *m);
void			ft_prespt(t_mat *m);
void			ft_world_memory(t_mat *m);
void			ft_menu(t_mat *m);
void			ft_key_menu(t_mat *m);

#endif
