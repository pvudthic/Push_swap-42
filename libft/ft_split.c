/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvudthic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:54:05 by pvudthic          #+#    #+#             */
/*   Updated: 2023/09/05 15:27:16 by pvudthic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			words++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (words);
}

static void	free_memerror(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		temp[i] = NULL;
		i++;
	}
	free(temp);
}

static char	**add_value(char **temp, const char *s, char c, size_t words)
{
	size_t		i;
	size_t		count;
	const char	*start_str;

	i = -1;
	while (++i < words)
	{
		count = 0;
		while (*s == c)
			s++;
		start_str = s;
		while (*s != c && *s != '\0')
		{
			count++;
			s++;
		}
		temp[i] = ft_substr(start_str, 0, count);
		if (temp[i] == NULL)
		{
			free_memerror(temp);
			return (NULL);
		}
	}
	return (temp);
}

char	**ft_split(char const *s, char c)
{
	char		**temp;
	size_t		words;

	if (s == NULL)
		return (NULL);
	words = count_word(s, c);
	temp = (char **)ft_calloc((words + 1), sizeof(char *));
	if (temp == NULL)
		return (NULL);
	temp = add_value(temp, s, c, words);
	if (temp == NULL)
		return (NULL);
	return (temp);
}
//Make Word count first
//Then allocate memmory
//Allocate 2 dimension
//1 for collect words
//2 for collect Character in words
// int	main(void)
// {
// 	//char	src[50] = " Phanu wat  Vudt hichai";
// 	char	src[50] = "      split       this for   me  !";
// 	char	c = ' ';
// 	char	**str_split;
// 	int		i;
// 	i = 0;
// 	str_split = ft_split(src, c);
// 	while (str_split[i] != (void *)0)
// 	{
// 		printf("%s\n", str_split[i]);
// 		i++;
// 	}
// 	return (0);
// }
