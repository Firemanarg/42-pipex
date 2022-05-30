/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 11:13:07 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/04/15 00:21:13 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_x.h"

static size_t	ft_find_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	s1_len;

	i = 0;
	s1_len = ft_strlen(s1);
	while (i < s1_len)
	{
		if (!ft_strchr(set, s1[i]))
			return (i);
		i += 1;
	}
	return (0);
}

static size_t	ft_find_end(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		if (!ft_strchr(set, s1[i]))
			return (i);
		i -= 1;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*newstr;

	if (s1)
	{
		start = ft_find_start(s1, set);
		end = ft_find_end(s1, set);
		if (start == end)
			return (ft_strdup(""));
		newstr = ft_substr(s1, start, (end - start) + 1);
		if (!newstr)
			return (NULL);
		return (newstr);
	}
	return (NULL);
}
