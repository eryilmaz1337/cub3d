/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:47:51 by uercan            #+#    #+#             */
/*   Updated: 2023/02/14 17:27:09 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*get_file_line(int fd, char *map)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		map = ft_strjoin_2(map, line);
		free(line);
		line = get_next_line(fd);
	}
	return (map);
}

void	map_check(t_cub3d *main)
{
	int		fd;
	char	*map;
	int		i;

	i = -1;
	map = NULL;
	main->map->map_line_c = 1;
	fd = open(main->map->map_name, O_RDONLY);
	if (fd == -1)
		exit_free(main, FILE_NOT_FOUND_ERROR);
	map = get_file_line(fd, map);
	main->map->map = ft_split(map, '\n');
	while (main->map->map[++i])
		main->map->map_line_c++;
	printf("%d\n", main->map->map_line_c);
	free(map);
	close(fd);
	map_down_control(main);
}

void	map_full_check(int index, char **str, t_cub3d *main)
{
	if (index == 2)
	{
		name_check(str[1], main);
		map_check(main);
	}
	else
		exit_free(main, PROGRAM_ARG_ERROR);
}
