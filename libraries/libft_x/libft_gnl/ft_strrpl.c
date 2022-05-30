/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrpl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:47:14 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/05/28 21:52:25 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

size_t	ft_strrpl(char *s, char old, char new)
{
	size_t	count;
	size_t	i;

	if (s == NULL)
		return (0);
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == old)
			s[i] = new;
		i += 1;
	}
	return (count);
}
