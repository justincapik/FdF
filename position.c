/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 12:10:27 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/21 11:59:31 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <math.h>

t_v3d			get_vertex(t_v3d old_v, double **m)
{
	t_v3d vertex;

	vertex.x = (old_v.x * m[0][0] + old_v.y * m[0][1] + old_v.z * m[0][2])
		* m[3][3] + m[3][0];
	vertex.y = (old_v.x * m[1][0] + old_v.y * m[1][1] + old_v.z * m[1][2])
		* m[3][3] + m[3][1];
	vertex.z = (old_v.x * m[2][0] + old_v.y * m[2][1] + old_v.z * m[2][2])
		* m[3][3] + m[3][2];
	return (vertex);
}

static t_pixpos	transfo_iso(t_v3d tmp, t_img *img)
{
	t_pixpos	res;

	tmp = get_vertex(tmp, img->matrice);
	res.x = (int)((tmp.x - tmp.y) * cos(0.523599));
	res.y = (int)(-tmp.z + (tmp.x + tmp.y) * sin(0.523599));
	return (res);
}

static t_pixpos	transfo_para(t_v3d tmp, t_img *img)
{
	t_pixpos	res;

	tmp = get_vertex(tmp, img->matrice);
	res.x = (int)tmp.x;
	res.y = (int)(-tmp.z);
	return (res);
}

t_pixpos		get_todraw(t_v3 **data, int height, int width, t_img *img)
{
	t_pixpos	res;
	t_v3d		tmp;

	tmp.x = (double)data[height][width].x;
	tmp.y = (double)data[height][width].y;
	tmp.z = (double)data[height][width].z;
	if (img->transfo & iso)
		res = transfo_iso(tmp, img);
	else if (img->transfo & para)
		res = transfo_para(tmp, img);
	res.h = data[height][width].z;
	return (res);
}

int				get_color(int z)
{
	if (z <= -2)
		return (0x0000AA);
	else if (z <= 0)
		return (0x0000FF);
	else if (z <= 35)
		return (0x00A000);
	else if (z <= 90)
		return (0xA0522D);
	else
		return (0xFFFFFF);
}
