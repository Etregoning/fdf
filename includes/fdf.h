/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 10:27:23 by etregoni          #+#    #+#             */
/*   Updated: 2017/08/13 16:01:59 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <stdio.h>
# define WHITE 0x00FFFFFF
# define BLUE 0x00242cf8
# define RED  0x00FF0000

typedef struct	s_coord
{
	float		x;
	float		y;
	float		z;
	float		raw_z;
}				t_coord;

typedef struct	t_drawline
{
	char		*str;
	char		**points;
	char		*line;
	float		delta;
	float		offset;
	float		threshold;
	float		adjust;
	float		color;
	float		range;
}				t_drawline;

typedef struct	s_map
{
	int			**map_ptr;
	int			win_x;
	int			win_y;
	int			hmax;
	int			hmin;
	int			h;
	int			w;
}				t_map;

typedef struct	s_env
{
	t_coord		**cart;
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	int			gap;
	int			big;
	float		rise;
	float		run;
	float		m;
	float		win_h;
	float		win_w;
	int			mid_x;
	int			mid_y;
	int			i;
	int			j;
	int			h;
	int			w;
	float		z;
	float		next_z;
	void		*mlx;
	void		*win;
}				t_env;

void			parse_xy(t_map *m, int fd, t_drawline *arg);
void			parse_z(t_map *m, int fd);
t_env				*make_env(t_map *m);
int				count_width(char **map_coord);
void			slope_steep(t_env *fdf, t_drawline *values);
void			slope_gradual(t_env *fdf, t_drawline *values);
void			slope_flat(t_env *fdf);
void			plot_lines(t_env *fdf);
void			rotate_z(t_env *fdf);
void			rotate_x(t_env *fdf);
void			translate(t_env *fdf);

#endif
