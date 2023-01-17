/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:59:21 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/01/16 13:59:25 by eryilmaz         ###   ########.tr	      */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H
# include "struct.h"
int				move_loop(t_cub3d *main);
int				ft_key_press(int key_code, t_cub3d *main);
int				ft_key_release(int key_code, t_cub3d *main);
int				mouse_cursor(int x, int y, t_cub3d *main);
int				is_wall(t_cub3d *main, double x, double y);
#endif
