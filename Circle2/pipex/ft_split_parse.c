/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:43:52 by seykim            #+#    #+#             */
/*   Updated: 2023/07/04 21:49:53 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//arr[0] = start, arr[1] = flag, arr[2] = num, arr[3] = idx
char	**ft_split_parse(char const *s, char c)
{
	char	**newstr;
	int		arr[4];

	arr[1] = 0;
	arr[2] = 0;
	arr[3] = 0;
	newstr = (char **)malloc(sizeof(char *) * (size_count((char *)s, c) + 1));
	if (!newstr)
		return (0);
	set_arr(s, arr, c, newstr);
	newstr[arr[3]] = 0;
	return (newstr);
}

char	**ft_free5(char **newstr, int idx)
{
	while (idx--)
	{
		free(newstr[idx]);
	}
	free(newstr);
	return (0);
}

int	size_count(char *str, char c)
{
	int	num;
	int	count;
	int	flag;

	num = 0;
	count = 0;
	flag = 0;
	while (str[num])
	{
		change_char(str[num], &flag, &c, &num);
		while (str[num] && (find_cs(str[num], c)))
			num++;
		change_char(str[num], &flag, &c, &num);
		if (str[num] != 0)
			count++;
		while (str[num] && (!find_cs(str[num], c)))
			num++;
		num++;
	}
	return (count);
}

char	*abc(int start, int end, char *str)
{
	int		size;
	int		idx;
	char	*arr;

	size = end - start;
	idx = 0;
	arr = (char *)malloc(sizeof(char) * (size + 1));
	if (arr == 0)
		return (0);
	while (start < end)
	{
		arr[idx] = str[start];
		start++;
		idx++;
	}
	arr[idx] = 0;
	return (arr);
}

int	find_cs(char c, char charset)
{
	int	i;

	i = 0;
	if (c == charset)
		return (1);
	return (0);
}
