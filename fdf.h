/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 10:27:23 by etregoni          #+#    #+#             */
/*   Updated: 2017/06/26 19:25:00 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include <mlx.h>
#include <libft.h>
#include <math.h>
#include <stdio.h>
# define WHITE 0x00FFFFFF
# define BLUE 0x00242cf8
# define RED  0x00FF0000

typedef struct  s_coord
{
  float         x;
  float         y;
  float         z;
  float         raw_z;
}               coord;

typedef struct  s_draw_line
{
  char          *str;
  char          **points;
  char          *line;
  float         delta;
  float         offset;
  float         threshold;
  float         adjust;
}               draw_line;

typedef struct  s_map
{
  int           **map_ptr;
  int           win_x;
  int           win_y;
  int           hmax;
  int           hmin;
  int           h;
  int           w;
}               map;

typedef struct  s_env
{
  coord         **cart;
  float         x1;
  float         x2;
  float         y1;
  float         y2;
  int           gap;
  int           big;
  float         rise;
  float         run;
  float         m;
  float         win_h;
  float         win_w;
  int           mid_x;
  int           mid_y;
  int           i;
  int           j;
  int           h;
  int           w;
  float         z;
  float         next_z;
  void          *mlx;
  void          *win;
}               env;

void  parse_xy(map *m, int fd, draw_line *arg);
void  parse_z(map *m, int fd);
env *make_env(map *m);
int count_width(char **map_coord);
void  slope_steep(env *fdf, draw_line *values);
void slope_gradual(env *fdf, draw_line *values);
void slope_flat(env *fdf);
void    plot_lines(env *fdf);
void	rotate_z(env **fdf);
void	rotate_x(env **fdf);

#endif
