/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:59:20 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/29 14:22:39 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdlib.h>

void		init_matrice(t_img *img)
{
	img->rot = 0.1;
	img->zoom = 0.01;
	img->transfo = 0;
	img->transfo |= iso;
	if (img->matrice == NULL)
		img->matrice = malloc_mat();
	img->matrice[0][0] = 10.0;
	img->matrice[0][1] = 0.0;
	img->matrice[0][2] = 0.0;
	img->matrice[0][3] = 0.0;
	img->matrice[1][0] = 0.0;
	img->matrice[1][1] = 10.0;
	img->matrice[1][2] = 0.0;
	img->matrice[1][3] = 0.0;
	img->matrice[2][0] = 0.0;
	img->matrice[2][1] = 0.0;
	img->matrice[2][2] = 1;
	img->matrice[2][3] = 0.0;
	img->matrice[3][0] = WIDTH / 2.0;
	img->matrice[3][1] = 0.0;
	img->matrice[3][2] = 0.0;
	img->matrice[3][3] = 1.0;
}

double		**mult_mat(double **a, double **b)
{
	double	**t;
	int		i;

	i = 0;
	t = malloc_mat();
	while (i < 4)
	{
		t[i][0] = a[i][0] * b[0][0] + a[i][1] * b[1][0] + a[i][2] * b[2][0]
			+ a[i][3] * b[3][0];
		t[i][1] = a[i][0] * b[0][1] + a[i][1] * b[1][1] + a[i][2] * b[2][1]
			+ a[i][3] * b[3][1];
		t[i][2] = a[i][0] * b[0][2] + a[i][1] * b[1][2] + a[i][2] * b[2][2]
			+ a[i][3] * b[3][2];
		t[i][3] = a[i][0] * b[0][3] + a[i][1] * b[1][3] + a[i][2] * b[2][3]
			+ a[i][3] * b[3][3];
		i++;
	}
	return (t);
}

void		rot_x(t_img *img)
{
	img->rx = malloc_mat();
	img->rx[0][0] = 1.0;
	img->rx[0][1] = 0.0;
	img->rx[0][2] = 0.0;
	img->rx[0][3] = 0.0;
	img->rx[1][0] = 0.0;
	img->rx[1][1] = cos(img->rot);
	img->rx[1][2] = -sin(img->rot);
	img->rx[1][3] = 0.0;
	img->rx[2][0] = 0.0;
	img->rx[2][1] = sin(img->rot);
	img->rx[2][2] = cos(img->rot);
	img->rx[2][3] = 0.0;
	img->rx[3][0] = 0.0;
	img->rx[3][1] = 0.0;
	img->rx[3][2] = 0.0;
	img->rx[3][3] = 1.0;
}

void		rot_y(t_img *img)
{
	img->ry = malloc_mat();
	img->ry[0][0] = cos(img->rot);
	img->ry[0][1] = 0.0;
	img->ry[0][2] = sin(img->rot);
	img->ry[0][3] = 0.0;
	img->ry[1][0] = 0.0;
	img->ry[1][1] = 1.0;
	img->ry[1][2] = 0.0;
	img->ry[1][3] = 0.0;
	img->ry[2][0] = -sin(img->rot);
	img->ry[2][1] = 0.0;
	img->ry[2][2] = cos(img->rot);
	img->ry[2][3] = 0.0;
	img->ry[3][0] = 0.0;
	img->ry[3][1] = 0.0;
	img->ry[3][2] = 0.0;
	img->ry[3][3] = 1.0;
}

void		rot_z(t_img *img)
{
	img->rz = malloc_mat();
	img->rz[0][0] = cos(img->rot);
	img->rz[0][1] = -sin(img->rot);
	img->rz[0][2] = 0.0;
	img->rz[0][3] = 0.0;
	img->rz[1][0] = sin(img->rot);
	img->rz[1][1] = cos(img->rot);
	img->rz[1][2] = 0.0;
	img->rz[1][3] = 0.0;
	img->rz[2][0] = 0.0;
	img->rz[2][1] = 0.0;
	img->rz[2][2] = 1.0;
	img->rz[2][3] = 0.0;
	img->rz[3][0] = 0.0;
	img->rz[3][1] = 0.0;
	img->rz[3][2] = 0.0;
	img->rz[3][3] = 1.0;
}
