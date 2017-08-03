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

void	values_down(env **fdf, int i, int j)
{
	if (i + 1 < (*fdf)->h)
	{
		(*fdf)->x1 = round((*fdf)->cart[i][j].x);
		(*fdf)->y1 = round((*fdf)->cart[i][j].y);
		(*fdf)->x2 = round((*fdf)->cart[i + 1][j].x);
		(*fdf)->y2 = round((*fdf)->cart[i + 1][j].y);
		(*fdf)->z = (*fdf)->cart[i][j].z;
		(*fdf)->next_z = (*fdf)->cart[i + 1][j].z;
		(*fdf)->rise = (*fdf)->y2 - (*fdf)->y1;
		(*fdf)->run = (*fdf)->x2 - (*fdf)->x1;
	}
}

void	draw_down(env *fdf, map *m, draw_line **bresen)
{
	fdf->i = 0;
	while (fdf->i + 1 < m->h)
	{
		fdf->j = 0;
		while (fdf->j < m->w)
		{
			values_down(&fdf, fdf->i, fdf->j);
			if (fdf->run == 0 && fdf->i + 1 < m->h)
			{
				slope_flat(fdf);
			}
			else
			{
				fdf->m = fdf->rise / fdf->run;
				(*bresen)->adjust = fdf->m >= 0 ? 1 : -1;
				(*bresen)->offset = 0;
				(*bresen)->threshold = 0.5;
				if (fdf->m <= 1 && fdf->m >= -1)
					slope_gradual(fdf, *bresen);
				else
					slope_steep(fdf, *bresen);
			}
			fdf->j++;
		}
		fdf->i++;
	}
}

void	values_right(env **fdf, int i, int j)
{
	if (j + 1 < (*fdf)->w)
	{
		(*fdf)->x1 = round((*fdf)->cart[i][j].x);
		(*fdf)->y1 = round((*fdf)->cart[i][j].y);
		(*fdf)->x2 = round((*fdf)->cart[i][j + 1].x);
		(*fdf)->y2 = round((*fdf)->cart[i][j + 1].y);
		(*fdf)->z = (*fdf)->cart[i][j].z;
		(*fdf)->next_z = (*fdf)->cart[i + 1][j].z;
		(*fdf)->rise = (*fdf)->y2 - (*fdf)->y1;
		(*fdf)->run = (*fdf)->x2 - (*fdf)->x1;
	}
	printf("y1 = %f, y2 = %f\n", (*fdf)->y1, (*fdf)->y2);
	printf("x1 = %f, x2 = %f\n", (*fdf)->x1, (*fdf)->x2);
}

void	draw_right(env *fdf, map *m, draw_line **bresen)
{
	fdf->i = 0;
	while (fdf->i < m->h)
	{
		fdf->j = 0;
		while (fdf->j + 1 < m->w)
		{
			values_right(&fdf, fdf->i, fdf->j);
			if (fdf->run == 0  && fdf->j + 1 < m->h)
				slope_flat(fdf);
			else
			{
				fdf->m = fdf->rise / fdf->run;
				(*bresen)->adjust = fdf->m >= 0 ? 1 : -1;
				(*bresen)->offset = 0;
				(*bresen)->threshold = 0.5;
				if (fdf->m <= 1 && fdf->m >= -1)
					slope_gradual(fdf, *bresen);
				else
					slope_steep(fdf, *bresen);
			}
			fdf->j++;
		}
		fdf->i++;
	}
}

void	plot_lines(env *fdf, map *m)
{
	draw_line *bresen;

	bresen = (draw_line *)malloc(sizeof(draw_line));
	draw_right(fdf, m, &bresen);
	//draw_down(fdf, m, &bresen);
}
