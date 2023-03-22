/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:51:45 by rbordin           #+#    #+#             */
/*   Updated: 2023/02/10 15:01:29 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*place_holder(int fd, char *mem)
{
	char	*tmp;
	int		find;

	tmp = (char *)malloc(sizeof (char) * BUFFER_SIZE +1);
	if (!tmp)
		return (NULL);
	find = 1;
	while (!ft_finder(mem) && find != 0)
	{
		find = read(fd, tmp, BUFFER_SIZE);
		if (find < 0)
		{
			free(tmp);
			return (NULL);
		}
		tmp[find] = 0;
		mem = ft_link(mem, tmp);
	}
	free(tmp);
	return (mem);
}

char	*extract(char *mem)
{
	size_t	i;
	char	*mine;

	i = 0;
	while (mem[i] && mem[i] != '\n')
		++i;
	mine = (char *)malloc(sizeof (char) * (i + 2));
	if (!mine)
		return (NULL);
	i = 0;
	while (mem[i] && mem[i] != '\n')
	{
		mine[i] = mem[i];
		++i;
	}
	if (mem[i] == '\n')
	{
		mine[i] = '\n';
		++i;
	}
	mine[i] = 0;
	return (mine);
}

char	*forget(char *mem)
{
	size_t	i;
	size_t	j;
	char	*remanence;

	i = 0;
	while (mem[i] && mem[i] != '\n')
	++i;
	if (!mem[i])
	{
		free(mem);
		return (NULL);
	}
	j = 0;
	while (mem[j])
		++j;
	remanence = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!remanence)
		return (NULL);
	++i;
	j = 0;
	while (mem[i])
		remanence[j++] = mem[i++];
	remanence[j] = 0;
	free(mem);
	return (remanence);
}
