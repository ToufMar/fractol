/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commande.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroturea <mroturea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 16:14:25 by mroturea          #+#    #+#             */
/*   Updated: 2016/06/01 18:53:35 by mroturea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_key_print(int key, t_struct *s)
{
  printf("%d\niter = %d\n", key, s->iter_max);
  if (key == 53)
  {
    exit(2);
    mlx_destroy_image(s->mlx, s->ptr_img);
    mlx_destroy_window(s->mlx, s->win);
  }
  if (key == 125)
    s->y1 *= 1.01;
  if (key == 126)
    s->y1 *= 0.99;
  if (key == 124)
    s->x1 *= 1.01;
  if (key == 123)
    s->x1 *= 0.99;
  if (key == 69)
    s->zoom *= 1.05;
  if (key == 78)
    s->zoom *= 0.97;
  if (key == 75)
    s->iter_max++;
  if (key == 67)
    s->iter_max--;
  if (key == 83)
	{
    s->type++;
    s->bol = 0;
    if (s->type == 5)
      s->type = 1;
  }
  put_img(s);
	return (1);
}
