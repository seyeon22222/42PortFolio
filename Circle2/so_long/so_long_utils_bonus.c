/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:34:49 by seykim            #+#    #+#             */
/*   Updated: 2023/06/12 14:54:31 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**visited_bonus(t_info *info, char **arr2)
{
	char	**visit;
	int		i;

	visit = (char **)malloc(sizeof(char *) * (info->size_row + 1));
	if (!visit)
		return (0);
	i = 0;
	while (arr2[i] && i < info->size_row)
	{
		visit[i] = ft_strdup(arr2[i]);
		if (!visit[i])
		{
			ft_free2_bonus(visit, i);
			return (0);
		}
		i++;
	}
	visit[i] = 0;
	return (visit);
}

char	**ft_free2_bonus(char **newstr, int idx)
{
	while (idx--)
	{
		free(newstr[idx]);
	}
	free(newstr);
	return (NULL);
}

void	print_error_bonus(int flag)
{
	if (flag == 0)
	{
		write(1, "Error\n", 6);
		write(1, "Imposible Read\n", 16);
	}
	else if (flag == 1)
	{
		write(1, "Error\n", 6);
		write(1, "Map Size Error\n", 16);
	}
	else if (flag == 2)
	{
		write(1, "Error\n", 6);
		write(1, "Map Setting Error\n", 19);
	}
	exit (1);
}

void	key_init_bonus(t_info *info, char **arr2)
{
	ft_free2_bonus(info->visited, info->size_row);
	info->visited = visited_bonus(info, arr2);
	if (!info->visited)
		exit (1);
	info->get_cnt = 0;
}

void	print_move_bonus(t_info *info, int flag)
{
	info->go_cnt++;
	if (flag == 1)
	{
		mlx_destroy_image(info->my_mlx->mlx, info->my_mlx->img);
		mlx_destroy_image(info->my_mlx->mlx, info->my_mlx->img1);
		mlx_destroy_image(info->my_mlx->mlx, info->my_mlx->img2);
		mlx_destroy_image(info->my_mlx->mlx, info->my_mlx->img3);
		mlx_destroy_image(info->my_mlx->mlx, info->my_mlx->img4);
		mlx_destroy_image(info->my_mlx->mlx, info->my_mlx->img5);
		mlx_destroy_image(info->my_mlx->mlx, info->my_mlx->img6);
		mlx_destroy_window(info->my_mlx->mlx, info->my_mlx->win);
		exit(0);
	}
}
