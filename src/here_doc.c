/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:01:44 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/02/03 00:13:21 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	read_input(char *limiter, int *fd)
{
	char	*line;

	close(fd[0]);
	while (1)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			free(line);
			exit(0);
		}
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
}

void	here_doc(char *limiter, int ac)
{
	pid_t	pid;
	int		fd[2];

	if (ac < 6)
		msg_error("Invalid number of arguments");
	if (pipe(fd) == -1)
		msg_error("Pipe failed");
	pid = fork();
	if (pid == 0)
		read_input(limiter, fd);
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}
