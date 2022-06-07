/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:41:14 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/05/30 22:01:03 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	pipex_loop(t_data *data, int i)
{
	if (i > 0)
	{
		dup2(data->fd[0], STDIN_FILENO);
		close(data->fd[0]);
	}
	if (pipe(data->fd) == -1)
		error(data, NULL);
	data->pid = fork();
	if (data->pid == -1)
		error(data, NULL);
	if (data->pid == 0)
	{
		if (i == 0 && data->fd_infile == -1)
			error(data, NULL);
		exec_cmd(data, i);
	}
}

void	pipex(t_data *data)
{
	int		i;
	pid_t	w;
	int		wstatus;

	dup2(data->fd_infile, STDIN_FILENO);
	close(data->fd_infile);
	i = 0;
	while (i < data->cmd_count)
	{
		pipex_loop(data, i);
		w = waitpid(data->pid, &wstatus, 0);
		if (w == -1)
			error(data, NULL);
		if (WIFEXITED(wstatus) && i == data->cmd_count - 1)
		{
			if (WEXITSTATUS(wstatus) != 0)
			{
				if (data != NULL && data->paths != NULL)
					clean_array(data->paths);
				exit(WEXITSTATUS(wstatus));
			}
		}
		close(data->fd[1]);
		i += 1;
	}
}

char	**get_paths(char *envp[])
{
	char	**it;
	char	**paths;

	it = envp;
	while (*it != NULL)
	{
		if (!ft_strncmp(*it, "PATH=", 5))
		{
			paths = ft_split((*it) + 5, ':');
			if (paths == NULL)
				return (NULL);
			return (paths);
		}
		it++;
	}
	return (NULL);
}

void	exec_cmd(t_data *data, int i)
{
	char	**cmd;
	char	*cmd_path;

	if (i == data->cmd_count - 1)
	{
		data->fd_outfile = open(
				data->argv[data->argc - 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0664);
		if (data->fd_outfile == -1)
			error(data, NULL);
		dup2(data->fd_outfile, STDOUT_FILENO);
	}
	else
		dup2(data->fd[1], STDOUT_FILENO);
	cmd = decode_cmd(data->argv[i + 2]);
	cmd_path = get_cmd_path(data, cmd[0]);
	if (cmd_path == NULL)
		error_cmd_not_found(data, cmd);
	close(data->fd_outfile);
	close(data->fd[1]);
	execve(cmd_path, cmd, data->envp);
	exit(EXIT_FAILURE);
}
