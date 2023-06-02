/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadahun <ofadahun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:03:47 by ofadahun          #+#    #+#             */
/*   Updated: 2023/06/02 13:50:19 by ofadahun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*free_line(char *line)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
	return (line);
}

/*
This function joins line to buff and it frees
the line pointer passed to it and return the newly allocated joined line*/
static char	*ft_linejoin(char *line, char *buff)
{
	char	*new_line;

	if (!line)
	{
		line = malloc(1);
		if (!line)
			return (NULL);
		*line = '\0';
	}
	new_line = (char *)malloc(((ft_strlen(buff) + ft_strlen(line) + 1)) \
	* sizeof(char));
	if (new_line)
	{
		ft_strlcpy(new_line, line, ft_strlen(line) + 1);
		ft_strlcpy(new_line + ft_strlen(line), buff, ft_strlen(buff) + 1);
	}
	line = free_line(line);
	return (new_line);
}

/*
This functions extracts a complete line when a newline charater has been found
It copies the buff from the start of the buff until the newline character
Memset used to nullify all the characters that has already been copied into line
strlcpy is used to move the remaining charcters in buff that has not been copied
to the front.
*/
static char	*extract(char *line, char *buff, char *breaker)
{
	char	*to_join;

	to_join = malloc(breaker - buff + 2);
	if (!to_join)
		return (free_line(line));
	ft_strlcpy(to_join, buff, breaker - buff + 2);
	line = ft_linejoin(line, to_join);
	free(to_join);
	if (!line)
		return (line);
	ft_memset(buff, 0, breaker - buff);
	ft_strlcpy(buff, breaker + 1, ft_strlen(breaker) + 1);
	return (line);
}

/*
This functions keeps joining to line until it gets a newline character
it uses memset to nullify all the elements that has been copied in buff
*/
static char	*join_to_get_complete_line(char *line, char *buff, int fd)
{
	ssize_t	bytes_read;

	line = ft_linejoin(line, buff);
	if (!line)
		return (line);
	while (!ft_strchr(buff, '\n'))
	{
		ft_memset(buff, 0, ft_strlen(buff));
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == 0)
		{
			if (line && *line == '\0')
				line = free_line(line);
			break ;
		}
		else if (bytes_read == -1)
			return (free_line(line));
		buff[bytes_read] = '\0';
		if (ft_strchr(buff, '\n'))
			break ;
		line = ft_linejoin(line, buff);
		if (!line)
			break ;
	}
	return (line);
}

/*
Line needed to start with empty string because we will joining to it
If there is a newlie character on the first read, then we just call
extract function that extract the complete line else
we call the join_to_get_complete_lie that keeps joining to line
until it finds a newline character or perhaps even reach EOF*/
char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE + 1];
	char			*line;
	ssize_t			bytes_read;

	bytes_read = 0;
	line = NULL;
	if (BUFFER_SIZE < 1 || fd < 0 || fd >= 1024)
		return (NULL);
	if (!*buff)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 1)
			return (NULL);
		buff[bytes_read] = '\0';
	}
	while (*buff)
	{
		if (ft_strchr(buff, '\n'))
			return (extract(line, buff, ft_strchr(buff, '\n')));
		else
			line = join_to_get_complete_line(line, buff, fd);
		if (!line)
			break ;
	}
	return (line);
}
