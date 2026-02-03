/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 06:36:49 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/02/02 23:57:50 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_one(t_pipex *data)
{
	dup2(data->infile, STDIN_FILENO);
	dup2(data->pipe_fd[1], STDOUT_FILENO);
	close(data->pipe_fd[0]);
	close_fds(data);
	data->i = 2;
	exec(data);
}

void	child_two(t_pipex *data)
{
	dup2(data->pipe_fd[0], STDIN_FILENO);
	dup2(data->outfile, STDOUT_FILENO);
	close(data->pipe_fd[1]);
	close_fds(data);
	data->i = 3;
	exec(data);
}

static void	init_pipex(t_pipex *data, int ac, char **av, char **envp)
{
	data->ac = ac;
	data->av = av;
	data->envp = envp;
	data->infile = open_file(av[1], 0);
	data->outfile = open_file(av[4], 1);
	data->cmd_args = NULL;
	data->cmd_path = NULL;
	data->cmd_paths = NULL;
	parse_cmds(data);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	data;
	pid_t	pid1;
	pid_t	pid2;

	if (ac != 5)
		return (ft_putstr_fd("Error: Invalid arguments\n", 2), 1);
	init_pipex(&data, ac, av, envp);
	if (pipe(data.pipe_fd) == -1)
		msg_error("Pipe failed");
	pid1 = fork();
	if (pid1 == 0)
		child_one(&data);
	pid2 = fork();
	if (pid2 == 0)
		child_two(&data);
	close_fds(&data);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	parent_free(&data);
	return (0);
}
