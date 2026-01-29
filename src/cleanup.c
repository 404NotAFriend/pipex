/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:02:00 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/01/29 19:05:58 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	close_fds(t_pipex *data)
{
	if (data->infile != -1)
		close(data->infile);
	if (data->outfile != -1)
		close(data->outfile);
	if (data->pipe_fd[0] != -1)
		close(data->pipe_fd[0]);
	if (data->pipe_fd[1] != -1)
		close(data->pipe_fd[1]);
}

void	parents_free(t_pipex *data)
{
	int	i;

	close_fds(data);
	i = 0;
	if (data->cmd_args)
	{
		while (data->cmd_args[i])
		{
			free(data->cmd_args[i]);
			i++;
		}
		free(data->cmd_args);
	}
	i = 0;
	if (data->cmd_paths[i])
	{
		while (data->cmd_paths[i])
		{
			free(data->cmd_paths[i]);
			i++;
		}
		free(data->cmd_paths);
	}
	if (data->cmd_path)
		free(data->cmd_path);
}
