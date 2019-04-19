/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 13:26:07 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/21 11:19:08 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#include <stdlib.h>

double	**malloc_mat(void)
{
	double	**m;
	int		i;

	i = 0;
	m = (double **)malloc(sizeof(double *) * 4);
	while (i < 4)
		m[i++] = (double *)malloc(sizeof(double) * 4);
	return (m);
}

void	free_mat(double **m)
{
	int i;

	i = 0;
	while (i < 4)
		free(m[i++]);
	free(m);
	m = NULL;
}
