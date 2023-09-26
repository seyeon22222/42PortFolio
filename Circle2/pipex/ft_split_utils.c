/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:06:00 by seykim            #+#    #+#             */
/*   Updated: 2023/07/04 21:49:59 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	change_char(char ch, int *flag, char *c, int *num)
{
	if (ch == '\'' && (*flag) == 1)
	{
		*c = ' ';
		*flag = 0;
		(*num)++;
	}
	if (ch == '\'' && (*flag) == 0)
	{
		*c = '\'';
		*flag = 1;
		(*num)++;
	}
	if (ch == '"' && (*flag) == 2)
	{
		*c = ' ';
		*flag = 0;
		(*num)++;
	}
	if (ch == '"' && (*flag) == 0)
	{
		*c = '"';
		*flag = 2;
		(*num)++;
	}
}

void	set_arr(char const *s, int *arr, char c, char **newstr)
{
	while (s[arr[2]] && arr[3] < (size_count((char *)s, c)))
	{
		change_char(s[arr[2]], &arr[1], &c, &arr[2]);
		while (s[arr[2]] && find_cs(s[arr[2]], c))
			arr[2]++;
		change_char(s[arr[2]], &arr[1], &c, &arr[2]);
		if (s[arr[2]] != 0)
			arr[0] = arr[2];
		while (s[arr[2]] && (!(find_cs(s[arr[2]], c))))
			arr[2]++;
		newstr[arr[3]] = abc(arr[0], arr[2], (char *)s);
		if (!newstr[arr[3]])
			ft_free5(newstr, arr[3]);
		arr[3]++;
	}
}
