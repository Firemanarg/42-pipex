/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:41:07 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/05/30 20:27:31 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(t_data *data, char **cmd)
{
	if (cmd != NULL)
		clean_array(cmd);
	if (data != NULL && data->paths != NULL)
		clean_array(data->paths);
	perror("Error");
	exit(EXIT_FAILURE);
}

void	error_cmd_not_found(t_data *data, char **cmd)
{
	if (cmd != NULL)
		clean_array(cmd);
	if (data->paths != NULL)
		clean_array(data->paths);
	ft_putstr_fd("command not found\n", 2);
	exit(127);
}

int	clean_array(char **paths)
{
	char	**it;

	it = paths;
	while (*it != NULL)
	{
		free(*it);
		*it = NULL;
		it++;
	}
	free(paths);
	paths = NULL;
	return (0);
}
