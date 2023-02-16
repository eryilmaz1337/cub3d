/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_assigments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:14:30 by uercan            #+#    #+#             */
/*   Updated: 2023/02/16 12:48:17 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

static void	get_prime_map_while(t_cub3d *main, int b, int c)
{
	while (main->map->map[c])
	{
		b = 0;
		while (main->map->map[c][b])
		{
			if (main->map->map[c][b] == 'N' || main->map->map[c][b] == 'W'
				|| main->map->map[c][b] == 'E' || main->map->map[c][b] == 'S')
				set_direction(main, main->map->map[c][b], c, b);
			b++;
		}
		if (b >= main->map->map_max_line)
			main->map->map_max_line = b;
		c++;
	}
}

void	get_prime_map(t_cub3d *main, int i)
{
	char	**map;
	int		c;

	c = 0;
	map = main->map->map;
	main->map->map = ft_double_strcpy(main->map->map, i);
	while (map[c])
		free(map[c++]);
	free(map);
	main->map->map_lines_num = 0;
	while (main->map->map[main->map->map_lines_num])
		main->map->map_lines_num++;
	main->map->map_max_line = 0;
	get_prime_map_while(main, 0, 0);
}

char	*get_texture_path(t_cub3d *main, int i, int k)
{
	int	y;
	int	z;

	k += 2;
	while (main->map->map[i][k] != '\0'
	&& check_isspace(main->map->map[i][k]) == 0)
			k++;
	if (k == '\0')
		exit_free(main, INVALID_MAP);
	y = k;
	while (main->map->map[i][y] != '\0'
	&& check_isspace(main->map->map[i][y]) == 1)
		y++;
	if (main->map->map[i][y] != '\0')
		z = y + 1;
	else
		return (ft_substr(main->map->map[i], k, y));
	while (main->map->map[i][z] != '\0'
	&& check_isspace(main->map->map[i][z]) == 0)
	{
		if (check_isspace(main->map->map[i][z]) == 1)
			exit_free(main, INVALID_MAP);
		z++;
	}
	return (ft_substr(main->map->map[i], k, y));
}

void	get_rgb(t_cub3d *main, int i, int k)
{
	char	*path;
	int		*code;
	int		a;

	a = 0;
	path = get_texture_path(main, i, k);
	free(main->map->val);
	main->map->val = NULL;
	a = get_val(main, a, path);
	if (a != 3)
		exit_free(main, INVALID_COUNTS);
	code = (int *)malloc(sizeof(int) * 3);
	a = -1;
	while (++a < 3)
		code[a] = ft_atoi(main->map->val[a]);
	a = 0;
	while (main->map->val[a])
	{
		free(main->map->val[a]);
		a++;
	}
	set_c_f(main, i, k, code);
	free(main->map->val[a]);
	free(path);
	free(code);
}
