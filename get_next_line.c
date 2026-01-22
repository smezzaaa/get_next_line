/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:28:22 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/01/22 18:12:08 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* 
static char *ft_stash(ssize_t nb, void *buff)
{
	void	*stash;
	int		i;

	stash = malloc(nb * sizeof(char));
} */

char *get_next_line(int fd)
{
	void		*buff;
	ssize_t		rd;
	static char	*stash = NULL;

	rd = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return(NULL);
	while (rd > 0 && !ft_strchr(stash, '\n'))
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (!stash)
			stash = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(stash, buff);
			free (stash);
		}
	}
}

int main ()
{
	int fd;
	fd = open("doc.txt", O_RDONLY);
}