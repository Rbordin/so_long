/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:43:36 by rbordin           #+#    #+#             */
/*   Updated: 2023/02/10 14:51:17 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_finder(char *mem)
{
	size_t	i;

	if (!mem)
		return (NULL);
	i = 0;
	while (mem[i])
	{
		if (mem[i] == '\n')
			return (mem + i);
		i++;
	}
	return (NULL);
}

char	*ft_link(char *mem, char *tmp)
{
	int		i;
	int		j;
	char	*clear;

	if (!mem && (!tmp || !*tmp))
		return (NULL);
	i = 0;
	if (mem)
	{
		while (mem[i])
			++i;
	}
	j = 0;
	while (tmp[j])
		++j;
	clear = (char *)malloc(sizeof(char) * i + j + 1);
	if (!clear)
		return (NULL);
	clear[i + j] = '\0';
	while (--j >= 0)
		clear[i + j] = tmp[j];
	while (--i >= 0)
		clear[i] = mem[i];
	free(mem);
	return (clear);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*mem;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	mem = place_holder(fd, mem);
	if (!mem || !*mem)
	{
		free(mem);
		return (NULL);
	}
	res = extract(mem);
	mem = forget(mem);
	return (res);
}
