/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 10:43:49 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/30 15:19:11 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <mlx.h>

void		draw_at_pix(t_img *img, int x, int y, int color)
{
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
		img->val[y * WIDTH + x] = color;
}

static int	*get_c_img(void *img_ptr)
{
	char	*c_img;
	int		bpp;
	int		sl;
	int		endian;

	c_img = mlx_get_data_addr(img_ptr, &bpp, &sl, &endian);
	return ((int *)c_img);
}

static void	fill_img_helper(t_img *img, t_v3 **data, int i)
{
	int			j;
	t_pixpos	todraw;
	t_pixpos	tmp;

	j = 1;
	while (j < data[i][0].z - 1)
	{
		todraw = get_todraw(data, i, j, img);
		tmp = get_todraw(data, i, j + 1, img);
		draw_line(img, todraw, tmp);
		tmp = get_todraw(data, i + 1, j, img);
		draw_line(img, todraw, tmp);
		++j;
	}
	todraw = get_todraw(data, i, j, img);
	tmp = get_todraw(data, i + 1, j, img);
	draw_line(img, todraw, tmp);
}

static void	fill_img(t_img *img, t_v3 **data)
{
	int			i;
	int			j;
	t_pixpos	todraw;
	t_pixpos	tmp;

	i = 0;
	todraw = get_todraw(data, 0, 1, img);
	draw_at_pix(img, todraw.x, todraw.y, get_color(10));
	while (data[i + 1] != NULL)
	{
		fill_img_helper(img, data, i);
		++i;
	}
	j = 1;
	while (j < data[i][0].z - 1)
	{
		todraw = get_todraw(data, i, j, img);
		tmp = get_todraw(data, i, j + 1, img);
		draw_line(img, todraw, tmp);
		++j;
	}
}

void		put_img(void *mlx_ptr, void *win_ptr, t_v3 **data, t_img *img)
{
	mlx_clear_window(mlx_ptr, win_ptr);
	img->ptr = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	img->val = get_c_img(img->ptr);
	fill_img(img, data);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img->ptr, 0, 0);
	mlx_destroy_image(mlx_ptr, img->ptr);
}
