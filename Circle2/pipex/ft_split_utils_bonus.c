/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:06:00 by seykim            #+#    #+#             */
/*   Updated: 2023/07/04 21:44:11 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	change_char_bonus(char ch, int *flag, char *c, int *num)
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

void	set_arr_bonus(char const *s, int *arr, char c, char **newstr)
{
	while (s[arr[2]] && arr[3] < (size_count_bonus((char *)s, c)))
	{
		change_char_bonus(s[arr[2]], &arr[1], &c, &arr[2]);
		while (s[arr[2]] && find_cs_bonus(s[arr[2]], c))
			arr[2]++;
		change_char_bonus(s[arr[2]], &arr[1], &c, &arr[2]);
		if (s[arr[2]] != 0)
			arr[0] = arr[2];
		while (s[arr[2]] && (!(find_cs_bonus(s[arr[2]], c))))
			arr[2]++;
		newstr[arr[3]] = abc_bonus(arr[0], arr[2], (char *)s);
		if (!newstr[arr[3]])
			ft_free_bonus(newstr, arr[3]);
		arr[3]++;
	}
}
