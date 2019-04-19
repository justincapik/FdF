/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 08:44:37 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/30 09:45:45 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

void		key_up(t_img *img)
{
	img->matrice[3][2] += 10;
	put_img(img->mlx_ptr, img->win_ptr, img->data, img);
}

void		key_left(t_img *img)
{
	img->matrice[3][1] += 5;
	img->matrice[3][0] -= 5;
	put_img(img->mlx_ptr, img->win_ptr, img->data, img);
}

void		key_right(t_img *img)
{
	img->matrice[3][1] -= 5;
	img->matrice[3][0] += 5;
	put_img(img->mlx_ptr, img->win_ptr, img->data, img);
}

static void	key_press_helper(int keycode, t_img *img)
{
	if (keycode == 46)
		key_m(img);
	else if (keycode == 16)
		key_y(img);
	else if (keycode == 32)
		key_u(img);
	else if (keycode == 38)
		key_j(img);
	else if (keycode == 53)
	{
		free_img(img);
		exit(0);
	}
}

int			key_press(int keycode, void *param)
{
	t_img *img;

	img = (t_img *)param;
	if (keycode == 126)
		key_up(img);
	else if (keycode == 123)
		key_left(img);
	else if (keycode == 124)
		key_right(img);
	else if (keycode == 125)
		key_down(img);
	else if (keycode == 34)
		key_i(img);
	else if (keycode == 31)
		key_o(img);
	else if (keycode == 35)
		key_p(img);
	else if (keycode == 40)
		key_k(img);
	else if (keycode == 37)
		key_l(img);
	else
		key_press_helper(keycode, img);
	return (0);
}
