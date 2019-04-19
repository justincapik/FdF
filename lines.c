/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:41:58 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/21 10:29:40 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

static void	x_mov(t_img *img, t_pixpos p0, t_pixpos p1)
{
	float		slope;
	float		pitch;
	t_pixposd	d;
	t_pixposd	s;
	int			pasz;

	d.x = p1.x - p0.x;
	s.x = (d.x < 0) ? -1 : 1;
	d.y = p1.y - p0.y;
	s.y = (d.y < 0) ? -1 : 1;
	slope = d.y / d.x;
	pitch = p0.y - slope * p0.x;
	if (p0.x - p1.x != 0)
		pasz = ft_abs(p0.h - p1.h) / ft_abs(p0.x - p1.x);
	while (p0.x != p1.x)
	{
		draw_at_pix(img, p0.x, (int)(slope * p0.x + pitch),
				get_color(p0.h));
		p0.x += s.x;
		p0.h += s.x * pasz;
	}
}

static void	y_mov(t_img *img, t_pixpos p0, t_pixpos p1)
{
	float		slope;
	float		pitch;
	t_pixposd	d;
	t_pixposd	s;
	int			pasz;

	d.x = p1.x - p0.x;
	s.x = (d.x < 0) ? -1 : 1;
	d.y = p1.y - p0.y;
	s.y = (d.y < 0) ? -1 : 1;
	slope = d.x / d.y;
	pitch = p0.x - slope * p0.y;
	if (p0.y - p1.y != 0)
		pasz = ft_abs(p0.h - p1.h) / ft_abs(p0.y - p1.y);
	while (p0.y != p1.y)
	{
		draw_at_pix(img, (int)(slope * p0.y + pitch), p0.y,
				get_color(p0.h));
		p0.y += s.y;
		p0.h += s.y * pasz;
	}
}

void		draw_line(t_img *img, t_pixpos p0, t_pixpos p1)
{
	t_pixposd	d;
	t_pixpos	s;

	d.x = p1.x - p0.x;
	s.x = (d.x < 0) ? -1 : 1;
	d.y = p1.y - p0.y;
	s.y = (d.y < 0) ? -1 : 1;
	if (ft_abs(d.y) < ft_abs(d.x))
		x_mov(img, p0, p1);
	else
		y_mov(img, p0, p1);
}
