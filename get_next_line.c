/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:28:22 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/01/21 20:00:29 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_stash(ssize_t nb, void *buff)
{
	void	*stash;
	int		i;
	
	stash = malloc(nb)
}

char *get_next_line(int fd)
{
	void	*buff;
	ssize_t		rd;

	buff = malloc(BUFFER_SIZE * sizeof(char));
	if (!buff)
		return(NULL);
	while (rd != 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		ft_stash(rd, buff);
	}
}

int main ()
{
	int fd;
	fd = open("doc.txt", O_RDONLY);
}