/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:41:21 by bramalho          #+#    #+#             */
/*   Updated: 2025/11/13 15:13:01 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlgnl(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	return (len);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

static void	copy_strings(char *result, char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	len1 = 0;
	if (s1)
		len1 = ft_strlgnl(s1);
	len2 = ft_strlgnl(s2);
	i = 0;
	while (s1 && i < len1)
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && j < len2)
		result[i++] = s2[j++];
	result[i] = '\0';
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	len1 = 0;
	if (s1)
		len1 = ft_strlgnl(s1);
	len2 = ft_strlgnl(s2);
	result = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!result)
		return (free(s1), NULL);
	copy_strings(result, s1, s2);
	free(s1);
	return (result);
}

void	new_buffer(char *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	j = 0;
	while (buffer[i + j])
	{
		buffer[j] = buffer[i + j];
		j++;
	}
	while (j < BUFFER_SIZE)
	{
		buffer[j] = '\0';
		j++;
	}
}
