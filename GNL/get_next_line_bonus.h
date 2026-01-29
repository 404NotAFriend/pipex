/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:46:41 by bramalho          #+#    #+#             */
/*   Updated: 2025/11/13 14:15:20 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define FD_MAX 1024

char	*get_next_line(int fd);
size_t	ft_strlgnl(const char *str);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strjoin_free(char *s1, char *s2);
void	new_buffer(char *buffer);

#endif
