/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:04:52 by fhihi             #+#    #+#             */
/*   Updated: 2022/11/02 10:05:04 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size;
	size_t	i;
	size_t	j;
	size_t	j2;
	char	*s;

	if (!s1 && !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	s = (char *)malloc((size + 1) * sizeof(char));
	if (!s)
		return (0);
	i = 0;
	j = 0;
	j2 = 0;
	while (s1 && s1[j])
		s[i++] = s1[j++];
	while (s2 && s2[j2])
		s[i++] = s2[j2++];
	s[i] = '\0';
	free(s1);
	return (s);
}
