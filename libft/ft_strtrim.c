/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:29:59 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/09/22 16:57:36 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Allocates with malloc and returns a copy of ’s1’ with the characters specified 
in ’set’ removed from the beginning and the end of the string.

ft_strtrim have a start variable initialised at 0 and an end one initalised at 
the length of s1 (index of \0). We first iterate while chars on s1 are on the 
set and haven't reach \0 to move start index. Then do the same backwards from 
lastchar while end index > start and chars on s1 are on the set. 
Once we have start and end, we malloc for end - start + 1 bytes for \0.
Finally, we use ft_strlcpy to copy the string from start and nbytes. 
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		start;
	int		end;
	int		nbytes;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	nbytes = end - start + 1;
	dest = (char *) malloc(sizeof(char) * nbytes);
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, &(s1[start]), nbytes);
	return (dest);
}

/*
int	main(void)
{
	char	str[] = "4422222222222222222He42llo24";
	char	set[] = "42";

	printf("%s\n", ft_strtrim(str, set));
}
*/
