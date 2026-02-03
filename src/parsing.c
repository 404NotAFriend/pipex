/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:00:13 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/02/02 23:47:09 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*find_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

void	parse_cmds(t_pipex *data)
{
	char	*path_env;

	path_env = find_path(data->envp);
	if (!path_env)
		return ;
	data->cmd_paths = ft_split(path_env, ':');
	if (!data->cmd_paths)
	{
		parent_free(data);
		msg_error("Pipex: Malloc failed");
	}
}
