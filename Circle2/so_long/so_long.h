/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:39:49 by seykim            #+#    #+#             */
/*   Updated: 2023/06/12 18:43:02 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "mlx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

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
	int		img_width;
	int		img_height;
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
	char	**visited;
	t_mlx	*my_mlx;
}	t_info;

//setting mlx
t_mlx	*my_mlx_init(int size_col, int size_row);
t_info	*size_init(char **argv);
t_info	*info_init(void);
void	my_mlx_print(char **arr2, t_mlx *my_mlx);
char	**get_arr2(char **arr2, t_info *info, int i, char **argv);
char	**visited(t_info *info, char **arr2);

//map error check
int		error_check(char **arr2, t_info *info);
int		error_check2(int index_row, int index_col, char **arr2, t_info *info);
int		error_check3(int row, int col, char **arr2, t_info *info);
int		dfs(char **arr2, int col, int row, t_info *info);
char	**ft_free2(char **newstr, int idx);
void	print_error(int flag);

//event hook
void	key_init(t_info *info, char **arr2);
void	move_w(t_info *info);
void	move_s(t_info *info);
void	move_a(t_info *info);
void	move_d(t_info *info);
int		key_press(int keycode, t_info *info);
void	print_move(t_info *info, int flag);
int		click_key(t_info *info);

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
