/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:28:22 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/01/27 13:12:54 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	void		*buff;
	ssize_t		rd;
	static char	*stash = NULL;
	char	*line;

	rd = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	line = NULL;
	if (!buff)
		return(NULL);
	while (rd > 0 && !ft_strchr(stash, '\n'))
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (!stash)
			stash = ft_strdup(buff);
		else
			line = ft_strjoin(stash, buff);
		free (buff);
	}
	if (ft_strchr(stash, '\n'))
	{
		line = ft_strjoin(line, stash);
		stash = ft_stash(&stash, '\n');
	}
	return (line);
}

int main ()
{
	int fd;
	fd = open("doc.txt", O_RDONLY);
	char *line = get_next_line(fd);
	printf ("prima riga: %s", line);
	free (line);;
}