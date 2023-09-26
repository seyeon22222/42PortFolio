/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:36:29 by seykim            #+#    #+#             */
/*   Updated: 2023/03/23 19:14:30 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *s);
static int		idx_start(const char *s, const char *sep);
static int		idx_end(const char *s, const char *sep);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	int		new_idx;
	int		start;
	int		end;

	new_idx = 0;
	start = idx_start(s1, set);
	end = idx_end(s1, set);
	if (start > end)
	{
		new_str = (char *)malloc(1);
		if (!new_str)
			return (NULL);
		*new_str = 0;
		return (new_str);
	}
	new_str = (char *)malloc(sizeof(char) * ((end - start) + 2));
	if (!new_str)
		return (NULL);
	while (start <= end)
		new_str[new_idx++] = s1[start++];
	new_str[new_idx] = 0;
	return (new_str);
}

static int	idx_start(const char *s, const char *sep)
{
	int		start;
	size_t	max;
	int		sep_idx;
	int		flag;

	start = 0;
	flag = 0;
	max = ft_strlen(s) - 1;
	while (max > 0)
	{
		sep_idx = -1;
		while (sep[++sep_idx])
		{
			if (s[start] == sep[sep_idx])
			{
				start++;
				flag = 1;
			}
		}
		max--;
		if (flag == 0)
			break ;
	}
	return (start);
}

static int	idx_end(const char *s, const char *sep)
{
	int		end;
	size_t	max;
	int		sep_idx;
	int		s_len;
	int		flag;

	s_len = ft_strlen(s);
	end = (s_len - 1);
	max = s_len;
	while (max-- > 0)
	{
		sep_idx = -1;
		flag = 0;
		while (sep[++sep_idx])
		{
			if (s[end] == sep[sep_idx])
			{
				end -= 1;
				flag = 1;
			}
		}
		if (flag == 0)
			break ;
	}
	return (end);
}

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

// #include <stdio.h>
// int main ()
// {	
// 	char *s2 = ft_strtrim("asssssssbssakbcd", "abcd");
// 	printf("%s \n", s2);
// }