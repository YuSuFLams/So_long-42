/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 02:39:46 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/06/27 02:39:55 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_substr(char const *s, int start, int len)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		start = ft_strlen(s);
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = (char *)malloc(len + 1 * sizeof(char));
	if (!str)
		return (str);
	i = -1;
	while (++i < len && s[i + start] && start < ft_strlen(s))
		*(str + i) = *(s + (i + start));
	*(str + i) = '\0';
	return (str);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*s;

	s = (char *)malloc(ft_strlen(src) + 1 * sizeof(char ));
	if (!s)
		return (s);
	i = -1;
	while (*(src + (++i)))
		*(s + i) = *(src + i);
	*(s + i) = '\0';
	return (s);
}

void	freesplit(char **s, int i)
{
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int	count(char const *s, char c)
{
	int		i;
	int		counter;

	counter = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			counter++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;
	int		n;

	i = 0;
	j = 0;
	n = -1;
	if (!s)
		return (NULL);
	str = (char **)malloc((count(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (++n < count(s, c))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		str[n] = ft_substr(s, j, i - j);
		if (!str[n])
			return (freesplit(str, 0), NULL);
	}
	return (str[n] = NULL, str);
}
