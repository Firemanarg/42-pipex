/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:41:35 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/05/30 20:25:30 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"
#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	if (argc != 5)
	{
		write(2, "Error: Invalid argument\n", 25);
		exit(EINVAL);
	}
	init_data(&data);
	data.argc = argc;
	data.argv = argv;
	data.envp = envp;
	ft_putstr_fd("AAAA!\n", 2);
	data.fd_infile = open(argv[1], O_RDONLY);
	ft_putstr_fd("BBBB!\n", 2);
	//if (data.fd_infile == -1)
		//error(&data, NULL);
	data.paths = get_paths(envp);
	if (data.paths == NULL)
		error(&data, NULL);
	data.cmd_count = argc - 3;
	pipex(&data);
	clean_array(data.paths);
	return (EXIT_SUCCESS);
}
