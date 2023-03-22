/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:46:45 by rbordin           #+#    #+#             */
/*   Updated: 2023/02/01 10:17:07 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	p;
	unsigned char	*str;

	str = ((unsigned char *)s);
	i = 0;
	p = (unsigned char)c;
	if (!s && !c && !n)
		return (NULL);
	while (i < n)
	{
		if (str[i] != p)
			i++;
		else
			return ((unsigned char *)&str[i]);
	}
	return (NULL);
}
