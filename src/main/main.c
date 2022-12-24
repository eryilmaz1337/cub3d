/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:58:03 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/12/23 16:14:22 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"


unsigned long	rgb_to_hex(int r, int g, int b)//0x_00_00_ff
{
	return ((r << 16) + (g << 8) + (b));
}
void game_window(t_cub3d *main)
{
	main->mlx = mlx_init();
	if (!main->mlx)
		exit_free(main, MLX_ERROR_INIT);
	main->mlx_window = mlx_new_window(main->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "CUB3D");
	if (!main->mlx_window)
		exit_free(main, MLX_ERROR_WINDOW);
	main->game_img = mlx_new_image(main->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!main->game_img)
		exit_free(main, MLX_ERROR_IMG);
	main->mini_map_img = mlx_new_image(main->mlx, MINI_MAP_WIDTH, MINI_MAP_HEIGHT);
	if (!main->mini_map_img)
		exit_free(main, MLX_ERROR_IMG);
	main->game_img_adress = (int *)mlx_get_data_addr(main->game_img, &main->tmp_img_x, &main->tmp_img_y, &main->tmp_img_z);
	if (!main->game_img_adress)
		exit_free(main, MLX_ERROR_IMG);
	main->mini_map_img_adress = (int *)mlx_get_data_addr(main->mini_map_img, &main->tmp_img_x, &main->tmp_img_y, &main->tmp_img_z);
	if (!main->mini_map_img_adress)
		exit_free(main, MLX_ERROR_IMG);
}

void main_game_img_paint(t_cub3d *main)
{
	int i;
	int k;
	int sky;
	k = 0;
	i = 0;
	sky = SCREEN_HEIGHT / 2;
	while (k != SCREEN_HEIGHT)
	{
		i = -1;
		while (++i != SCREEN_WIDTH && k != sky)
			main->game_img_adress[SCREEN_WIDTH * k + i] = main->map->C_rgb_code;
		i = -1;
		while (++i != SCREEN_WIDTH && k >= sky)
			main->game_img_adress[SCREEN_WIDTH * k + i] = main->map->F_rgb_code;
		k++;
	}
	mlx_put_image_to_window(main->mlx, main->mlx_window, main->game_img, 0, 0);
}

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
			main->mini_map_img_adress[(int)(main->mini_map->map_img_size_x * (y + i) + (x + k))] = color;
		}
	}
}

void map_paint(t_cub3d *main)
{
	int x;
	int y;

	main->mini_map->map_img_size_y = MINI_MAP_HEIGHT / main->map->map_lines_num;
	main->mini_map->map_img_size_x = MINI_MAP_WIDTH / main->map->map_max_line;
	y = -1;
	while (++y != main->map->map_lines_num)
	{
		x = -1;
		printf("%d %p %s\n", y , main->map->map[y], main->map->map[y]);
		// while (++x != main->map->map_max_line)
		// {
		// 	// printf("%c", main->map->map[x][y]);
		// 	if (main->map->map[y][x] == '1')
		// 		ft_pixel_put(main, main->map->map_max_line*x, main->map->map_lines_num*y, 0xffffff);
		// }
	}
}

void game_mini_map_paint(t_cub3d *main)
{
	map_paint(main);
	mlx_put_image_to_window(main->mlx, main->mlx_window, main->mini_map_img, 0, 0);
}

int	ft_close(void)// şimdilik kapatmak için
{
	exit (0);
	return (0);
}

void loop_window_and_game(t_cub3d *main)
{
	main_game_img_paint(main);
	game_mini_map_paint(main);
	mlx_hook(main->mlx_window, 17, (0L), ft_close, main);
	mlx_loop(main->mlx);
}


int main(int argc, char **argv)
{
	t_cub3d *main;

	main = (t_cub3d *)malloc(sizeof(t_cub3d));
	if(!main)
		exit_free(main, MALLOC_ERROR);
	main->map = (t_cub3d_map *)malloc(sizeof(t_cub3d_map));
	if(!main->map)
		exit_free(main, MALLOC_ERROR);
	map_full_check(argc, argv, main); // leak var get_prime_map fonksiyonu
	game_window(main);
	loop_window_and_game(main);
	return (EXIT_SUCCESS);
}
