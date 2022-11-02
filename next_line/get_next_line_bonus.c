/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:05:20 by fhihi             #+#    #+#             */
/*   Updated: 2022/11/02 10:25:35 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*return_line(char *line)
{
	int		i;
	char	*s;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	s = (char *)malloc(i * sizeof(char ) + 2);
	if (!s)
		return (NULL);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			s[i] = line[i];
			i++;
			break ;
		}
		s[i] = line[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*left(char *line)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i] || (line[i] == '\n' && line [i + 1] == '\0'))
	{
		free(line);
		return (NULL);
	}
	s = (char *)malloc((ft_strlen(line) - i) * sizeof(char ));
	if (!s)
	{
		free(line);
		return (NULL);
	}
	i++;
	j = 0;
	while (line[i])
		s[j++] = line[i++];
	s[j] = '\0';
	free(line);
	return (s);
}

char	*was_read(int fd, char *lft)
{
	char		buf[BUFFER_SIZE + 1];
	int			red;

	red = 1;
	while (red != 0)
	{
		red = read(fd, buf, BUFFER_SIZE);
		if (red <= 0)
		{
			break ;
		}
		buf[red] = '\0';
		lft = ft_strjoin(lft, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (lft);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*lft[128];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lft[fd] = was_read(fd, lft[fd]);
	if (!lft[fd])
		return (NULL);
	line = return_line(lft[fd]);
	lft[fd] = left(lft[fd]);
	return (line);
}
