/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:24:38 by heinfalt          #+#    #+#             */
/*   Updated: 2017/02/02 16:24:39 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**reduce(char **input)
{
	int		i;
	int		*tab_line;
	int		*tab_clmn;
	int		nbr_shape;
	char	**cpy;

	i = 0;
	nbr_shape = get_nbr_shape(input);
	tab_clmn = (int *)ft_memalloc(sizeof(int) * nbr_shape);
	tab_line = (int *)ft_memalloc(sizeof(int) * nbr_shape);
	while (input[i])
	{
		tab_clmn[i] = empty_clmn(input[i]);
		tab_line[i] = empty_line(input[i]);
		if (!tab_clmn[i] || !tab_line[i])
			return (input);
		i++;
	}
	if (nbr_shape > 2)
		return (input);
	return (side_red(input, tab_line, tab_clmn, &cpy));
}

char		**side_red(char **input, int *line, int *clmn, char ***cpy)
{
	int		i;
	int		j;
	int		k;
	int		side;

	i = 0;
	cpy = (char ***)ft_memalloc(sizeof(char *) * get_nbr_shape(input) + 1);
	while (input[i])
	{
		j = 0;
		k = 0;
		side = get_side_shape(input[i]);
		cpy[i] = (char **)ft_memalloc(sizeof(char) * (side - 1)\
		* (side - 1) + 1);
		while (input[i][j])
		{
			if (j % side == clmn[i] - 1 || (j >= (side * (line[i] - 1)) &&\
			j <= (side * line[i]) - 1))
				j++;
			else
				cpy[i][k++] = &input[i][j++];
		}
		*cpy[i++][k] = '\0';
	}
	return (*cpy);
}

int			empty_line(char *shape)
{
	int		i;
	int		empty;
	int		line;
	int		side;

	i = 0;
	empty = 0;
	side = get_side_shape(shape);
	while (shape[i])
	{
		line = 0;
		while (line < side && i < (side * side) + 1)
		{
			if (shape[i + line] == '.')
				line++;
			else
			{
				i += side;
				empty++;
			}
		}
		if (line == side)
			return (empty + 1);
	}
	return (0);
}

int			empty_clmn(char *shape)
{
	int		i;
	int		j;
	int		empty;

	i = 0;
	j = 0;
	empty = 0;
	while (shape[i + j] && i < get_side_shape(shape))
	{
		if (shape[i + j] == '.')
		{
			j += get_side_shape(shape);
			empty++;
			if (empty == get_side_shape(shape))
				return (i + 1);
		}
		else
		{
			i++;
			j = 0;
			empty = 0;
		}
	}
	return (0);
}
