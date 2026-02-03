/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:00:33 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/02/03 02:37:34 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*get_cmd(char **paths, char *cmd)
{
	char	*temp_path;
	char	*full_path;
	int		i;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	i = 0;
	while (paths && paths[i])
	{
		temp_path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(temp_path, cmd);
		free(temp_path);
		if (access(full_path, F_OK | X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

static void	free_cmd_args(char **cmd_args)
{
	int	i;

	i = 0;
	if (!cmd_args)
		return ;
	while (cmd_args[i])
	{
		free(cmd_args[i]);
		i++;
	}
	free(cmd_args);
}

void	exec(t_pipex *data)
{
	if (!data->av[data->i] || data->av[data->i][0] == '\0')
	{
		ft_putendl_fd("pipex: command not found: ", 2);
		exit(127);
	}
	data->cmd_args = ft_split(data->av[data->i], ' ');
	data->cmd_path = get_cmd(data->cmd_paths, data->cmd_args[0]);
	if (!data->cmd_path)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(data->cmd_args[0], 2);
		free_cmd_args(data->cmd_args);
		child_free(data);
		exit(127);
	}
	if (execve(data->cmd_path, data->cmd_args, data->envp) == -1)
	{
		free_cmd_args(data->cmd_args);
		free(data->cmd_path);
		msg_error("pipex: execve failed");
	}
}
