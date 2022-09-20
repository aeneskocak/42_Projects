/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkocak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:18:02 by ahkocak           #+#    #+#             */
/*   Updated: 2022/04/11 11:42:47 by ahkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_len(char const *s, char c)
{
	size_t	r;

	r = 0;
	while (s[r] != '\0' && s[r] != c)
		r++;
	return (r);
}

static size_t	word_count(char const *s, char c)
{
	size_t	r;

	r = 0;
	while (*s != '\0')
	{
		if (*s != c && (s[1] == '\0' || s[1] == c))
			r++;
		s++;
	}
	return (r);
}

char	**ft_split(char const *s, char c)
{
	char		**r;
	size_t		i;
	size_t		l;
	size_t		word_idx;

	if (!s)
		return (NULL);
	l = word_count(s, c);
	r = (char **)malloc(sizeof(char *) * l + 1);
	if (r == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		while (*s == c && *s != '\0')
			s++;
		r[i] = (char *)malloc(sizeof(char) * word_len(s, c) + 1);
		word_idx = 0;
		while (*s != c && *s != '\0')
			r[i][word_idx++] = *s++;
		r[i][word_idx] = '\0';
		i++;
	}
	r[i] = NULL;
	return (r);
}
