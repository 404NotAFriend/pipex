/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:00:33 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/02/02 19:49:19 by bramalho@st      ###   ########.fr       */
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

void exec(t_pipex *data)
{

}
