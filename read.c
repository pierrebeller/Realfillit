/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:19:17 by heinfalt          #+#    #+#             */
/*   Updated: 2017/02/02 14:10:22 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_open(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY | O_CREAT, 0777);
	if (fd == -1)
		ft_error();
	return (fd);
}

void		ft_close(int fd)
{
	fd = close(fd);
	if (fd == -1)
		ft_error();
}

char		**ft_build(char *file)
{
	char	*buf;
	int		ret;
	int		fd;

	buf = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE);
	fd = ft_open(file);
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret--] = '\0';
	ft_close(fd);
	fd = 0;
	while (buf[ret--] == '\n')
		fd++;
	if (check_clmn_line(buf) && fd == 1)
		return (ft_strsplit(remove_endl(buf), '\n'));
	else
		ft_error();
	return (NULL);
}
