/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 02:28:24 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/06/27 02:29:38 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (s);
	if ((unsigned char )c == 0)
		return ((char *)s + ft_strlen(s));
	i = -1;
	while (*(s + (++i)))
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((char *)(s + i));
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (s1);
		s1[0] = '\0';
	}
	if (!s2)
		return (free(s1), s2);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (!str)
		return (str);
	i = -1;
	while (*(s1 + (++i)))
		*(str + i) = *(s1 + i);
	j = -1;
	while (*(s2 + (++j)))
		*(str + i + j) = *(s2 + j);
	*(str + i + j) = '\0';
	return (free(s1), str);
}

char	*set_read_line(char *line)
{
	char	*str;
	int		i;

	i = 0;
	if (*line == 0)
		return (NULL);
	while (*(line + i) && *(line + i) != '\n')
		i++;
	if (*(line + i) == '\n')
		i++;
	str = (char *)malloc(i + 1 * sizeof(char));
	if (!str)
		return (str);
	i = 0;
	while (*(line + i) && *(line + i) != '\n')
	{
		str[i] = *(line + i);
		i++;
	}
	if (*(line + i) == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*set_next_line(char *line)
{
	char	*str;
	int		j;
	int		i;

	i = 0;
	while (*(line + i) && *(line + i) != '\n')
		i++;
	if (*(line + i) == '\0')
		return (free(line), NULL);
	str = (char *)malloc((ft_strlen(line) - i + 1) * sizeof(char));
	if (!str)
		return (str);
	i++;
	j = 0;
	while (*(line + i))
	{
		str[j] = *(line + i);
		i++;
		j++;
	}
	str[j] = '\0';
	return (free(line), str);
}
