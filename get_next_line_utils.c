/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaestre <jmaestre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:45:52 by username          #+#    #+#             */
/*   Updated: 2026/11/05 19:02:44 by jmaestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	if ((char) c == '\0')
		return ((char *) s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ns;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = "";
	if (!s2)
		return (NULL);
	ns = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ns)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i])
		ns[i] = s1[i];
	j = -1;
	while (s2[++j])
		ns[i + j] = s2[j];
	ns[i + j] = '\0';
	return (ns);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ns;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen((char *) s);
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	ns = malloc((len + 1) * sizeof(char));
	if (ns == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		ns[i] = s[start + i];
		i++;
	}
	ns[i] = '\0';
	return (ns);
}
