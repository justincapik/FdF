/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 15:08:02 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/30 15:00:51 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"

#include <stdio.h>

static int		get_size_line(char *line)
{
	static int	old_size = -1;
	int			nbarg;
	int			i;

	i = 0;
	nbarg = 0;
	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
		++i;
	while (line[i] != '\0')
	{
		if ((i = check_line(line, i)) == -1)
			return (-1);
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
			return (-1);
		while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
			++i;
		++nbarg;
	}
	if (old_size != nbarg && old_size != -1)
		return (-1);
	return (old_size = nbarg);
}

static int		*get_int_line(char *line)
{
	int		*tab;
	int		nbarg;
	int		i;
	int		j;

	if ((nbarg = get_size_line(line)) == -1)
		return (NULL);
	if ((tab = (int *)malloc(sizeof(int) * (nbarg + 1))) == NULL)
		return (NULL);
	tab[0] = nbarg;
	i = 0;
	j = 1;
	while (j < nbarg + 1)
	{
		while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
			++i;
		tab[j] = ft_atoi(&(line[i]));
		tab[j] = (tab[j] > 10000) ? 10000 : tab[j];
		tab[j] = (tab[j] < -10000) ? -10000 : tab[j];
		while ((line[i] != ' ' && line[i] != '\t') && line[i] != '\0')
			++i;
		++j;
	}
	return (tab);
}

static t_list	*get_one_t_list(char *line)
{
	t_list	*comp;
	int		*tab;

	if (line == NULL)
		return (NULL);
	if ((tab = get_int_line(line)) == NULL)
	{
		free(tab);
		return (NULL);
	}
	if ((comp = ft_lstnew(NULL, sizeof(int) * (tab[0] + 1))) == NULL)
		return (NULL);
	free(comp->content);
	comp->content = (void *)tab;
	return (comp);
}

t_v3			**datatov3(t_list *data)
{
	t_v3	**ret;
	int		y;
	int		x;
	int		*tab;

	ret = (t_v3 **)malloc(sizeof(t_v3) * (ft_lstsize(data) + 1));
	y = 0;
	while (data != NULL)
	{
		tab = (int *)data->content;
		ret[y] = (t_v3 *)malloc(sizeof(t_v3) * (tab[0] + 1));
		ret[y][0].z = tab[0] + 1;
		x = 1;
		while (x < tab[0] + 1)
		{
			ret[y][x].z = tab[x];
			ret[y][x].x = x;
			ret[y][x++].y = y;
		}
		++y;
		data = data->next;
	}
	ret[y] = NULL;
	return (ret);
}

t_v3			**imgtodata(int img_fd)
{
	char	*line;
	t_list	*data;
	t_list	*curr;
	t_list	*tmp;
	t_v3	**ret;

	get_next_line(img_fd, &line);
	if ((data = get_one_t_list(line)) == NULL)
		return (NULL);
	free(line);
	curr = data;
	while (get_next_line(img_fd, &line) != 0 && ft_strcmp(line, "") != 0)
	{
		if ((tmp = get_one_t_list(line)) == NULL)
			return (NULL);
		curr->next = tmp;
		curr = tmp;
		free(line);
	}
	free(line);
	curr->next = NULL;
	ret = datatov3(data);
	free_data(&data);
	return (ret);
}
