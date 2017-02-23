/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 12:10:09 by heinfalt          #+#    #+#             */
/*   Updated: 2017/01/19 12:10:11 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(1);
}

void	ft_free_error(void *elem)
{
	free(elem);
	ft_putstr("error\n");
	exit(1);
}
