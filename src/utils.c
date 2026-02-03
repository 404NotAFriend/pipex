/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:05:28 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/02/03 02:37:11 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	open_file(char *file, int mode)
{
	int	fd;

	if (mode == 0)
		fd = open(file, O_RDONLY);
	else if (mode == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		perror(file);
	return (fd);
}

void	setup_output_redirect(int outfile_fd)
{
	int	null_fd;

	if (outfile_fd == -1)
	{
		null_fd = open("/dev/null", O_WRONLY);
		dup2(null_fd, STDOUT_FILENO);
		close(null_fd);
	}
	else
		dup2(outfile_fd, STDOUT_FILENO);
	if (outfile_fd != -1)
		close(outfile_fd);
}

void	setup_input_redirect(int infile_fd)
{
	if (infile_fd != -1)
		dup2(infile_fd, STDIN_FILENO);
}

void	msg_error(char *str)
{
	perror(str);
	exit(1);
}
