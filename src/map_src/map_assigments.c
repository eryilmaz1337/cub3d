/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_assigments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:14:30 by uercan            #+#    #+#             */
/*   Updated: 2022/12/23 16:14:04 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	get_prime_map(t_cub3d *main, int i) //leak kontrolü yapılmadı
{
	char	**map;
	int		c;
	int		b;

	b = 0;
	c = 0;
	map = main->map->map;
	main->map->map = ft_double_strcpy(main->map->map, i);
	while (map[c])
	{
		free(map[c]);
		c++;
	}
	free(map);
	main->map->map_lines_num = 0;
	while (main->map->map[main->map->map_lines_num])
		main->map->map_lines_num++;
	main->map->map_max_line = 0;
	c = 0;
	while (main->map->map[c])
	{
		b = 0;
		while (main->map->map[c][b])
			b++;
		if (b >= main->map->map_max_line)
			main->map->map_max_line = b;
		c++;
	}
	//printf("%d %d", main->map->map_lines_num, main->map->map_max_line);
	// c = 0;
	// system("leaks cub3d");
	// exit(0);
	// while (map[c] != NULL)
	// {
	// 	printf("*%s*\n", map[c]);
	// 	free(map[c]);
	// 	c++;
	// }
	// free(map);
}

char	*get_texture_path(t_cub3d *main, int i, int k)
{
	int	y;
	int	z;

	k += 2;
	while (main->map->map[i][k] != '\0' && check_isspace(main->map->map[i][k]) == 0)
			k++;
	if (k == '\0')
		exit_free(main, INVALID_MAP);
	y = k;
	while (main->map->map[i][y] != '\0' && check_isspace(main->map->map[i][y]) == 1)
		y++;
	if (main->map->map[i][y] != '\0')
		z = y + 1;
	else
		return (ft_substr(main->map->map[i], k, y));
	while (main->map->map[i][z] != '\0' && check_isspace(main->map->map[i][z]) == 0)
	{
		if (check_isspace(main->map->map[i][z]) == 1)
			exit_free(main, INVALID_MAP);
		z++;
	}
	return (ft_substr(main->map->map[i], k, y));
}

void	get_RGB(t_cub3d *main, int i, int k)
{
	char	**val;
	char	*path;
	int		*code;
	int		a;
	int		b;

	a = 0;
	b = 0;
	path = get_texture_path(main, i, k);
	val = ft_split(path, ',');
	while (val[a])
	{
		while (val[a][b])
		{
			if (val[a][b] < '0' && val[a][b] > '9')
				exit_free(main, INVALID_CHARACTER);
			b++;
		}
		a++;
	}
	if (a != 3)
		exit_free(main, INVALID_COUNTS);
	code = (int *)malloc(sizeof(int) * 3);
	a = -1;
	while (++a < 3)
		code[a] = ft_atoi(val[a]);
	//printf("sa! %c\n", main->map->map[i][k]);
	if (main->map->map[i][k] == 'F')
		main->map->F_rgb_code = rgb_to_hex(code[0], code[1], code[2]);
	else if (main->map->map[i][k] == 'C')
		main->map->C_rgb_code = rgb_to_hex(code[0], code[1], code[2]);
	//printf("%c: %lu\n", main->map->map[i][k],main->map->F_rgb_code);
}
