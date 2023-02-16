/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_prime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:12:11 by uercan            #+#    #+#             */
/*   Updated: 2023/02/16 15:10:01 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

static void	map_down_check_corners(t_cub3d *main, int i, int k, int s_i)
{
	int	l_i;

	l_i = main->map->map_line_c;
	if (i + 1 < l_i && k + 1 <= \
	(int)ft_strlen(main->map->map[i + 1]) \
	&& k > 0 && (!check_isspace(main->map->map \
	[i + 1][k - 1]) || !check_isspace(main->map->map \
	[i + 1][k + 1])))
		exit_free(main, INVALID_MAP);
	if (i != s_i && k + 1 <= \
	(int)ft_strlen(main->map->map[i - 1]) \
	&& k > 0 && (!check_isspace(main->map->map \
	[i - 1][k - 1]) || !check_isspace(main->map->map \
	[i - 1][k + 1])))
		exit_free(main, INVALID_MAP);
}

static void	map_down_check_c(t_cub3d *main, int i, int k, int s_i)
{
	int	l_i;

	l_i = main->map->map_line_c;
	if (k == (int)ft_strlen(main->map->map[i]) - 1
		&& check_isspace(main->map->map[i][k]) == 1)
		exit_free(main, INVALID_MAP);
	else if (i + 1 < l_i - 2
		&& check_isspace(main->map->map[i + 1][k]) == 0)
		exit_free(main, INVALID_MAP);
	else if (i == l_i
		&& check_isspace(main->map->map[i][k]) == 1)
		exit_free(main, INVALID_MAP);
	else if (k == 0 && check_isspace(main->map->map[i][k]) == 1)
		exit_free(main, INVALID_MAP);
	else if (k - 1 > 0 && check_isspace(main->map->map[i][k]) == 0)
		exit_free(main, INVALID_MAP);
	map_down_check_corners(main, i, k, s_i);
}

static void	map_down_check(t_cub3d *main, int i, int k, int s_i)
{
	check_invallid_chracters(main->map->map[i][k], main, 0);
	if (main->map->map[i][k] != '1'
		&& check_isspace(main->map->map[i][k]) == 1)
	{
		if (i == s_i && check_isspace(main->map->map[i][k]) == 1)
			exit_free(main, INVALID_MAP);
		else if (i - 1 > s_i
			&& check_isspace(main->map->map[i - 1][k]) == 0)
			exit_free(main, INVALID_MAP);
		else if (k + 1 < (int)ft_strlen(main->map->map[i])
			&& check_isspace(main->map->map[i][k + 1]) == 0)
			exit_free(main, INVALID_MAP);
		else
			map_down_check_c(main, i, k, s_i);
	}
}

//{printf("NO:1  i:%d k:%d  O:%c\n", i, k, main->map->map[i][k]);exit (1);}//
void	map_down_control(t_cub3d *main)
{
	int	i;
	int	k;
	int	s_i;
	int	l_i;

	i = get_map_parts(main, 0, 0, 0);
	s_i = i;
	l_i = main->map->map_line_c;
	while (i < main->map->map_line_c - 1)
	{
		k = 0;
		while (k < (int)ft_strlen(main->map->map[i]))
		{
			map_down_check(main, i, k, s_i);
			k++;
		}
		i++;
	}
	check_invallid_chracters(main->map->map[0][0], main, 1);
	get_prime_map(main, s_i);
}
