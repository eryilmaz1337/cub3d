/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get_parts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:23:28 by uercan            #+#    #+#             */
/*   Updated: 2023/02/13 16:44:50 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

static int	get_parts(t_cub3d *main, int l, int i, int k)
{
	if (get_tex_dir_no(main, l, i, k) != -1)
		return (0);
	else if (get_tex_dir_so(main, l, i, k) != -1)
		return (0);
	else if (get_tex_dir_we(main, l, i, k) != -1)
		return (0);
	else if (get_tex_dir_ea(main, l, i, k) != -1)
		return (0);
	else if (l == 3)
		exit_free(main, INVALID_MAP);
	else if (main->map->map[i][k] == 'F' && l == 4)
	{
		get_rgb(main, i, k);
		return (0);
	}
	else if (l == 4)
		exit_free(main, INVALID_MAP);
	else if (main->map->map[i][k] == 'C' && l == 5)
	{
		get_rgb(main, i, k);
		return (0);
	}
	else if (l == 5)
		exit_free(main, INVALID_MAP);
	return (-1);
}

static void	last_if(t_cub3d *main, int i, int k, int l)
{
	if (l == 7 && (main->map->map[i][k] != '1'
		|| main->map->map[i][k] == '0'))
		exit_free(main, INVALID_MAP);
}

int	get_map_parts(t_cub3d *main, int ret, int l, int k)
{
	int	i;

	i = -1;
	while (++i < main->map->map_line_c - 1)
	{
		k = 0;
		while (main->map->map[i][k] != '\0'
		&& check_isspace(main->map->map[i][k]) == 0)
			k++;
		if (main->map->map[i][k] == '\0')
			continue ;
		else
		{
			if (get_parts(main, l, i, k) != -1)
				l++;
			else if (l == 6)
			{
				ret = i;
				l++;
			}
			else
				last_if(main, i, k, l);
		}
	}
	return (ret);
}
