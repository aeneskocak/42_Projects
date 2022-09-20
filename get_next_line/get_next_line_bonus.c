/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkocak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 15:51:16 by ahkocak           #+#    #+#             */
/*   Updated: 2022/07/04 12:45:31 by ahkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*reading_from_file(int fd, char *buff)
{
	char	*tmp;
	int		byte_num;

	byte_num = 1;
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	while (check_newline(buff) && byte_num)
	{
		byte_num = read(fd, tmp, BUFFER_SIZE);
		if (byte_num == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[byte_num] = '\0';
		buff = append_string(buff, tmp);
	}
	free(tmp);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff[1024];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd == -1)
		return (NULL);
	buff[fd] = reading_from_file(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	line = get_line(buff[fd]);
	buff[fd] = shift_string(buff[fd]);
	return (line);
}
