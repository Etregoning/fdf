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

typedef struct  s_coord
{
  float         x;
  float         y;
  float         z;
}               coord;

typedef struct  s_draw_line
{
  char          *str;
  char          **points;
  char          *line;
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
  void          *mlx;
  void          *win;
  void          *img;
}               env;

#endif
