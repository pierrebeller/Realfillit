/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:39:55 by heinfalt          #+#    #+#             */
/*   Updated: 2016/11/29 11:39:56 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

# define BUFF_SIZE 1024

void				ft_error(void);
void				ft_close(int fd);
int					ft_open(char *file);
char				**ft_build(char *file);
void				ft_free_error(void *elem);

void				check_arg_nbr(int argc);
int					check_hash_dot(char *shape);
int					check_clmn_line(char *shape);
int					check_shapes(char **input, char **base_shapes);
int					check_insert(char *src, char *shape, char *map, int start);

char				**reduce(char **input);
int					empty_clmn(char *shape);
int					empty_line(char *shape);
char				**side_red(char **input, int *line, int *clmn, char ***cpy);

void				do_map(char **input);
char				*init_map(size_t size);
char				**put_id(char **shapes);
char				*remove_id(char *shape);
int					*init_start(size_t size);
char				*remove_shape(char *map, int piece);
char				*solve(char **input, char **dup, char *map, int *start);
char				*insert_shape(char *shape, char *map, int start, int piece);

int					get_side_shape(char *shape);
int					get_nbr_shape(char **shapes);

char				*side_inc(char *src);
char				*remove_endl(char *buf);
char				*trunc_shape(char *shape);
char				**ft_arraydup(char **src);
char				**trunc_array(char **array);
char				**side_inc_array(char **src);

void				display_map(char *map);

#endif
