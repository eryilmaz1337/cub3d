/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:25:52 by uercan            #+#    #+#             */
/*   Updated: 2023/02/16 15:28:43 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	split_anim_2(t_cub3d *main, int anim)
{
	if (anim % 15 == 0)
	{
		main->map->sp_addr = \
		(int *)mlx_get_data_addr(mlx_xpm_file_to_image(main->mlx, \
		"./texture/sp_3.xpm", \
		&main->tmp_img_x, &main->tmp_img_y), &main->tmp_img_x, \
		&main->tmp_img_y, &main->tmp_img_z);
	}
	if (anim % 20 == 0)
	{
		main->map->sp_addr = \
		(int *)mlx_get_data_addr(mlx_xpm_file_to_image(main->mlx, \
		"./texture/sp_4.xpm", \
		&main->tmp_img_x, &main->tmp_img_y), &main->tmp_img_x, \
		&main->tmp_img_y, &main->tmp_img_z);
	}
	if (anim % 25 == 0)
	{
		main->map->sp_addr = \
		(int *)mlx_get_data_addr(mlx_xpm_file_to_image(main->mlx, \
		"./texture/sp_5.xpm", \
		&main->tmp_img_x, &main->tmp_img_y), &main->tmp_img_x, \
		&main->tmp_img_y, &main->tmp_img_z);
	}
}

void	split_anim(t_cub3d *main, int anim)
{
	if (anim < 5)
	{
		main->map->sp_addr = \
		(int *)mlx_get_data_addr(mlx_xpm_file_to_image(main->mlx, \
		"./texture/sp_1.xpm", \
		&main->tmp_img_x, &main->tmp_img_y), &main->tmp_img_x, \
		&main->tmp_img_y, &main->tmp_img_z);
	}
	if (anim % 10 == 0)
	{
		main->map->sp_addr = \
		(int *)mlx_get_data_addr(mlx_xpm_file_to_image(main->mlx, \
		"./texture/sp_2.xpm", \
		&main->tmp_img_x, &main->tmp_img_y), &main->tmp_img_x, \
		&main->tmp_img_y, &main->tmp_img_z);
	}
	split_anim_2(main, anim);
}
