/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:47:51 by uercan            #+#    #+#             */
/*   Updated: 2023/01/14 14:31:30 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_map_parts(t_cub3d *main)
{
	int	i;
	int	k;
	int	l;
	int	ret;

	ret = 0;
	l = 0;
	k = 0;
	i = -1;
	while (++i < main->map->map_line_c - 1)
	{
		k = 0;
		while (main->map->map[i][k] != '\0' && check_isspace(main->map->map[i][k]) == 0)
			k++;
		if (main->map->map[i][k] == '\0')
			continue;
		else
		{
			if (main->map->map[i][k] == 'N' && main->map->map[i][k + 1] == 'O' && l == 0)
			{
				l++;
				main->map->NO_texture_path = get_texture_path(main, i, k);
			}
			else if (l == 0)
				{printf("F:%s f:%s, l:%d\n", __FILE__, __FUNCTION__, __LINE__);exit (1);}//exit_free(main, INVALID_MAP);
			else if (main->map->map[i][k] == 'S' && main->map->map[i][k + 1] == 'O' && l == 1)
			{
				l++;
				main->map->SO_texture_path = get_texture_path(main, i, k);
			}
			else if (l == 1)
				{printf("F:%s f:%s, l:%d\n", __FILE__, __FUNCTION__, __LINE__);exit (1);}//exit_free(main, INVALID_MAP);
			else if (main->map->map[i][k] == 'W' && main->map->map[i][k + 1] == 'E' && l == 2)
			{
				l++;
				main->map->WE_texture_path = get_texture_path(main, i, k);
			}
			else if (l == 2)
				{printf("F:%s f:%s, l:%d\n", __FILE__, __FUNCTION__, __LINE__);exit (1);}//exit_free(main, INVALID_MAP);
			else if (main->map->map[i][k] == 'E' && main->map->map[i][k + 1] == 'A' && l == 3)
			{
				l++;
				main->map->EA_texture_path = get_texture_path(main, i, k);
			}
			else if (l == 3)
				{printf("F:%s f:%s, l:%d\n", __FILE__, __FUNCTION__, __LINE__);exit (1);}//exit_free(main, INVALID_MAP);
			else if (main->map->map[i][k] == 'F' && l == 4)
			{
				l++;
				get_RGB(main, i, k);
			}
			else if (l == 4)
				{printf("F:%s f:%s, l:%d\n", __FILE__, __FUNCTION__, __LINE__);exit (1);}//exit_free(main, INVALID_MAP);
			else if (main->map->map[i][k] == 'C' && l == 5)
			{
				l++;
				get_RGB(main, i, k);
			}
			else if (l == 5)
				{printf("F:%s f:%s, l:%d\n", __FILE__, __FUNCTION__, __LINE__);exit (1);}//exit_free(main, INVALID_MAP);
			else if (l == 6)
			{
				ret = i;
				l++;
			}
			else
			{
				if (l == 7 && (main->map->map[i][k] != '1' || main->map->map[i][k] == '0'))
					{printf("F:%s f:%s, l:%d\n", __FILE__, __FUNCTION__, __LINE__);exit (1);}//exit_free(main, INVALID_MAP);
			}
		}
	}
	return (ret);
}

void	check_invallid_chracters(char s, t_cub3d *main, int status)
{
	static int	player_c;

	if (status == 0 && check_isspace(s) == 1)
		if (s != '1')
			if (s != '0')
			{
				if (s == 'N' || s == 'W' || s == 'S' || s == 'E')
				{
					if (player_c == 0)
						player_c++;
					else if (player_c > 1)
						exit_free (main, INVALID_COUNTS);
				}
				else
					exit_free (main, INVALID_CHARACTER);
			}
	if (status == 1 && player_c == 0)
		exit_free (main, INVALID_COUNTS);
}

void	map_down_control(t_cub3d *main)//{printf("NO:1  i:%d k:%d  O:%c\n", i, k, main->map->map[i][k]);exit (1);}//
{
	int i;
	int k;
	int s_i;
	int l_i;
	i = get_map_parts(main);
	s_i = i;
	l_i = main->map->map_line_c;
	while (i < main->map->map_line_c - 1)
	{
		k = 0;
		while (k < (int)ft_strlen(main->map->map[i]))
		{
			check_invallid_chracters(main->map->map[i][k], main, 0);
			if (main->map->map[i][k] != '1' && check_isspace(main->map->map[i][k]) == 1)
			{
				if (i == s_i && check_isspace(main->map->map[i][k]) == 1)
					{printf("F:%s f:%s, l:%d\n", __FILE__, __FUNCTION__, __LINE__);exit (1);}//exit_free(main, INVALID_MAP);
				else if (i - 1 > s_i && check_isspace(main->map->map[i - 1][k]) == 0)
					{printf("F:%s f:%s, l:%d\n", __FILE__, __FUNCTION__, __LINE__);exit (1);}//exit_free(main, INVALID_MAP);
				else if (k + 1 < (int)ft_strlen(main->map->map[i]) && check_isspace(main->map->map[i][k + 1]) == 0)
					{printf("F:%s f:%s, l:%d\n", __FILE__, __FUNCTION__, __LINE__);exit (1);}//exit_free(main, INVALID_MAP);
				else if (k == (int)ft_strlen(main->map->map[i]) - 1 && check_isspace(main->map->map[i][k]) == 1)
					{printf("F:%s f:%s, l:%d\n", __FILE__, __FUNCTION__, __LINE__);exit (1);}//exit_free(main, INVALID_MAP);
				else if (i + 1 < l_i - 1 && check_isspace(main->map->map[i + 1][k]) == 0)
					{printf("F:%s f:%s, l:%d\n", __FILE__, __FUNCTION__, __LINE__);exit (1);}//exit_free(main, INVALID_MAP);
				else if (i == l_i - 1 && check_isspace(main->map->map[i][k]) == 1)
					{printf("F:%s f:%s, l:%d %d %d\n", __FILE__, __FUNCTION__, __LINE__, i, k);exit (1);}//exit_free(main, INVALID_MAP);
				else if (k == 0 && check_isspace(main->map->map[i][k]) == 1)
					{printf("F:%s f:%s, l:%d\n", __FILE__, __FUNCTION__, __LINE__);exit (1);}//exit_free(main, INVALID_MAP);
				else if (k - 1 > 0 && check_isspace(main->map->map[i][k]) == 0)
					{printf("F:%s f:%s, l:%d\n", __FILE__, __FUNCTION__, __LINE__);exit (1);}//exit_free(main, INVALID_MAP);
			}
			k++;
		}
		i++;
	}
	check_invallid_chracters(main->map->map[0][0], main, 1);
	get_prime_map(main, s_i);
}

void map_check(t_cub3d *main)
{
	int		fd;
	char	*line;
	char	*map;
	int		i;

	i = 0;
	map = NULL;
	main->map->map_line_c = 1;
	fd = open(main->map->map_name, O_RDONLY);
	if (fd == -1)
		exit_free(main, FILE_NOT_FOUND_ERROR);
	line = get_next_line(fd);
	while (line)
	{
		map = ft_strjoin_2(map, line);
		free(line);
		line = get_next_line(fd);
	}
	main->map->map = ft_split(map, '\n');

	while (map[i])
	{
		if (i != 0 && map[i] == '\n' && map[i - 1] != '\n')
			main->map->map_line_c++;
		i++;
	}
	free(map);
	close(fd);
	map_down_control(main);
}

void map_full_check(int index, char **str, t_cub3d *main)
{
	if(index == 2)
	{
		name_check(str[1], main);
		map_check(main);
	}
	else
		exit_free(main, PROGRAM_ARG_ERROR);
}
