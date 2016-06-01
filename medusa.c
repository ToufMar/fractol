/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medusa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroturea <mroturea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 16:10:15 by mroturea          #+#    #+#             */
/*   Updated: 2016/06/01 16:12:46 by mroturea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_medusa(t_struct *s)
{
  s->x1 = -3;
  s->x2 = 2.5;
  s->y1 = -2;
  s->y2 = 3;
  s->zoom = 259.37;
  s->iter_max = 80;
  mandelbrot(s);
}

void medusa(t_struct *s)
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
        s->z_r = fabs(s->z_r * s->z_r - s->z_i * s->z_i) + s->c_r;
        s->z_i = 3 * s->z_i * s->tmp + s->c_i;
        s->i++;
      }
      put_pixel_to_image(s);
      s->y++;
    }
    s->x++;
  }
}
