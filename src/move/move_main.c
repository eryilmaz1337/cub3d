/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:00:44 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/02/09 14:41:49 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall(t_cub3d *main, double x, double y)
{
	double	new_x;
	double	new_y;
	double	collider;

	collider = 5;
	// collider = 0;
	// new_x = (x + (main->mini_map->map_img_size_x / 2) - collider) / main->mini_map->map_img_size_x;
	// new_y = (y + (main->mini_map->map_img_size_y / 2)) / main->mini_map->map_img_size_y;
	// if (main->map->map[(int)new_y][(int)new_x] == 'K')
	// {
	// 	return (2);
	// }
	new_x = (x + (main->mini_map->map_img_size_x / 2) - collider) / main->mini_map->map_img_size_x;
	new_y = (y + (main->mini_map->map_img_size_y / 2) - collider) / main->mini_map->map_img_size_y;
	if (main->map->map[(int)new_y][(int)new_x] == '1')
	{
		printf("WHTYUk_sol_üst\n");
		return (1);
	}
	new_x = (x + (main->mini_map->map_img_size_x / 2) + collider) / main->mini_map->map_img_size_x;
	new_y = (y + (main->mini_map->map_img_size_y / 2) - collider) / main->mini_map->map_img_size_y;
	if (main->map->map[(int)new_y][(int)new_x] == '1')
	{
		printf("WHTYUk_sağ_üst\n");
		return (1);
	}
	new_x = (x + (main->mini_map->map_img_size_x / 2) - collider) / main->mini_map->map_img_size_x;
	new_y = (y + (main->mini_map->map_img_size_y / 2) + collider) / main->mini_map->map_img_size_y;
	if (main->map->map[(int)new_y][(int)new_x] == '1')
	{
		printf("WHTYUk_sol_alt\n");
		return (2);
	}
	new_x = (x + (main->mini_map->map_img_size_x / 2) + collider) / main->mini_map->map_img_size_x;
	new_y = (y + (main->mini_map->map_img_size_y / 2) + collider) / main->mini_map->map_img_size_y;
	if (main->map->map[(int)new_y][(int)new_x] == '1')
	{
		printf("WHTYUk_sağ_alt\n");
		return (1);
	}
	return (0);
}

int	mouse_cursor(int x, int y, t_cub3d *main)
{
	if (x > MOVE_MOUSE_CENTER)
		main->player->angle -= ROT_ANGLE;
	if (x < MOVE_MOUSE_CENTER)
		main->player->angle += ROT_ANGLE;
	if (y < MOVE_MOUSE_CENTER && main->mini_map->screen_focus < (SCREEN_HEIGHT / 2) + (SCREEN_HEIGHT / 4))
		main->mini_map->screen_focus += 10;
	if (y > MOVE_MOUSE_CENTER && main->mini_map->screen_focus > SCREEN_HEIGHT / 4)
		main->mini_map->screen_focus -= 10;
	mlx_mouse_move(main->mlx_window, MOVE_MOUSE_CENTER, MOVE_MOUSE_CENTER);
	return (0);
}

int	move_loop(t_cub3d *main)
{
	double	x;
	double	y;
	int		hit_x;
	int		hit_y;

	hit_x = 0;
	hit_y = 0;
	x = main->player->player_x;
	y = main->player->player_y;
	if (main->player->key_shift == true)
		main->player->move_speed = MOVE_PIXEL;
	else if (main->player->key_shift == false)
		main->player->move_speed = MOVE_PIXEL;
	if (main->player->key_w)
	{
		x += cos(angle_to_radyan(main->player->angle));
		if (!is_wall(main, x, main->player->player_y))
			hit_x = 1;
		y += -1 * sin(angle_to_radyan(main->player->angle)) * main->player->move_speed;
		if (!is_wall(main, main->player->player_x, y))
			hit_y = 1;
	}
	if (main->player->key_a)
	{
		x += -1 * sin(angle_to_radyan(main->player->angle)) * main->player->move_speed;
		
		if (!is_wall(main, x, main->player->player_y))
			hit_x = 1;
		y -= cos(angle_to_radyan(main->player->angle));
		if (!is_wall(main, main->player->player_x, y))
			hit_y = 1;
	}
	if (main->player->key_s)
	{
		x += -1 * cos(angle_to_radyan(main->player->angle));
		
		if (!is_wall(main, x, main->player->player_y))
			hit_x = 1;
		y += sin(angle_to_radyan(main->player->angle)) * main->player->move_speed;
		if (!is_wall(main, main->player->player_x, y))
			hit_y = 1;
	}
	if (main->player->key_d)
	{
		x += sin(angle_to_radyan(main->player->angle)) * main->player->move_speed;
		
		if (!is_wall(main, x, main->player->player_y))
			hit_x = 1;
		y += cos(angle_to_radyan(main->player->angle));
		if (!is_wall(main, main->player->player_x, y))
			hit_y = 1;
	}
	if (main->player->dir_left)
		main->player->angle += ROT_ANGLE;
	if (main->player->dir_right)
		main->player->angle -= ROT_ANGLE;
	if (main->player->dir_up && main->mini_map->screen_focus < (SCREEN_HEIGHT / 2) + (SCREEN_HEIGHT / 4))
		main->mini_map->screen_focus += 2;
	if (main->player->dir_down && main->mini_map->screen_focus > SCREEN_HEIGHT / 4)
		main->mini_map->screen_focus -= 2;
	if (hit_x == 1)
	{
		main->player->player_x = x;
		hit_x = 0;
	}
	if (hit_y == 1)
	{
		main->player->player_y = y;
		hit_y = 0;
	}
	while (main->player->angle >= 360)
			main->player->angle -= 360;
	while (main->player->angle < 0)
			main->player->angle += 360;
	mlx_put_image_to_window(main->mlx, main->mlx_window, main->game_img, 0, 0);
	put_backscreen(main);
	map_paint(main);
	mlx_put_image_to_window(main->mlx, main->mlx_window, main->mini_map_img, 0, 0);
	mlx_put_image_to_window(main->mlx, main->mlx_window, main->player->player_img, main->player->player_x, main->player->player_y);
	// mlx_put_image_to_window(main->mlx, main->mlx_window, main->map->hand, 0, 0);
	raycasting(main);
	return (0);
}

int	ft_key_press(int key_code, t_cub3d *main)
{
	if (key_code == KEY_ESC)
		exit(0);
	if (key_code == KEY_A)
		main->player->key_a = true;
	if (key_code == KEY_S)
		main->player->key_s = true;
	if (key_code == KEY_D)
		main->player->key_d = true;
	if (key_code == KEY_W)
		main->player->key_w = true;
	if (key_code == KEY_E)
		main->player->key_e = true;
	if (key_code == KEY_RIGHT)
		main->player->dir_right = true;
	if (key_code == KEY_LEFT)
		main->player->dir_left = true;
	if (key_code == KEY_UP)
		main->player->dir_up = true;
	if (key_code == KEY_DOWN)
		main->player->dir_down = true;
	if (key_code == KEY_SHIFT)
		main->player->key_shift = true;
	return (0);
}

int	ft_key_release(int key_code, t_cub3d *main)
{
	//mlx_clear_window(main->mlx, main->mlx_window);
	if (key_code == KEY_A)
		main->player->key_a = false;
	if (key_code == KEY_S)
		main->player->key_s = false;
	if (key_code == KEY_D)
		main->player->key_d = false;
	if (key_code == KEY_W)
		main->player->key_w = false;
	if (key_code == KEY_E)
		main->player->key_e = false;
	if (key_code == KEY_RIGHT)
		main->player->dir_right = false;
	if (key_code == KEY_LEFT)
		main->player->dir_left = false;
	if (key_code == KEY_UP)
		main->player->dir_up = false;
	if (key_code == KEY_DOWN)
		main->player->dir_down = false;
	if (key_code == KEY_SHIFT)
		main->player->key_shift = false;
	return (0);
}

