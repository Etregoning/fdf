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

void	values_down(t_env **fdf, int i, int j)
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

void	draw_down(t_env *fdf, t_drawline **values)
{
	fdf->i = 0;
	while (fdf->i + 1 < fdf->h)
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
				(*values)->adjust = fdf->m >= 0 ? 1 : -1;
				(*values)->offset = 0;
				(*values)->threshold = 0.5;
				if (fdf->m <= 1 && fdf->m >= -1)
					slope_gradual(fdf, *values);
				else
					slope_steep(fdf, *values);
			}
			fdf->j++;
		}
		fdf->i++;
	}
}

void	values_right(t_env **fdf, int i, int j)
{
	if (j + 1 < (*fdf)->w)
	{
		(*fdf)->x1 = round((*fdf)->cart[i][j].x);
		(*fdf)->y1 = round((*fdf)->cart[i][j].y);
		(*fdf)->x2 = round((*fdf)->cart[i][j + 1].x);
		(*fdf)->y2 = round((*fdf)->cart[i][j + 1].y);
		(*fdf)->z = (*fdf)->cart[i][j].z;
		(*fdf)->next_z = (*fdf)->cart[i][j + 1].z;
		(*fdf)->rise = (*fdf)->y2 - (*fdf)->y1;
		(*fdf)->run = (*fdf)->x2 - (*fdf)->x1;
	}
}

void	draw_right(t_env *fdf, t_drawline **values)
{
	fdf->i = 0;
	while (fdf->i < fdf->h)
	{
		fdf->j = 0;
		while (fdf->j + 1 < fdf->w)
		{
			values_right(&fdf, fdf->i, fdf->j);
			if (fdf->run == 0 && fdf->j + 1 < fdf->h)
				slope_flat(fdf);
			else
			{
				fdf->m = fdf->rise / fdf->run;
				(*values)->adjust = fdf->m >= 0 ? 1 : -1;
				(*values)->offset = 0;
				(*values)->threshold = 0.5;
				if (fdf->m <= 1 && fdf->m >= -1)
					slope_gradual(fdf, *values);
				else
					slope_steep(fdf, *values);
			}
			fdf->j++;
		}
		fdf->i++;
	}
}

void	plot_lines(t_env *fdf)
{
	t_drawline *values;

	values = (t_drawline *)malloc(sizeof(t_drawline));
	rotate_z(fdf);
	rotate_x(fdf);
	translate(fdf);
	draw_right(fdf, &values);
	draw_down(fdf, &values);
}
