/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_decoder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:41:00 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/05/30 20:25:23 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*build_cmd_path(char *path, char *cmd);

char	**decode_cmd(char *arg)
{
	int		i;
	char	**cmd;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] == '\'' || arg[i] == '\"')
		{
			i++;
			while (arg[i] != '\'' && arg[i] != '\"' && arg[i] != '\0')
				i++;
		}
		else if (arg[i] == ' ')
			arg[i] = 1;
		i++;
	}
	cmd = ft_split(arg, 1);
	return (cmd);
}

char	*get_cmd_path(t_data *data, char *cmd)
{
	char	**path;
	char	*cmd_path;

	path = data->paths;
	while (*path != NULL)
	{
		cmd_path = build_cmd_path(*path, cmd);
		if (!access(cmd_path, X_OK))
			return (cmd_path);
		free(cmd_path);
		path++;
	}
	cmd_path = NULL;
	return (NULL);
}

static char	*build_cmd_path(char *path, char *cmd)
{
	char	*cmd_path;
	size_t	lpath;
	size_t	lcmd;

	if (path == NULL || cmd == NULL)
		return (NULL);
	lpath = ft_strlen(path);
	lcmd = ft_strlen(cmd);
	cmd_path = ft_calloc(lpath + lcmd + 2, sizeof(char));
	if (cmd_path == NULL)
		return (NULL);
	ft_strlcpy(cmd_path, path, lpath + 1);
	cmd_path[lpath] = '/';
	ft_strlcpy(cmd_path + lpath + 1, cmd, lcmd + 1);
	cmd_path[lpath + lcmd + 1] = '\0';
	return (cmd_path);
}
