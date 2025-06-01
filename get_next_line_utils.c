/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhov <akorzhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:02:24 by akorzhov          #+#    #+#             */
/*   Updated: 2025/05/27 17:34:56 by akorzhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	size_t	len;
	char	*start;

	len = ft_strlen(s1);
	len += ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	start = res;
	while (*s1)
		*res++ = *s1++;
	while (*s2)
		*res++ = *s2++;
	*res = '\0';
	return (start);
}

char	*ft_strdup(const char *s)
{
	char	*res;
	char	*start;
	size_t	len;

	len = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	start = res;
	while (*s)
		*res++ = *s++;
	*res = '\0';
	return (start);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	s_len;
	size_t	sub_len;
	size_t	i;

	i = 0;
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len - start < len)
		sub_len = s_len - start;
	else
		sub_len = len;
	res = (char *)malloc(sizeof(char) * (sub_len + 1));
	if (!res)
		return (NULL);
	while (i < sub_len && s[start])
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}
