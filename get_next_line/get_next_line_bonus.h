/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkocak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:45:22 by ahkocak           #+#    #+#             */
/*   Updated: 2022/07/04 10:44:26 by ahkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*reading_from_file(int fd, char *buff);
char	*get_line(char *buff);
char	*append_string(char *s1, char *s2);
char	*shift_string(char *str);
int		check_newline(char *str);
int		ft_strlen(char *str);

#endif
