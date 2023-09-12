/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:46:07 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/09/12 16:44:48 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while ((str1[i] != '\0' || str2[i] != '\0') && i < n)
	{
		if (str1[i] != str2[i])
			return ((int)(str1[i] - str2[i]));
		i++;
	}
	return (0);
}

// Split for the PATH :
static int	ft_nwords(char const *s, char c)
{
	int	i;
	int	nwords;

	i = 0;
	nwords = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			nwords++;
			while (s[i] != c && s[i] != '\0')
				i++;
			if (s[i] == '\0')
				return (nwords);
		}
		i++;
	}
	return (nwords);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sbstr;
	size_t	i;
	size_t	strsize;

	i = 0;
	if (s == NULL)
		return (NULL);
	strsize = ft_strlen(s);
	if (len > strsize - start)
		len = strsize - start;
	if (start > strsize)
		len = 0;
	sbstr = (char *) malloc(sizeof(char) * (len + 1));
	if (sbstr == NULL)
		return (NULL);
	while (i < len && s[start + i] != '\0' && start < strsize)
	{
		sbstr[i] = s[start + i];
		i++;
	}
	sbstr[i] = '\0';
	return (sbstr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		start;
	char	**strs;

	strs = (char **) malloc (sizeof(char *) * (ft_nwords(s, c) + 1));
	if (strs == NULL || s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (j < ft_nwords(s, c))
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			strs[j] = ft_substr(s, start, i - start);
			j++;
		}
		i++;
	}
	strs[j] = NULL;
	return (strs);
}

// strjoin to put / and program name together and put with the PATH
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;
	size_t	nbytes;

	i = 0;
	j = 0;
	nbytes = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest = (char *) malloc(sizeof(char) * nbytes);
	if (dest == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
