/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:00:44 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/02/14 18:19:54 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	split_anim(t_cub3d *main, int anim)
{
	// void	*anim_sp;

	printf("%d\n", anim);
	if (anim < 5)
	{
		main->map->sp_addr = (int *)mlx_get_data_addr(mlx_xpm_file_to_image(main->mlx, \
		"./texture/sp_1.xpm", &main->tmp_img_x, &main->tmp_img_y), &main->tmp_img_x,
			&main->tmp_img_y, &main->tmp_img_z);
		// anim_sp = mlx_xpm_file_to_image(main->mlx, \
		// "./texture/sp_1.xpm", &main->tmp_img_x, &main->tmp_img_y);
	}
	if (anim % 10 == 0)
	{
		main->map->sp_addr = (int *)mlx_get_data_addr(mlx_xpm_file_to_image(main->mlx, \
		"./texture/sp_2.xpm", &main->tmp_img_x, &main->tmp_img_y), &main->tmp_img_x,
			&main->tmp_img_y, &main->tmp_img_z);
	}
	if (anim % 15 == 0)
	{
		main->map->sp_addr = (int *)mlx_get_data_addr(mlx_xpm_file_to_image(main->mlx, \
		"./texture/sp_3.xpm", &main->tmp_img_x, &main->tmp_img_y), &main->tmp_img_x,
			&main->tmp_img_y, &main->tmp_img_z);
	}
	if (anim % 20 == 0)
	{
		main->map->sp_addr = (int *)mlx_get_data_addr(mlx_xpm_file_to_image(main->mlx, \
		"./texture/sp_4.xpm", &main->tmp_img_x, &main->tmp_img_y), &main->tmp_img_x,
			&main->tmp_img_y, &main->tmp_img_z);
	}
	if (anim % 25 == 0)
	{
		main->map->sp_addr = (int *)mlx_get_data_addr(mlx_xpm_file_to_image(main->mlx, \
		"./texture/sp_5.xpm", &main->tmp_img_x, &main->tmp_img_y), &main->tmp_img_x,
			&main->tmp_img_y, &main->tmp_img_z);
	}
	// main->map->sp_addr = (int *)mlx_get_data_addr(anim_sp, &main->tmp_img_x,
	// 		&main->tmp_img_y, &main->tmp_img_z);
}

int	mouse_cursor(int x, int y, t_cub3d *main)
{
	if (x > MOVE_MOUSE_CENTER)
		main->player->angle -= ROT_ANGLE;
	if (x < MOVE_MOUSE_CENTER)
		main->player->angle += ROT_ANGLE;
	if (y < MOVE_MOUSE_CENTER && main->mini_map->screen_focus
		< (SCREEN_HEIGHT / 2) + (SCREEN_HEIGHT / 4))
		main->mini_map->screen_focus += 100;
	if (y > MOVE_MOUSE_CENTER && main->mini_map->screen_focus
		> SCREEN_HEIGHT / 4)
		main->mini_map->screen_focus -= 100;
	mlx_mouse_move(main->mlx_window, MOVE_MOUSE_CENTER, MOVE_MOUSE_CENTER);
	return (0);
}

void	img_loop(t_cub3d *main)
{
	mlx_put_image_to_window(main->mlx, main->mlx_window, main->game_img, 0, 0);
	put_backscreen(main);
	map_paint(main);
	mlx_put_image_to_window(main->mlx, main->mlx_window,
		main->mini_map_img, 0, 0);
	mlx_put_image_to_window(main->mlx, main->mlx_window,
		main->player->player_img, main->player->player_x,
		main->player->player_y);
	raycasting(main);
}

int	move_loop(t_cub3d *main)
{
	static int	anim;

	key(main);
	split_anim(main, anim);
	if (main->player->key_shift)
		main->player->move_speed = MOVE_PIXEL_FAST;
	if (!main->player->key_shift)
		main->player->move_speed = MOVE_PIXEL;
	if (main->player->dir_left)
		main->player->angle += ROT_ANGLE;
	if (main->player->dir_right)
		main->player->angle -= ROT_ANGLE;
	if (main->player->dir_up && main->mini_map->screen_focus
		< (SCREEN_HEIGHT / 2) + (SCREEN_HEIGHT / 4))
		main->mini_map->screen_focus += 10;
	if (main->player->dir_down && main->mini_map
		->screen_focus > SCREEN_HEIGHT / 4)
		main->mini_map->screen_focus -= 10;
	while (main->player->angle >= 360)
			main->player->angle -= 360;
	while (main->player->angle < 0)
			main->player->angle += 360;
	img_loop(main);
	anim++;
	return (0);
}

int	ft_key_press(int key_code, t_cub3d *main)
{
	if (key_code == KEY_ESC)
		exit(0);
	if (key_code == KEY_A)
		main->player->key_a = true;
	if (key_code == KEY_T)
		main->player->key_t = true;
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
	if (key_code == KEY_A)
		main->player->key_a = false;
	if (key_code == KEY_T)
		main->player->key_t = false;
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
