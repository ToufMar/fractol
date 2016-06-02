/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroturea <mroturea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 17:19:00 by mroturea          #+#    #+#             */
/*   Updated: 2016/06/02 17:55:38 by mroturea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_color(t_struct *s)
{
	if (s->color == 0)
		BLACK;
	if (s->color == 1)
		COL1;
	if (s->color == 2)
		COL2;
	if (s->color == 3)
		COL3;
	if (s->color == 4)
		COL4;
	if (s->color == 5)
		COL5;
}

void	put_pixel_to_image(t_struct *s)
{
	if (s->i == s->iter_max && s->bw == 0)
	{
		s->ptr_img[(s->size_line * s->y) + (4 * s->x) + 2] = 255;
		s->ptr_img[(s->size_line * s->y) + (4 * s->x) + 1] = 255;
		s->ptr_img[(s->size_line * s->y) + (4 * s->x)] = 255;
	}
	else if (s->i == s->iter_max && s->bw == 1)
	{
		s->ptr_img[(s->size_line * s->y) + (4 * s->x) + 2] = 0;
		s->ptr_img[(s->size_line * s->y) + (4 * s->x) + 1] = 0;
		s->ptr_img[(s->size_line * s->y) + (4 * s->x)] = 0;
	}
	else
	{
		s->ptr_img[(s->size_line * s->y) + (4 * s->x) + 2] =
			(s->i * 255 / s->iter_max) * s->blue;
		s->ptr_img[(s->size_line * s->y) + (4 * s->x) + 1] =
			(s->i * 255 / s->iter_max) * s->green;
		s->ptr_img[(s->size_line * s->y) + (4 * s->x)] =
			(s->i * 255 / s->iter_max) * s->red;
	}
}
