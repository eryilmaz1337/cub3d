/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:18:09 by uercan            #+#    #+#             */
/*   Updated: 2022/12/23 16:31:51 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

#ifndef CUB3D_H
# define CUB3D_H

/*------------ERROR-CODE----------------*/
# define PROGRAM_ARG_ERROR		101	//22	EINVAL	Invalid argument
# define FILE_NOT_FOUND_ERROR	102	//2		ENOENT	No such file or directory
# define WRONG_FILE_EXTENSION	103	//59	EBFONT	Bad font file format
# define INVALID_MAP			104
# define INVALID_CHARACTER		105
# define INVALID_COUNTS			106
# define MALLOC_ERROR			107
# define MLX_ERROR_INIT			108
# define MLX_ERROR_WINDOW		109
# define MLX_ERROR_IMG			110
# define SUCCESSFUL				0

/*------------MAP-SIZE--------------*/
# define SCREEN_WIDTH			1920
# define SCREEN_HEIGHT			1080
# define MINI_MAP_WIDTH_RATION	2
# define MINI_MAP_HEIGHT_RATION	2
# define MINI_MAP_WIDTH			SCREEN_WIDTH / MINI_MAP_WIDTH_RATION
# define MINI_MAP_HEIGHT		SCREEN_HEIGHT / MINI_MAP_HEIGHT_RATION

typedef struct s_cub3d_map
{
	char			**map;
	char			*map_name;
	char			*NO_texture_path;
	char			*SO_texture_path;
	char			*WE_texture_path;
	char			*EA_texture_path;
	int				map_line_c;
	unsigned long	F_rgb_code;
	unsigned long	C_rgb_code;
	int				map_lines_num;
	int				map_max_line;
} t_cub3d_map;

typedef struct s_cub3d_mini_map
{
	int				map_img_size_y;
	int				map_img_size_x;
	double			player_x;
	double			player_y;
}	t_cub3d_mini_map;

typedef struct s_cub3d
{
	int					tmp_img_x;
	int					tmp_img_y;
	int					tmp_img_z;
	int					*game_img_adress;
	int					*mini_map_img_adress;
	void				*mlx;
	void				*mlx_window;
	void				*game_img;
	void				*mini_map_img;
	t_cub3d_mini_map	*mini_map;
	t_cub3d_map			*map;
}	t_cub3d;

void	exit_free(t_cub3d *main, int err_no);
void	map_check(t_cub3d *main);
void	map_full_check(int index, char **str, t_cub3d *main);
void	map_down_control(t_cub3d *main);
void	check_invallid_chracters(char s, t_cub3d *main, int x, int y, int status);
void	name_check(char *str, t_cub3d *main);
void	free_double_Str(char **s);
void	get_RGB(t_cub3d *main, int i, int k);
void	get_prime_map(t_cub3d *main, int i);

char	**ft_double_strcpy(char **s, int i);
char	**ft_split_isspace(const char *s);
char	*ft_strjoin_2(char *save, char *buffer);
char	*get_texture_path(t_cub3d *main, int i, int k);

unsigned long	rgb_to_hex(int r, int g, int b);

int		get_SO_path(t_cub3d *main, int i, int k);
int		get_EA_path(t_cub3d *main, int i, int k);
int		get_WE_path(t_cub3d *main, int i, int k);
int		get_C_RGB(t_cub3d *main, int i, int k);
int		get_F_RGB(t_cub3d *main, int i, int k);
int		get_map_parts(t_cub3d *main);
int		check_isspace(char s);

#endif
