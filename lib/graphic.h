/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:57:43 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/02/13 14:15:12 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H
# include "assigments.h"

void			set_last_hit_h(t_cub3d *main, double dx, double dy);
void			set_last_hit_v(t_cub3d *main, double dx, double dy);
void			ray_calculator_c(t_cub3d \
	*main, double distance_v, double distance_h);
void			door_control(t_cub3d *main, double x, double y);
void			loop_window_and_game(t_cub3d *main);
void			textured_wall(t_cub3d *main, \
			int img_loc, int location, int i);
void			mlx_variable_init_value(t_cub3d *main);
void			mlx_img_init(t_cub3d *main);
void			mlx_inits(t_cub3d *main);
void			mlx_img_addr_init(t_cub3d *main);
void			put_backscreen(t_cub3d *main);
void			map_paint(t_cub3d *main);
void			img_colors(int *img, int height, int width, t_color_data color);
void			draw_xpm_to_wall(t_cub3d *main,
					int location, int *xpm);
void			raycasting(t_cub3d *main);
void			draw_3d(t_cub3d *main, double distance, double angle);
void			draw_ray(int x, int y, double angle,
					t_cub3d *main);
int				while_check_h(t_cub3d *main, double vdx, double vdy);
int				while_check_v(t_cub3d *main, double vdx, double vdy);
int				is_wall_tmp(t_cub3d *main, double x, double y);
int				is_wall_v2(t_cub3d *main, double x, double y);
int				if_check_v(t_cub3d *main, double vdy, double vdx);
int				if_check_h(t_cub3d *main, double hdy, double hdx);
unsigned long	rgb_to_hex(t_color_data color);
double			angle_to_radyan(double ang);

t_color_data	color_assignment(int transparent, int red, int green, int blue);

#endif
