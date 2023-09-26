/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:23:32 by seykim            #+#    #+#             */
/*   Updated: 2023/07/04 21:47:57 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char		*abc(int start, int end, char *str);
static int		find_cs(char c, char charset);
static int		size_count(char *str, char c);
static char		**ft_free2(char **newstr, int idx);

char	**ft_split2_bonus(char const *s, char c)
{
	char	**newstr;
	int		idx;
	int		num;
	int		start;

	idx = 0;
	newstr = (char **)malloc(sizeof(char *) * (size_count((char *)s, c) + 1));
	if (!newstr)
		return (NULL);
	num = 0;
	while (s[num] && idx < (size_count((char *)s, c)))
	{
		while (s[num] && find_cs(s[num], c))
			num++;
		if (s[num] != 0)
			start = num;
		while (s[num] && (!(find_cs(s[num], c))))
			num++;
		newstr[idx] = abc(start, num, (char *)s);
		if (!newstr[idx])
			return (ft_free2(newstr, idx));
		idx++;
	}
	newstr[idx] = 0;
	return (newstr);
}

static char	**ft_free2(char **newstr, int idx)
{
	while (idx--)
	{
		free(newstr[idx]);
	}
	free(newstr);
	return (NULL);
}

static int	size_count(char *str, char c)
{
	int	num;
	int	count;

	num = 0;
	count = 0;
	while (str[num])
	{
		while (str[num] && (find_cs(str[num], c)))
			num++;
		if (str[num] != 0)
			count++;
		while (str[num] && (!find_cs(str[num], c)))
			num++;
	}
	return (count);
}

static char	*abc(int start, int end, char *str)
{
	int		size;
	int		idx;
	char	*arr;

	size = end - start;
	idx = 0;
	arr = (char *)malloc(sizeof(char) * (size + 2));
	if (arr == NULL)
		return (NULL);
	while (start < end)
	{
		arr[idx] = str[start];
		start++;
		idx++;
	}
	arr[idx++] = '/';
	arr[idx] = 0;
	return (arr);
}

static int	find_cs(char c, char charset)
{
	int	i;

	i = 0;
	if (c == charset)
		return (1);
	return (0);
}
