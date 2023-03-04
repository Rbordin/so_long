/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:40:35 by rbordin           #+#    #+#             */
/*   Updated: 2023/02/10 15:01:48 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <unistd.h>

char		*get_next_line(int fd);
char		*forget(char *mem);
char		*extract(char *mem);
char		*ft_link(char *mem, char *tmp);
char		*place_holder(int fd, char *mem);
char		*ft_finder(char *mem);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
#endif
