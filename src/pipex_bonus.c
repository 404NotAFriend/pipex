/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:05:13 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/02/03 00:19:41 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	child_process(t_pipex *data)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		msg_error("Pipe failed");
	pid = fork();
	if (pid == -1)
		msg_error("Fork failed");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		exec(data);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

static void	handle_input(t_pipex *data, int ac, char **av)
{
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		data->i = 3;
		data->outfile = open_file(av[ac - 1], 2);
		here_doc(av[2], ac);
	}
	else
	{
		data->i = 2;
		data->outfile = open_file(av[ac - 1], 1);
		data->infile = open_file(av[1], 0);
		dup2(data->infile, STDIN_FILENO);
	}
}

static void	init_bonus(t_pipex *data, int ac, char **av, char **envp)
{
	data->ac = ac;
	data->av = av;
	data->envp = envp;
	data->cmd_args = NULL;
	data->cmd_path = NULL;
	data->cmd_paths = NULL;
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	data;

	if (ac < 5)
		return (msg_error("Invalid number of arguments"), 1);
	init_bonus(&data, ac, av, envp);
	handle_input(&data, ac, av);
	parse_cmds(&data);
	while (data.i < ac - 2)
	{
		child_process(&data);
		data.i++;
	}
	dup2(data.outfile, STDOUT_FILENO);
	exec(&data);
	parent_free(&data);
	return (0);
}
