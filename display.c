/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 13:03:58 by heinfalt          #+#    #+#             */
/*   Updated: 2017/01/30 13:03:59 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		display_map(char *map)
{
	int		count;
	int		side;
	int		i;

	i = 0;
	count = 0;
	side = get_side_shape(map);
	while (map[i])
	{
		if (count == side)
		{
			ft_putchar('\n');
			count = 0;
		}
		ft_putchar(map[i]);
		i++;
		count++;
	}
	ft_putchar('\n');
}

char		**put_id(char **shapes)
{
	char	id;
	int		i;
	int		j;

	id = 65;
	i = 0;
	if (!shapes)
		return (NULL);
	while (shapes[i])
	{
		j = 0;
		while (shapes[i][j])
		{
			if (shapes[i][j] == '#')
				shapes[i][j] = (char)(id + i);
			j++;
		}
		i++;
	}
	return (shapes);
}

char		*remove_id(char *shape)
{
	int		i;

	i = 0;
	if (!shape)
		return (NULL);
	while (shape[i])
	{
		if (ft_isalpha(shape[i]))
			shape[i] = '#';
		i++;
	}
	return (shape);
}
