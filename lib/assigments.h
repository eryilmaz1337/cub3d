/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigments.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:39:48 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/02/16 15:54:09 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSIGMENTS_H
# define ASSIGMENTS_H
# include <stdbool.h>

typedef struct s_ray
{
	bool	hit_v;
	bool	hit_h;
	bool	sp_ray;
	char	lh_x;
	char	lh_y;
	char	last_hit;
	double	pos_x;
	double	pos_y;
	double	distance;
	double	sp_distance;
	double	sp_value;
	double	sp_angle;
	double	sp_lenght;
	double	o_distance;
	double	sp_y;
	double	sp_x;
	int		dir_y;
	int		dir_x;
	int		door_x;
	int		door_y;
	int		ray_number;
}	t_ray;

typedef struct s_cub3d_map
{
	void			*hand;
	void			*hand_addr;
	void			*door_img;
	void			*sp_img;
	void			*so_texture_img;
	void			*no_texture_img;
	void			*we_texture_img;
	void			*ea_texture_img;
	char			**map;
	char			**val;
	char			*map_name;
	char			*no_texture_path;
	char			*so_texture_path;
	char			*we_texture_path;
	char			*ea_texture_path;
	unsigned long	f_rgb_code;
	unsigned long	c_rgb_code;
	int				map_line_c;
	int				map_lines_num;
	int				map_max_line;
	int				*no_texture_addr;
	int				*we_texture_addr;
	int				*ea_texture_addr;
	int				*so_texture_addr;
	int				*door_addr;
	int				*sp_addr;
	int				*xpm_tmp;
}	t_cub3d_map;

typedef struct s_cub3d_mini_map
{
	int		width;
	int		height;
	int		map_img_size_y;
	int		map_img_size_x;
	int		*ray_addr;
	void	*ray_img;
	int		screen_focus;

}	t_cub3d_mini_map;

typedef struct s_player
{
	bool			key_w;
	bool			key_s;
	bool			key_d;
	bool			key_a;
	bool			key_e;
	bool			key_shift;
	bool			dir_right;
	bool			dir_left;
	bool			dir_up;
	bool			dir_down;
	int				*player_addr;
	double			move_speed;
	double			p_last_x;
	double			p_last_y;
	double			player_x;
	double			player_y;
	double			def_p_x;
	double			def_p_y;
	double			angle;
	void			*player_img;
}	t_player;

typedef struct s_color_data
{
	int	transparent;
	int	red;
	int	green;
	int	blue;
	int	tmp_x;
	int	tmp_y;
	int	flag;
}	t_color_data;

typedef struct s_cub3d
{
	int					tmp_img_x;
	int					tmp_img_y;
	int					tmp_img_z;
	int					*game_img_adress;
	int					*mini_map_img_adress;
	int					wh;
	void				*mlx;
	void				*mlx_window;
	void				*game_img;
	void				*mini_map_img;
	t_cub3d_mini_map	*mini_map;
	t_cub3d_map			*map;
	t_player			*player;
	t_ray				ray;
}	t_cub3d;

#endif
