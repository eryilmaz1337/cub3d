/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_mini_map_game.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:03:41 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/12/28 19:51:58 by uercan           ###   ########.fr       */
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
			else
				ft_pixel_put(main, main->mini_map->map_img_size_x*x, main->mini_map->map_img_size_y * y, 0xba8576);
		}
	}
}
void game_mini_map_paint(t_cub3d *main)
{
	map_paint(main);
	mlx_put_image_to_window(main->mlx, main->mlx_window, main->mini_map_img, 0, 0);
}

void	game_put_player(t_cub3d *main)
{
	int	i;
	int	k;

	void	*player;
	int		*player_addrs;
	i = 0;
	k = 0;
	player = mlx_new_image(main->mlx, main->mini_map->map_img_size_x, main->mini_map->map_img_size_y);
	player_addrs = (int *)mlx_get_data_addr(player, &main->tmp_img_x, &main->tmp_img_y, &main->tmp_img_z);
	while (k != main->mini_map->map_img_size_y)
	{
		i = -1;
		while (++i != main->mini_map->map_img_size_x)
			player_addrs[main->mini_map->map_img_size_x * k + i] = 0xff0000;
		k++;
	}
	mlx_put_image_to_window(main->mlx, main->mlx_window, player, main->player->player_x, main->player->player_y);
}
