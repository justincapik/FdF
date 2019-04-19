/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:49:44 by jucapik           #+#    #+#             */
/*   Updated: 2019/01/30 15:03:04 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_line(char *line, int i)
{
	if (line[i] == '-' || line[i] == '+')
		++i;
	if (line[i] < '0' || line[i] > '9')
		return (-1);
	while (line[i] >= '0' && line[i] <= '9')
		++i;
	if (line[i] == ',')
	{
		++i;
		if (line[i++] != '0')
			return (-1);
		if (line[i] != 'X' && line[i] != 'x')
			return (-1);
		++i;
		if (!((line[i] >= '0' && line[i] <= '9')
				|| (line[i] >= 'a' && line[i] <= 'z')
				|| (line[i] >= 'A' && line[i] <= 'Z')))
			return (-1);
		while ((line[i] >= '0' && line[i] <= '9')
				|| (line[i] >= 'a' && line[i] <= 'z')
				|| (line[i] >= 'A' && line[i] <= 'Z'))
			++i;
	}
	return (i);
}
