/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:52:50 by heinfalt          #+#    #+#             */
/*   Updated: 2016/12/21 12:52:51 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_hash_dot(char *shape)
{
	int		i;
	int		nbr_hash;
	int		nbr_dots;

	i = 0;
	if (!shape)
		ft_error();
	nbr_dots = 0;
	nbr_hash = 0;
	while (shape[i])
	{
		if (shape[i] != '#' && shape[i] != '.' && shape[i] != '\n')
			ft_error();
		nbr_hash += (shape[i] == '#' ? 1 : 0);
		nbr_dots += (shape[i++] == '.' ? 1 : 0);
	}
	if (nbr_dots != 12 || nbr_hash != 4)
		ft_error();
	return (1);
}

int			check_clmn_line(char *shape)
{
	int		i;
	int		check_line;
	int		check_clmn;

	i = 0;
	while (shape[i])
	{
		check_line = 0;
		while (check_line != 4)
		{
			check_clmn = 0;
			while (shape[i++] != '\n' && shape[i] != '\0')
				check_clmn++;
			if (check_clmn != 4)
				ft_error();
			check_line++;
		}
		i++;
	}
	return (1);
}

int			check_shapes(char **input, char **base_shapes)
{
	int		i;
	int		j;
	int		check;

	j = 0;
	i = 0;
	check = 0;
	while (check != 2)
	{
		while (input[i])
		{
			if (!base_shapes[j])
				ft_error();
			else if (ft_strstr(base_shapes[j++], trunc_shape(input[i])))
			{
				i++;
				j = 0;
			}
		}
		check++;
		input = side_inc_array(input);
		base_shapes = side_inc_array(base_shapes);
	}
	return (1);
}

int			check_insert(char *src, char *shape, char *map, int start)
{
	char	*check;
	int		i;

	i = 0;
	check = init_map(ft_strlen(map));
	while (shape[i] && map[start + i])
	{
		if (shape[i] == '#')
		{
			if (map[start + i] != '.')
				return (0);
			else if (map[start + i] == '.')
				check[start + i] = shape[i];
		}
		if ((size_t)(start + ft_strlen(shape)) > ft_strlen(map))
			return (0);
		i++;
	}
	if (ft_strstr(side_inc(src), trunc_shape(side_inc(check))))
	{
		free(check);
		return (1);
	}
	return (0);
}

void		check_arg_nbr(int argc)
{
	if (argc != 2)
	{
		ft_putstr("usage: ./a.out source_file.txt\n");
		exit(1);
	}
}
