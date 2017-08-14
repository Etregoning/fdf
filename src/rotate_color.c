/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 10:27:23 by etregoni          #+#    #+#             */
/*   Updated: 2017/06/26 19:25:00 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_env *fdf)
{
	float	x;
	float	y;
	int		i;
	int		j;

	i = 0;
	while (i < fdf->h)
	{
		j = 0;
		while (j < fdf->w)
		{
			x = fdf->cart[i][j].x;
			y = fdf->cart[i][j].y;
			fdf->cart[i][j].x = x * cos(0.7854) - y * sin(0.7854);
			fdf->cart[i][j].y = x * sin(0.7854) + y * cos(0.7854);
			j++;
		}
		i++;
	}
}

void	rotate_z(t_env *fdf)
{
	float	y;
	float	z;
	int		i;
	int		j;

	i = 0;
	while (i < fdf->h)
	{
		j = 0;
		while (j < fdf->w)
		{
			y = fdf->cart[i][j].y;
			z = fdf->cart[i][j].z;
			fdf->cart[i][j].y = (y * cos(0.5235) - z * sin(0.5235));
			fdf->cart[i][j].z = (y * sin(0.5235) + z * cos(0.5235));
			j++;
		}
		i++;
	}
}

int		color2(t_drawline *values, float distance)
{
  if (distance <= (values->range * 0.10))
		return (0x00FF4500);
	else if (distance <= (values->range * 0.20))
		return (0x00FF5719);
	else if (distance <= (values->range * 0.30))
		return (0x00FF6A32);
	else if (distance <= (values->range * 0.40))
		return (0x00FF7C4C);
	else if (distance <= (values->range * 0.50))
		return (0x00FF8F66);
	else if (distance <= (values->range * 0.60))
		return (0x00FFA27F);
	else if (distance <= (values->range * 0.70))
		return (0x00FFB499);
	else if (distance <= (values->range * 0.80))
		return (0x00FFC7B2);
	else if (distance <= (values->range * 0.90))
		return (0x00FFD9CC);
	else if (distance <= values->range)
		return (0x00FFD9CC);
	return (0x006600FF);
}

int		color1(t_drawline *values, float distance)
{
	if (distance <= (values->range * 0.10))
		return (0x00FF4500);
	else if (distance <= (values->range * 0.20))
		return (0x00FF5719);
	else if (distance <= (values->range * 0.30))
		return (0x00FF6A32);
	else if (distance <= (values->range * 0.40))
		return (0x00FF7C4C);
	else if (distance <= (values->range * 0.50))
		return (0x00FF8F66);
	else if (distance <= (values->range * 0.60))
		return (0x00FFA27F);
	else if (distance <= (values->range * 0.70))
		return (0x00FFB499);
	else if (distance <= (values->range * 0.80))
		return (0x00FFC7B2);
	else if (distance <= (values->range * 0.90))
		return (0x00FFD9CC);
	else if (distance <= values->range)
		return (0x00FFD9CC);
	return (0x006600FF);
}

int		color(t_env *fdf, t_drawline *values, float distance)
{
	if ((fdf->next_z || fdf->z) > fdf->hmin)
	{
		if (fdf->z == fdf->next_z)
			return (0x00FF0000);
		if (fdf->z < fdf->next_z)
			return (color1(values, distance));
		else if (fdf->z > fdf->next_z)
			return (color2(values, distance));
	}
	return (0x00FF0000);
}
