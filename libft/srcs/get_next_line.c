/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:10:54 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/28 08:33:24 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		copyline(char *line, char *buf)
{
	unsigned int		count;

	count = 0;
	while (line[count] != '\n' && line[count])
		count++;
	if (ft_strlen(line) > count + 1)
	{
		buf = ft_strcpy(buf, &(line[count + 1]));
	}
	line[count] = '\0';
	return (1);
}

static int		do_line(const int fd, char **line, char **buff)
{
	char		*temp;
	int			val;

	val = 1;
	while (!(ft_strchr(*line, '\n')) &&
			(val = read(fd, buff[fd], BUFF_SIZE)) > 0)
	{
		temp = *line;
		*line = ft_strjoin(*line, buff[fd]);
		free(temp);
		if (!*line)
			return (-1);
		ft_bzero(buff[fd], BUFF_SIZE);
	}
	if (*line[0] != '\0' && val >= 0)
		return (copyline(*line, buff[fd]));
	return (val);
}

int				get_next_line(const int fd, char **line)
{
	static char	*buff[1000000];

	if (fd < 0 || read(fd, buff[fd], 0) < 0 || !line ||
		!(*line = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	if (!buff[fd])
		buff[fd] = ft_strnew(BUFF_SIZE + 1);
	if (buff[fd][0] != '\0')
		*line = ft_strcpy(*line, buff[fd]);
	ft_bzero(buff[fd], BUFF_SIZE);
	return (do_line(fd, line, buff));
}
