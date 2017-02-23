/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 12:26:33 by heinfalt          #+#    #+#             */
/*   Updated: 2017/01/05 12:26:34 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**trunc_array(char **array)
{
	int		i;

	i = 0;
	if (!array)
		return (NULL);
	while (array[i])
	{
		array[i] = trunc_shape(array[i]);
		i++;
	}
	return (array);
}

char		*trunc_shape(char *shape)
{
	int		start;
	int		end;

	if (!shape)
		return (NULL);
	start = 0;
	end = ft_strlen(shape);
	while (shape[start] != '#')
		start++;
	while (shape[end] != '#')
		end--;
	shape = ft_strsub(shape, start, (end + 1) - start);
	return (shape);
}

char		**ft_arraydup(char **src)
{
	char	**cpy;
	int		i;

	i = 0;
	cpy = (char **)ft_memalloc(sizeof(char *) * get_nbr_shape(src) + 1);
	if (!cpy)
		ft_free_error(cpy);
	while (src[i])
	{
		cpy[i] = ft_strdup(src[i]);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

char		**side_inc_array(char **src)
{
	char	**cpy;
	int		i;

	i = 0;
	if (!src)
		return (NULL);
	cpy = ft_arraydup(src);
	while (cpy[i])
	{
		cpy[i] = side_inc(cpy[i]);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

char		*side_inc(char *shape)
{
	char	*cpy;
	int		j;
	int		k;
	int		side;

	j = 0;
	k = 0;
	if (!shape)
		ft_error();
	side = get_side_shape(shape);
	cpy = (char *)ft_memalloc(sizeof(char) * ((side * 2) + (side * side) + 2));
	if (!cpy)
		ft_free_error(cpy);
	while (j < ((side * 2) + (side * side) + 1))
	{
		if ((j + 1) % (side + 1) == 0 || !shape[k])
			cpy[j++] = '.';
		else
			cpy[j++] = shape[k++];
	}
	cpy[j] = '\0';
	return (cpy);
}
