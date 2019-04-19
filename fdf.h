/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 11:19:26 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/30 14:58:54 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <mlx.h>
# include <unistd.h>
# define HEIGHT 1400
# define WIDTH 1800

typedef struct	s_vecteur_3
{
	int x;
	int y;
	int z;
}				t_v3;

typedef struct	s_vecteur_3_double
{
	double x;
	double y;
	double z;
}				t_v3d;

typedef struct	s_pixel_pos
{
	int x;
	int y;
	int h;
}				t_pixpos;

typedef struct	s_pixel_pos_double
{
	double x;
	double y;
}				t_pixposd;

typedef	enum	e_transformation
{
	iso = 1,
	para = 2,
	conique = 4
}				t_transfo;

typedef struct	s_imginfo
{
	void		*win_ptr;
	void		*mlx_ptr;
	t_v3		**data;
	int			*val;
	int			fd;
	void		*ptr;
	double		**matrice;
	double		**rx;
	double		**ry;
	double		**rz;
	int			transfo;
	double		anglex;
	double		angley;
	double		anglez;
	double		rot;
	double		zoom;
	double		dezoom;
}				t_img;

int				check_line(char *line, int i);
t_v3			**imgtodata(int imf_fd);
t_v3d			get_vertex(t_v3d old_v, double **m);
void			put_img(void *mlx_ptr, void *win_ptr, t_v3 **data, t_img *img);
t_pixpos		get_todraw(t_v3 **data, int height, int width, t_img *img);
int				get_color(int z);
void			draw_at_pix(t_img *img, int x, int y, int color);
void			draw_line(t_img *img, t_pixpos p0, t_pixpos p1);
void			init_matrice(t_img *img);
double			**mult_mat(double **a, double **b);
double			**malloc_mat();
void			free_mat(double **m);
void			free_data(t_list **data);
void			free_img(t_img *img);
void			rot_x(t_img *img);
void			rot_y(t_img *img);
void			rot_z(t_img *img);
int				key_press(int keycode, void *param);
void			key_up(t_img *img);
void			key_left(t_img *img);
void			key_right(t_img *img);
void			key_down(t_img *img);
void			key_i(t_img *img);
void			key_o(t_img *img);
void			key_p(t_img *img);
void			key_k(t_img *img);
void			key_l(t_img *img);
void			key_m(t_img *img);
void			key_y(t_img *img);
void			key_u(t_img *img);
void			key_j(t_img *img);

#endif
