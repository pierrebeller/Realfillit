/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:59:29 by heinfalt          #+#    #+#             */
/*   Updated: 2017/01/09 12:59:30 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		do_map(char **input)
{
	char	*map;

	map = init_map(ft_strlen(input[0]));
	map = solve(input, trunc_array(ft_arraydup(input)), map,\
	init_start(get_nbr_shape(input)));
	display_map(map);
}

char		*init_map(size_t size)
{
	char	*map;
	size_t	i;

	i = 0;
	map = (char *)ft_memalloc(sizeof(char) * (size + 1));
	while (i < size)
		map[i++] = '.';
	map[i] = '\0';
	return (map);
}

int			*init_start(size_t size)
{
	int		*start;
	int		i;

	i = 0;
	start = (int *)ft_memalloc(sizeof(int) * (size + 1));
	while (start[i])
		start[i++] = 0;
	return (start);
}

char		*insert_shape(char *shape, char *map, int start, int piece)
{
	int		i;

	i = 0;
	if (!shape || !map)
		return (NULL);
	while (map[start + i] && shape[i])
	{
		if (shape[i] == '#')
			map[start + i] = (char)(65 + piece);
		i++;
	}
	return (map);
}

char		*remove_shape(char *map, int piece)
{
	int		i;

	i = 0;
	if (!map)
		return (NULL);
	while (map[i])
	{
		if (map[i] == (char)(65 + piece))
			map[i] = '.';
		i++;
	}
	return (map);
}
