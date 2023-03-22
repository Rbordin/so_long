/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:36:26 by rbordin           #+#    #+#             */
/*   Updated: 2023/02/01 10:19:03 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ns1;
	unsigned char	*ns2;

	i = 0;
	ns1 = ((unsigned char *)s1);
	ns2 = ((unsigned char *)s2);
	if (!s1 && !s2)
		return (0);
	while (i < n)
	{
		if (ns1[i] < ns2[i] || ns1[i] > ns2[i])
			return (ns1[i] - ns2[i]);
		i++;
	}
	return (0);
}
