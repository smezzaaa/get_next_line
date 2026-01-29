/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:28:22 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/01/29 20:00:39 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	newlen;
	size_t	i;
	size_t	j;
	char	*newstr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	newlen = ft_strlen(s1) + ft_strlen(s2) + 1;
	i = -1;
	j = 0;
	newstr = malloc ((newlen) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	while (s1[++i])
		newstr[i] = s1[i];
	while (s2[j])
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	free(s1);
	return (newstr);
}

char	*ft_free(char *s, char *b)
{
	free(s);
	s = NULL;
	free(b);
	b = NULL;
	return (NULL);
}

char	*ft_return(char **s)
{
	char	*line;

	if (ft_strchr(*s, '\n'))
	{
		line = ft_strtrim(*s);
		*s = ft_stash(*s, '\n');
	}
	else
	{
		line = *s;
		*s = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buff;
	ssize_t		rd;
	static char	*stash[4096];
	char		*line;

	rd = 1;
	line = NULL;
	while (rd > 0 && !ft_strchr(stash[fd], '\n'))
	{
		buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buff)
			return (ft_free(stash[fd], buff));
		rd = read(fd, (void *)buff, BUFFER_SIZE);
		if (rd < 0)
			return (ft_free(stash[fd], buff));
		buff[rd] = '\0';
		if (!stash[fd] && rd != 0)
			stash[fd] = ft_strdup(buff);
		else
			stash[fd] = ft_strjoin(stash[fd], buff);
		free (buff);
		buff = NULL;
	}
	return (ft_return(&stash[fd]));
}
