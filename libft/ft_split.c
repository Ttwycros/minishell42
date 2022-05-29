/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:55:47 by sslowpok          #+#    #+#             */
/*   Updated: 2021/10/17 19:16:42 by sslowpok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

// static int	ft_word_count(const char *s, char c)
// {
// 	int	i;
// 	int	word_count;
// 	int	len;
// 	int	ss;

// 	len = 0;
// 	ss = 0;
// 	while (s[len])
// 		len++;
// 	i = 0;
// 	word_count = 0;
// 	while (s[i])
// 	{
// 		if (s[i] != c && ss == 0)
// 		{
// 			ss = 1;
// 			word_count++;
// 		}
// 		else if (s[i] == c)
// 			ss = 0;
// 		i++;
// 	}
// 	return (word_count);
// }

// static char	*ft_str_create(const char *s, char c)
// {
// 	int		i;
// 	char	*str;

// 	i = 0;
// 	while (s[i] && s[i] != c)
// 		i++;
// 	str = (char *)malloc(sizeof(char) * (i + 1));
// 	if (!str)
// 		return (NULL);
// 	ft_strlcpy(str, s, i + 1);
// 	return (str);
// }

// static void	ft_clear(char **arr, int i)
// {
// 	while (i > 0)
// 		free(arr[i--]);
// 	free(arr);
// }

// char	**ft_split(const char *s, char c)
// {
// 	char	**out;
// 	int		i;
// 	int		word_count;

// 	if (!s)
// 		return (NULL);
// 	i = -1;
// 	word_count = ft_word_count(s, c);
// 	out = (char **)malloc(sizeof(char *) * (word_count + 1));
// 	if (!out)
// 		return (NULL);
// 	while (++i < word_count)
// 	{
// 		while (*s == c)
// 			s++;
// 		out[i] = ft_str_create(s, c);
// 		if (!out)
// 		{
// 			ft_clear(out, i);
// 			return (NULL);
// 		}
// 		s = s + ft_strlen(out[i]);
// 	}
// 	out[i] = 0;
// 	return (out);
// }

#include "libft.h"
#include <stdlib.h>

static int	get_size(char const	*s, char c)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
			size++;
		while (*(s + i) != c && *(s + i))
			i++;
		if (*(s + i))
			i++;
	}
	size++;
	return (size);
}

char	**filler(const char	*s, char c, char	**strs)
{
	int		i;
	int		j;
	int		len;

	j = 0;
	i = 0;
	while (*(s + i))
	{
		len = 0;
		while (*(s + i) && *(s + i) == c)
			i++;
		while (*(s + i) && *(s + i) != c)
		{
			len++;
			i++;
		}
		if (len > 0)
			strs[j++] = ft_substr(s, i - len, len);
		if (*(s + i))
			i++;
	}
	return (strs);
}

char	**ft_split(char const	*s, char c)
{
	char	**strs;

	if (!s)
		return (0);
	strs = (char **) ft_calloc(get_size(s, c), sizeof(char *));
	if (!strs)
		return (0);
	filler(s, c, strs);
	return (strs);
}
