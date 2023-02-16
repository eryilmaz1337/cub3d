/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:59:21 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/02/16 15:51:17 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H
# include "struct.h"

int		move_loop(t_cub3d *main);
int		ft_key_press(int key_code, t_cub3d *main);
int		ft_key_release(int key_code, t_cub3d *main);
int		mouse_cursor(int x, int y, t_cub3d *main);
int		is_wall_functions(t_cub3d *main, double x, double y);
int		is_wall_c(t_cub3d *main, double x, double y, char c);
double	get_x_value(t_cub3d *main, int status, double x);
double	get_y_value(t_cub3d *main, int status, double y);
char	is_door(t_cub3d *main, double x, double y);
void	key(t_cub3d *main);
void	split_anim(t_cub3d *main, int anim);
void	sp_calculate(t_cub3d *main, double angle, int location);
#endif
