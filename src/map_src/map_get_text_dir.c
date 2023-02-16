/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get_text_dir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:18:27 by uercan            #+#    #+#             */
/*   Updated: 2023/02/16 15:48:11 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_tex_dir_no(t_cub3d *main, int l, int i, int k)
{
	if (main->map->map[i][k] == 'N'
	&& main->map->map[i][k + 1] == 'O' && l == 0)
	{
		main->map->no_texture_path = get_texture_path(main, i, k);
		return (0);
	}
	else if (l == 0)
		exit_free(main, INVALID_MAP);
	return (-1);
}

int	get_tex_dir_so(t_cub3d *main, int l, int i, int k)
{
	if (main->map->map[i][k] == 'S'
	&& main->map->map[i][k + 1] == 'O' && l == 1)
	{
		main->map->so_texture_path = get_texture_path(main, i, k);
		return (0);
	}
	else if (l == 1)
		exit_free(main, INVALID_MAP);
	return (-1);
}

int	get_tex_dir_we(t_cub3d *main, int l, int i, int k)
{
	if (main->map->map[i][k] == 'W'
	&& main->map->map[i][k + 1] == 'E' && l == 2)
	{
		main->map->we_texture_path = get_texture_path(main, i, k);
		return (0);
	}
	else if (l == 2)
		exit_free(main, INVALID_MAP);
	return (-1);
}

int	get_tex_dir_ea(t_cub3d *main, int l, int i, int k)
{
	if (main->map->map[i][k] == 'E'
	&& main->map->map[i][k + 1] == 'A' && l == 3)
	{
		main->map->ea_texture_path = get_texture_path(main, i, k);
		return (0);
	}
	return (-1);
}
