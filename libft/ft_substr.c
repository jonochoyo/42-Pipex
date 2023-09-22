/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:29:37 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/07/17 16:32:53 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Allocates with malloc and returns a substring from the string ’s’.
The substring begins at index ’start’ and is of maximum size ’len’.
RETURN: The substring or NULL if the allocation fails.

If the len given is higher than the len of s - start index, len becomes 
strlen(s) - start. This ensures we do not malloc more than what is needed.
If the start index is higher than the len of 's' we make len = 0. This
way will only malloc(1) and return an empty string. 
When copying to substr, we check that the start index is within s 
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
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

/*
int	main(void)
{
	char	str[] = "hello";

	printf("%s\n", ft_substr(str, 3, 3));
	printf("%s\n", ft_substr("hello", 5, 2));
	printf("%s\n", ft_substr("hola", 4294967295, 4294967295));
}
*/
