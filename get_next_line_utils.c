/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:15:16 by mmounsif          #+#    #+#             */
/*   Updated: 2024/12/22 08:16:02 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	size_t			len;

	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (*s == (unsigned char) c)
			return ((char *)s + 1);
		s++;
		i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	dest = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[ft_strlen(s1)] = '\0';
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	i = 0;
	while (i < len) 
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j]) 
		str[i++] = s2[j++];
	return (str);
}
