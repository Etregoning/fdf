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

void	slope_steep(t_env *fdf, t_drawline *values)
{
	float x;
	float tmp;

	values->delta = fabsf(fdf->run / fdf->rise);
	x = fdf->x1;
	if (fdf->y2 < fdf->y1)
	{
		tmp = fdf->y1;
		fdf->y1 = fdf->y2;
		fdf->y2 = tmp;
		x = fdf->x2;
	}
	while (fdf->y1 < fdf->y2)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, x, fdf->y1, RED);
		values->offset += values->delta;
		if (values->offset >= values->threshold)
		{
			x += values->adjust;
			values->threshold += 1.0;
		}
		fdf->y1++;
	}
}

void	slope_gradual(t_env *fdf, t_drawline *values)
{
	float y;
	float tmp;

	values->delta = fabsf(fdf->m);
	y = fdf->y1;
	if (fdf->x2 < fdf->x1)
	{
		tmp = fdf->x1;
		fdf->x1 = fdf->x2;
		fdf->x2 = tmp;
		y = fdf->y2;
	}
	while (fdf->x1 < fdf->x2)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->x1, y, RED);
		values->offset += values->delta;
		if (values->offset >= values->threshold)
		{
			y += values->adjust;
			values->threshold += 1.0;
		}
		fdf->x1++;
	}
}

void	slope_flat(t_env *fdf)
{
	float	tmp;

	if (fdf->y2 < fdf->y1)
	{
		tmp = fdf->y1;
		fdf->y1 = fdf->y2;
		fdf->y2 = tmp;
	}
	while (fdf->y1 <= fdf->y2)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->x1, fdf->y1, RED);
		fdf->y1++;
	}
}
