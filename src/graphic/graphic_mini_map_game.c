/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_mini_map_game.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:03:41 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/12/25 18:32:50 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"
void ft_pixel_put(t_cub3d *main, int x, int y, unsigned long color)
{
	int i;
	int k;

	i = -1;
	while (++i < main->mini_map->map_img_size_y)
	{
		k = -1;
		while (++k < main->mini_map->map_img_size_x)
		{
			main->mini_map_img_adress[(int)(MINI_MAP_WIDTH * (y + i) + (x + k))] = color;
		}
	}
}
void map_paint(t_cub3d *main)
{
	int x;
	int y;

	main->mini_map->map_img_size_y = MINI_MAP_HEIGHT / main->map->map_lines_num;
	main->mini_map->map_img_size_x = MINI_MAP_WIDTH / main->map->map_max_line;

	int k=0, i = 0;
	while (k != MINI_MAP_HEIGHT)
	{
		i = -1;
		while (++i != MINI_MAP_WIDTH)
			main->mini_map_img_adress[MINI_MAP_WIDTH * k + i] = rgb_to_hex(255,0,0,0);
		k++;
	}

	y = -1;
	while (main->map->map[++y])
	{
		x = -1;
		//("%d %p %s\n", y , main->map->map[y], main->map->map[y]);
		while (main->map->map[y][++x])
		{
			// printf("%c", main->map->map[x][y]);
			if (main->map->map[y][x] == '1')
				ft_pixel_put(main, main->mini_map->map_img_size_x * x, main->mini_map->map_img_size_y * y, 0xf0ff0f);
			else if (main->map->map[y][x] == '0')
				ft_pixel_put(main, main->mini_map->map_img_size_x*x, main->mini_map->map_img_size_y*y, 0xba8576);
			else if (main->map->map[y][x] != ' ')
				ft_pixel_put(main, main->mini_map->map_img_size_x * x, main->mini_map->map_img_size_y * y, 0xff0000);
		}
	}
}
void game_mini_map_paint(t_cub3d *main)
{
	map_paint(main);
	mlx_put_image_to_window(main->mlx, main->mlx_window, main->mini_map_img, 0, 0);
}

int	move(int key_code, t_cub3d *main)
{
	int	x;
	int	y;

	x = main->mini_map->player_x;
	y = main->mini_map->player_y;
	if (key_code == KEY_ESC)
		exit(0);
	else if (key_code == KEY_D)
	{
		if (main->map->map[y][x + 1] == '0')
		{
			main->map->map[y][x + 1] = 'E';
			main->map->map[y][x] = '0';
			main->mini_map->player_x++;
		}
	}
	else if (key_code == KEY_A)
	{
		if (main->map->map[y][x - 1] == '0')
		{
			main->map->map[y][x - 1] = 'W';
			main->map->map[y][x] = '0';
			main->mini_map->player_x--;
		}
	}
	else if (key_code == KEY_S)
	{
		if (main->map->map[y + 1] && main->map->map[y + 1][x] == '0')
		{
			main->map->map[y + 1][x] = 'S';
			main->map->map[y][x] = '0';
			main->mini_map->player_y++;
		}
	}
	else if (key_code == KEY_W)
	{
		if (main->map->map[y - 1][x] == '0')
		{
			main->map->map[y][x] = '0';
			main->map->map[y - 1][x] = 'N';
			main->mini_map->player_y--;
		}
	}
	game_mini_map_paint(main);
	return (0);
}