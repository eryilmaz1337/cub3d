/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:57:43 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/01/16 13:57:45 by eryilmaz         ###   ########.tr	      */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H
# include "struct.h"
void		loop_window_and_game(t_cub3d *main);
void		mlx_inits(t_cub3d *main);
void		put_backscreen(t_cub3d *main);
void		map_paint(t_cub3d *main);
void		img_colors(int *img, int height, int width, t_color_data color);
void		raycasting(t_cub3d *main);

unsigned long rgb_to_hex(t_color_data color);

double		angle_to_radyan(double ang);

t_color_data color_assignment(int transparent, int red, int green, int blue);
#endif
