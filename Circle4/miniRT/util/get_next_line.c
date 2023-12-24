/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:31:54 by seykim            #+#    #+#             */
/*   Updated: 2023/12/19 20:24:21 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*res;
	char		*arr;
	int			x;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!res)
		res = ft_strdup("");
	if (!res)
		return (ft_free(&res));
	arr = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!arr)
		return (ft_free(&res));
	x = read(fd, arr, BUFFER_SIZE);
	if (!(read_line(fd, x, &arr, &res)))
		return (0);
	free(arr);
	if (x < 0)
		return (ft_free(&res));
	return (print_arr(&res));
}

char	*read_line(int fd, int x, char **arr, char **res)
{
	while (x > 0)
	{	
		(*arr)[x] = '\0';
		(*res) = ft_strjoin((*res), (*arr));
		if (!(*res))
			return (ft_free(arr));
		if (ft_strchr((*res), '\n'))
			break ;
		x = read(fd, *arr, BUFFER_SIZE);
	}
	return ("1");
}

char	*print_arr(char **res)
{
	char	*temp;
	char	*temp2;
	int		len;

	len = 0;
	temp = 0;
	if (!(*res))
		return (0);
	while ((*res)[len] != '\n' && (*res)[len] != '\0')
		len++;
	if ((*res)[len] == '\n')
	{
		if (!(print_arr2(&temp, &temp2, res, len)))
			return (0);
		return (temp);
	}
	else if ((*res)[len] == '\0' && len > 0)
		temp = ft_strdup(*res);
	if (!temp)
		return (ft_free(res));
	ft_free(res);
	return (temp);
}

char	*print_arr2(char **temp, char **temp2, char **res, int len)
{
	*temp = ft_substr(*res, 0, len + 1);
	if (!(*temp))
		return (ft_free(res));
	*temp2 = ft_strdup(&(*res)[len + 1]);
	if (!(*temp2))
	{
		free(*temp);
		return (ft_free(res));
	}
	free(*res);
	*res = *temp2;
	return (*temp);
}

void	*ft_free(char **arr)
{
	if (*arr)
		free(*arr);
	*arr = 0;
	return (0);
}
