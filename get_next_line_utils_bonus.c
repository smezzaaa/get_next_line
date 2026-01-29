/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:42:51 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/01/29 19:47:55 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	int		i;
	char	x;
	char	*str;

	if (!s)
		return (0);
	str = (char *)s;
	x = (char)c;
	i = 0;
	while (str[i] != '\0' && str[i] != x)
		i++;
	if (str[i] != x)
		return (0);
	return (1);
}

char	*ft_strtrim(const char *s)
{
	int		i;
	char	*arr;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	arr = (char *)malloc(i + 1);
	if (!arr)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		arr[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = 0;
	return (arr);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*arr;

	i = 0;
	if (!s)
		return (NULL);
	arr = (char *)malloc(ft_strlen(s) + 1);
	if (!arr)
		return (NULL);
	while (s[i])
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = 0;
	return (arr);
}

char	*ft_stash(char *s, int c)
{
	int		i;
	char	x;
	char	*tmp;

	x = (char)c;
	i = 0;
	while (s[i] != x && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		i++;
	tmp = ft_strdup(s + i);
	free(s);
	return (tmp);
}
