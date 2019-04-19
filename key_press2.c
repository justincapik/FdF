/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 11:06:25 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/21 11:49:53 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

void	key_i(t_img *img)
{
	double **tmp;

	tmp = mult_mat(img->rx, img->matrice);
	free_mat(img->matrice);
	img->matrice = tmp;
	put_img(img->mlx_ptr, img->win_ptr, img->data, img);
}

void	key_o(t_img *img)
{
	double **tmp;

	tmp = mult_mat(img->ry, img->matrice);
	free_mat(img->matrice);
	img->matrice = tmp;
	put_img(img->mlx_ptr, img->win_ptr, img->data, img);
}

void	key_p(t_img *img)
{
	double **tmp;

	tmp = mult_mat(img->rz, img->matrice);
	free_mat(img->matrice);
	img->matrice = tmp;
	put_img(img->mlx_ptr, img->win_ptr, img->data, img);
}

void	key_k(t_img *img)
{
	img->matrice[3][3] += img->zoom;
	put_img(img->mlx_ptr, img->win_ptr, img->data, img);
}

void	key_l(t_img *img)
{
	if (img->matrice[3][3] - img->zoom > 0)
		img->matrice[3][3] -= img->zoom;
	put_img(img->mlx_ptr, img->win_ptr, img->data, img);
}
