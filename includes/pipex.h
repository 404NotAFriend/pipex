/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 06:37:07 by bramalho@st       #+#    #+#             */
/*   Updated: 2026/02/02 23:50:12 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* ========================================================================== */
/*                              INCLUDES                                      */
/* ========================================================================== */

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>

/* ========================================================================== */
/*                              ERROR MESSAGES                                */
/* ========================================================================== */

# define ERR_ARGS "Invalid number of arguments"
# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_PIPE "Pipe"
# define ERR_CMD "Command not found"

/* ========================================================================== */
/*                              MAIN  STRUCTURE                               */
/* ========================================================================== */

typedef struct s_pipex
{
	char	**envp;
	char	**av;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd_path;
	int		ac;
	int		here_doc;
	int		infile;
	int		outfile;
	int		pipe_fd[2];
	int		i;

}	t_pipex;

/* ========================================================================== */
/*                              INITIALIZATION                                */
/* ========================================================================== */

int		open_file(char *file, int mode);

/* ========================================================================== */
/*                                 PARSING                                    */
/* ========================================================================== */

char	*find_path(char **envp);
void	parse_cmds(t_pipex *data);

/* ========================================================================== */
/*                                EXECUTION                                   */
/* ========================================================================== */

void	exec(t_pipex *data);

/* ========================================================================== */
/*                              CLEANUP & EXIT                                */
/* ========================================================================== */

void	parent_free(t_pipex *data);
void	close_fds(t_pipex *data);
void	msg_error(char *str);

#endif
