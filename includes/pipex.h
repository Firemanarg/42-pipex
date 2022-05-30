/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:41:23 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/05/30 20:25:38 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# include "libft_x.h"

typedef struct s_data
{
	pid_t	pid;
	int		fd[2];
	int		fd_infile;
	int		fd_outfile;
	int		argc;
	char	**argv;
	char	**envp;
	int		cmd_count;
	char	**paths;
}	t_data;

void	pipex(t_data *data);
char	**get_paths(char *envp[]);
int		clean_array(char **paths);
void	error(t_data *data, char **cmd);
void	error_cmd_not_found(t_data *data, char **cmd);
char	*get_cmd_path(t_data *data, char *cmd);
char	**decode_cmd(char *cmd);
void	exec_cmd(t_data *data, int i);
void	init_data(t_data *data);

#endif
