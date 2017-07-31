/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slope.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 10:27:23 by etregoni          #+#    #+#             */
/*   Updated: 2017/06/26 19:25:00 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	slope_steep(env *fdf, draw_line *values)
{
	float x;
	float tmp;

	values->delta = fabsf(fdf->run / fdf->rise);
	x = fdf->x1;
	if (fdf->y2 < fdf->y1)
	{
		tmp = fdf->y2;
		fdf->y2 = fdf->y1;
		fdf->y1 = tmp;
		x = fdf->x2;
	}
	while (fdf->y1 < fdf->y2)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, x + 350, fdf->y1 + 350, RED);
		//printf("x = %f, y = %f\n", x, fdf->y1);
		values->offset += values->delta;
		if (values->offset >= values->threshold)
		{
			x += values->adjust;
			values->threshold += 1.0;
		}
		fdf->y1++;
	}
}

void	slope_shallow(env *fdf, draw_line *values)
{
	float y;
	float tmp;

	values->delta = fabsf(fdf->m);
	y = fdf->y1;
	if (fdf->x2 < fdf->x1)
	{
		tmp = fdf->x2;
		fdf->x2 = fdf->x1;
		fdf->x1 = tmp;
		y = fdf->x2;
	}
	while (fdf->y1 < fdf->y2)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->x1, y, BLUE);
		//printf("x = %f, y = %f\n", fdf->x1, y);
		values->offset += values->delta;
		if (values->offset >= values->threshold)
		{
			y += values->adjust;
			values->threshold += 1.0;
		}
		fdf->x1++;
	}
}

void	slope_flat(env *fdf)
{
	float   tmp;

	if (fdf->y2 < fdf->y1)
	{
		tmp = fdf->y2;
		fdf->y2 = fdf->y1;
		fdf->y1 = tmp;
	}
	while (fdf->y1 <= fdf->y2)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->x1 + 350, fdf->y1 + 350, WHITE);
		//printf("x = %f, y = %f\n", fdf->x1, fdf->y1);
		fdf->y1++;
	}
}
