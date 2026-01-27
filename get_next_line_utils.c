/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:42:51 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/01/27 13:05:48 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		return(0);
	str = (char *)s;
	x = (char)c;
	i = 0;
	while (str[i] != '\0' && str[i] != x)
		i++;
	if (str[i] != x)
		return (0);
	return (1);
}

char	*ft_strjoin(char const *s1, char const *s2)
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
	while (s2[j] && s2[j] != '\n')
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*arr;

	i = 0;
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

char	*ft_stash(char **s, int c)
{
	int		i;
	char	x;
	char	*tmp;

	x = (char)c;
	i = 0;
	while(*s[i] != x && *s[i] != '\0')
		i++;
	tmp = ft_strdup((*s + (i + 1)));
	free(*s);
	return (ft_strdup(tmp));
}