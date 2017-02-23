/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 12:16:33 by heinfalt          #+#    #+#             */
/*   Updated: 2017/01/05 12:16:36 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	char	*cpy_wout_endl(char *src, char *dest)
{
	int			i;
	int			j;
	int			count;

	i = 0;
	j = 0;
	count = 0;
	while (src[i])
	{
		if (src[i] == '\n')
		{
			count++;
			if (count == 5)
			{
				dest[j++] = src[i++];
				count = 0;
			}
			else
				i++;
		}
		else
			dest[j++] = src[i++];
	}
	return (dest);
}

char			*remove_endl(char *buf)
{
	char		*ret;
	int			i;
	int			nbr_endl;

	i = 0;
	nbr_endl = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			nbr_endl++;
			while (buf[i] == '\n')
				i++;
		}
		else
			i++;
	}
	ret = (char *)ft_memalloc(sizeof(char) * (i - nbr_endl + 1));
	ret = cpy_wout_endl(buf, ret);
	return (ret);
}
