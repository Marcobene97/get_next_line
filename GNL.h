/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenedet <mbenedet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:52:59 by mbenedet          #+#    #+#             */
/*   Updated: 2025/12/02 13:59:06 by mbenedet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# define BUFFER_SIZE 5


# include <ctype.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h> //error handling

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(const char *string);
char	*ft_strjoin_gnl(char *stash, char *buffer);
int find_newline(char *stash);

#endif
