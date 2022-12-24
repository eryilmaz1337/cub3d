/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:50:38 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/02/23 13:58:50 by eryilmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif 
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

char	*get_next_line(int fd);
char	*ft_strjoin1(char *s1, char *s2);
char	*ft_strchr1(const char *s, int c);
size_t	ft_strlen1(const char *s);

#endif
