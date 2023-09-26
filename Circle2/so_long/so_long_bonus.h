/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:39:49 by seykim            #+#    #+#             */
/*   Updated: 2023/07/19 16:24:19 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "mlx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h>
# define X_EVENT_KEY_PRESS			3
# define X_EVENT_MOUSE_EXIT			17

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	void	*img999;
	void	*img1;
	void	*img6;
	void	*img7;
	int		w;
	int		h;
}	t_mlx;

typedef struct s_info
{
	int		size_col;
	int		size_row;
	int		char_col;
	int		char_row;
	int		exit_col;
	int		exit_row;
	int		item_cnt;
	int		char_cnt;
	int		exit_cnt;
	int		get_cnt;
	int		get_exit;
	int		flag;
	int		fd;
	int		go_cnt;
	int		char_num;
	char	**visited;
	t_mlx	*my_mlx;
}	t_info;

//setting mlx
t_mlx	*my_mlx_init_bonus(int size_col, int size_row);
t_info	*size_init_bonus(char **argv);
t_info	*info_init_bonus(void);
void	my_mlx_print_bonus(char **arr2, t_info *info, int i, int i2);
void	my_mlx_print_bonus2(char **arr2, t_info *info, int i, int i2);
char	**get_arr2_bonus(char **arr2, t_info *info, int i, char **argv);
char	**visited_bonus(t_info *info, char **arr2);

//map error check
int		error_check_bonus(char **arr2, t_info *info);
int		error_check2_bonus(int index_row, int index_col, \
char **arr2, t_info *info);
int		error_check3_bonus(int row, int col, char **arr2, t_info *info);
int		dfs_bonus(char **arr2, int col, int row, t_info *info);
char	**ft_free2_bonus(char **newstr, int idx);
void	print_error_bonus(int flag);

//event hook
void	key_init_bonus(t_info *info, char **arr2);
void	move_w_bonus(t_info *info);
void	move_s_bonus(t_info *info);
void	move_a_bonus(t_info *info);
void	move_d_bonus(t_info *info);
void	move_enemy(t_info *info, int i, int i2, int k);
void	move_enemy2(t_info *info, int i, int i2);
int		key_press_bonus(int keycode, t_info *info);
void	print_move_bonus(t_info *info, int flag);
int		click_key_bonus(t_info *info);

//get_next_line
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*print_arr(char **res);
char	*ft_strdup(char *src);
void	*ft_free(char **arr);
char	*read_line(int fd, int x, char **arr, char **res);
char	*print_arr2(char **temp, char **temp2, char **res, int len);

#endif
