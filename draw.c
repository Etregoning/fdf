/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 10:27:23 by etregoni          #+#    #+#             */
/*   Updated: 2017/06/26 19:25:00 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void   values_down(env **fdf, int i, int j)
{
  if (i + 1 < (*fdf)->h)
  {
    (*fdf)->x1 = round((*fdf)->cart[i][j].x);
    (*fdf)->y1 = round((*fdf)->cart[i][j].y);
    (*fdf)->x1 = round((*fdf)->cart[i + 1][j].x);
    (*fdf)->y1 = round((*fdf)->cart[i + 1][j].y);
    (*fdf)->z = (*fdf)->cart[i][j].raw_z;
    (*fdf)->next_z = (*fdf)->cart[i + 1][j].raw_z
    (*fdf)->rise = (*fdf)->y2 - (*fdf)->y1;
    (*fdf)->run = (*fdf)->x2 - (*fdf)->x1;
  }
}

void    draw_down(env *fdf, draw_line **bresen)
{
  fdf->i = 0;
  while (fdf->i < fdf->h)
  {
    fdf->j = 0;
    while (fdf->j < fdf->w)
    {
      values_down(&fdf, fdf->i, fdf->j);
      if (fdf->run == 0 && fdf->i + 1 < fdf->h)
        slope_flat(fdf);
      else
      {
        fdf->m = fdf->rise / fdf->run;
        (*bresen)->adjust = fdf->m >= 0 ? 1 : -1;
        (*bresen)->offset = 0;
        (*bresen)->threshold = 0.5;
        if (*fdf->m <= 1 && fdf->m >= 1)
          slope_shallow(fdf, *bresen);
        else
          slope_steep(fdf, *bresen);
      }
      fdf->j++;
    }
    fdf->i++;
  }
}

void   values_right(env **fdf, int i, int j)
{
  if (j + 1 < (*fdf)->w)
  {
    (*fdf)->x1 = round((*fdf)->cart[i][j].x);
    (*fdf)->y1 = round((*fdf)->cart[i][j].y);
    (*fdf)->x1 = round((*fdf)->cart[i][j + 1].x);
    (*fdf)->y1 = round((*fdf)->cart[i][j + 1].y);
    (*fdf)->z = (*fdf)->cart[i][j].raw_z;
    (*fdf)->next_z = (*fdf)->cart[i + 1][j].raw_z
    (*fdf)->rise = (*fdf)->y2 - (*fdf)->y1;
    (*fdf)->run = (*fdf)->x2 - (*fdf)->x1;
  }
}

void    draw_right(env *fdf, draw_line **b)
{
  fdf->i = 0;
  while (fdf->i < fdf->h)
  {
    fdf->j = 0;
    while (fdf->j < fdf->w)
    {
      values_right(&fdf, fdf->i, fdf->j);
      if (fdf->run == 0  && fdf->j + 1 < fdf->h)
        slope_flat(fdf);
      else
      {
        fdf->m = fdf->rise / fdf->run;
        (*b)->adjust = fdf->m >= 0 ? 1 : -1;
        (*b)->offset = 0;
        (*b)->threshold = 0.5;
        if (fdf->m <= 1 && fdf->m >= -1)
          slope_shallow(fdf, *b)
        else
          slope_steep(fdf, *b)
      }
      fdf->j++;
    }
    fdf->i++;
  }
}

void plot_lines(env *fdf)
{
  int x;
  int y;
  draw_line *bresen;

  x = 0;
  y = 0;
  bresen = (draw_line *)malloc(sizeof(draw_line));
  draw_right(fdf, &bresen);
  draw_down(fdf, &bresen);
}
