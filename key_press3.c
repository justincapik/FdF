/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:43:27 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/21 11:50:21 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	key_down(t_img *img)
{
	img->matrice[3][2] -= 10;
	put_img(img->mlx_ptr, img->win_ptr, img->data, img);
}

void	key_m(t_img *img)
{
	init_matrice(img);
	put_img(img->mlx_ptr, img->win_ptr, img->data, img);
}

void	key_y(t_img *img)
{
	img->matrice[2][2] -= 1;
	put_img(img->mlx_ptr, img->win_ptr, img->data, img);
}

void	key_u(t_img *img)
{
	img->matrice[2][2] += 1;
	put_img(img->mlx_ptr, img->win_ptr, img->data, img);
}

void	key_j(t_img *img)
{
	int		i;
	double	**tmp;

	if (img->transfo & iso)
	{
		init_matrice(img);
		img->transfo = 0;
		img->transfo |= para;
		i = 0;
		while (i < 50)
		{
			tmp = mult_mat(img->rx, img->matrice);
			free_mat(img->matrice);
			img->matrice = tmp;
			++i;
		}
		img->matrice[3][2] = -(HEIGHT / 2.0) + 200;
		img->matrice[3][0] = WIDTH / 2.0 - 200;
	}
	else if (img->transfo & para)
		init_matrice(img);
	put_img(img->mlx_ptr, img->win_ptr, img->data, img);
}
