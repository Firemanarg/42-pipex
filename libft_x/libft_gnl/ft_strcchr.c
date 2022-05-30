/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 23:00:40 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/05/02 23:17:44 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

size_t	ft_strcchr(const char *s, int c)
{
	size_t	count;

	if (s == NULL)
		return (0);
	count = 0;
	while (*s != '\0')
	{
		if (*s == c)
			count += 1;
		s++;
	}
	return (count);
}
