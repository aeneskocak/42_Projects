/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkocak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:01:18 by ahkocak           #+#    #+#             */
/*   Updated: 2022/04/11 11:42:04 by ahkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	newstr = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1));
	if (newstr == NULL)
		return (NULL);
	while (*s1 || *s2)
	{
		if (*s1)
			newstr[i] = *s1++;
		else if (*s2)
			newstr[i] = *s2++;
		i++;
	}
	newstr[i] = 0;
	return (newstr);
}
