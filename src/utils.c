/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:05:28 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/29 18:35:15 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	open_file(char *file, int mode)
{
	int	fd;

	if (mode == 0)
	{
		if (access(file, F_OK | R_OK) == -1)
			msg_error(file);
		fd = open(file, O_RDONLY);
	}
	else if (mode == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		msg_error(file);
	return (fd);
}

void	msg_error(char *str)
{
	perror(str);
	exit(1);
}
