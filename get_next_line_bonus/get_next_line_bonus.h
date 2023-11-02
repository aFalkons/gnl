/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 03:02:17 by afalconi          #+#    #+#             */
/*   Updated: 2023/11/02 18:46:00 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>

char		*ft_strdup(char *src);
char		*get_next_line(int fd);
char		*get_the_line(int fd, char *raw_string);
char		*ft_strjoin(char *raw_string, char *second);
int			ft_strlen(char *str);
char		*ft_strchr(char *str, int c);
char		*stop_at_newline(char *raw_string);
char		*extract(char *raw_string);

#endif
