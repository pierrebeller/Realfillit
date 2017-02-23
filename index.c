/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_manip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 12:18:02 by heinfalt          #+#    #+#             */
/*   Updated: 2017/01/05 12:18:03 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_nbr_shape(char **shapes)
{
	int i;

	i = 0;
	while (shapes[i])
		i++;
	return (i);
}

int		get_side_shape(char *shape)
{
	int len;
	int root;

	len = ft_strlen(shape);
	root = 2;
	while (root * root != len)
		root++;
	return (root);
}
