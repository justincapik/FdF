/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 10:43:18 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/30 09:45:48 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

void		free_data(t_list **data)
{
	t_list *tmp;

	tmp = *data;
	while (tmp != NULL)
	{
		free(tmp->content);
		tmp = tmp->next;
		free(*data);
		*data = tmp;
	}
}

void		free_img(t_img *img)
{
	int	i;

	i = 0;
	if (img->data != NULL)
	{
		while (img->data[i] != NULL)
		{
			free(img->data[i]);
			++i;
		}
	}
	free(img->data);
	free_mat(img->rx);
	free_mat(img->ry);
	free_mat(img->rz);
	if (img->mlx_ptr != NULL)
		mlx_destroy_window(img->mlx_ptr, img->win_ptr);
}
