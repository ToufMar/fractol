/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_tricorn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroturea <mroturea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 18:09:00 by mroturea          #+#    #+#             */
/*   Updated: 2016/06/02 18:01:54 by mroturea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_struct *s)
{
	s->x1 = -1.508;
	s->x2 = 2.5;
	s->y1 = -1.319;
	s->y2 = 3;
	s->zoom = 417.7;
	s->iter_max = 126;
}

void	julia(t_struct *s)
{
	s->image_x = HGT;
	s->image_y = WDT;
	s->x = 0;
	while (s->x < s->image_x)
	{
		s->y = 0;
		while (s->y < s->image_y)
		{
		s->c_r = 0.285;
		s->c_i = 0.01;
		s->z_r = s->x / s->zoom + s->x1;
		s->z_i = s->y / s->zoom + s->y1;
		s->i = 0;
		while (s->z_r * s->z_r + s->z_i * s->z_i < 4 && s->i < s->iter_max)
		{
			s->tmp = s->z_r;
			s->z_r = s->z_r * s->z_r - s->z_i * s->z_i + s->c_r;
			s->z_i = 2 * s->z_i * s->tmp + s->c_i;
			s->i++;
		}
		put_pixel_to_image(s);
		s->y++;
		}
		s->x++;
	}
}

void	init_tricorn(t_struct *s)
{
	s->x1 = -2.45;
	s->x2 = 2.5;
	s->y1 = -2.06;
	s->y2 = 3;
	s->zoom = 259;
	s->iter_max = 84;
}

void	tricorn(t_struct *s)
{
	s->image_x = HGT;
	s->image_y = WDT;
	s->x = 0;
	while (s->x < s->image_x)
	{
		s->y = 0;
		while (s->y < s->image_y)
		{
		s->c_r = s->x / s->zoom + s->x1;
		s->c_i = s->y / s->zoom + s->y1;
		s->z_r = 0;
		s->z_i = 0;
		s->i = 0;
		while (s->z_r * s->z_r + s->z_i * s->z_i < 4 && s->i < s->iter_max)
		{
			s->tmp = s->z_r;
			s->z_r = s->z_r * s->z_r - s->z_i * s->z_i + s->c_r;
			s->z_i = -2 * s->z_i * s->tmp + s->c_i;
			s->i++;
		}
		put_pixel_to_image(s);
		s->y++;
		}
		s->x++;
	}
}
