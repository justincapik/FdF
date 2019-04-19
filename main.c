/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 11:18:39 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/30 09:43:47 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <mlx.h>

static void	usage(t_img *img)
{
	free_img(img);
	(void)img;
	ft_putstr("usage: ./fdf image.fdf\n");
	exit(1);
}

int			main(int ac, char **av)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	img->matrice = NULL;
	img->data = NULL;
	img->mlx_ptr = NULL;
	init_matrice(img);
	rot_x(img);
	rot_y(img);
	rot_z(img);
	if ((img->fd = open(av[1], O_RDONLY)) < 0)
		usage(img);
	if ((img->data = imgtodata(img->fd)) == NULL)
		usage(img);
	if ((img->mlx_ptr = mlx_init()) == NULL)
		return (0);
	if ((img->win_ptr = mlx_new_window(img->mlx_ptr, WIDTH, HEIGHT, "FdF"))
			== NULL)
		return (0);
	put_img(img->mlx_ptr, img->win_ptr, img->data, img);
	mlx_hook(img->win_ptr, 2, 0, key_press, img);
	mlx_loop(img->mlx_ptr);
	(void)ac;
	return (0);
}
