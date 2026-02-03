/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:05:13 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/02/03 02:36:50 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	child_process(t_pipex *data)
{
	pid_t	pid;
	int		fd[2];
	int		input_fd;

	if (pipe(fd) == -1)
		msg_error("Pipe failed");
	pid = fork();
	if (pid == -1)
		msg_error("Fork failed");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		if (data->i == 2)
		{
			input_fd = open(data->av[1], O_RDONLY);
			if (input_fd != -1)
				dup2(input_fd, STDIN_FILENO);
		}
		exec(data);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
}

static void	handle_input(t_pipex *data, int ac, char **av)
{
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		data->i = 3;
		data->outfile = open_file(av[ac - 1], 2);
		if (data->outfile == -1)
			exit(1);
		here_doc(av[2], ac);
	}
	else
	{
		data->i = 2;
		data->outfile = open_file(av[ac - 1], 1);
		if (data->outfile == -1)
			exit(1);
		data->infile = open_file(av[1], 0);
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

static int	execute_last_command(t_pipex *data)
{
	pid_t	last_pid;
	int		status;

	last_pid = fork();
	if (last_pid == 0)
	{
		setup_output_redirect(data->outfile);
		exec(data);
	}
	if (data->outfile != -1)
		close(data->outfile);
	waitpid(last_pid, &status, 0);
	parent_free(data);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
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
	return (execute_last_command(&data));
}
