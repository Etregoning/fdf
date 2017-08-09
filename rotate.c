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

void	rotate_z(t_env *fdf)
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

void	rotate_x(t_env *fdf)
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
