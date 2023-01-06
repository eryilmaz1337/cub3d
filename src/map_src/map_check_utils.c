/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:13:05 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/12/27 19:13:32 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../lib/cub3d.h"

void	name_check(char *str, t_cub3d *main)
{
	int	tmp;
	tmp = open(str, O_RDONLY);
	if (tmp == -1)
		exit_free(main, FILE_NOT_FOUND_ERROR);
	else
	{
		main->map->map_name = ft_strdup(str);
		if (str[0] == '.' && str[1] == '/')
			str = str + 2;
		str = ft_strchr(str, '.');
		if (str == NULL)
			exit_free(main, WRONG_FILE_EXTENSION);
		tmp = ft_strlen(str);
		if (!(tmp == 4 && ft_strnstr(str, ".cub", 4)))
		{
			exit_free(main, WRONG_FILE_EXTENSION);
		}
	}
	close(tmp);
}

int	check_isspace(char s)
{
	if (s != '\0')
		if (s != ' ')
			if (s != '\n')
				if (s != '\r')
					if (s != '\t')
						if (s != '\v')
							if (s != '\f')
								return (1);
	return (0);
}

char	*ft_strjoin_2(char *save, char *buffer)
{
	char	*temp;
	int		i;
	int		l;

	if (!save)
	{
		save = (char *)malloc(sizeof(char) * 1);
		save[0] = '\0';
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen(save) +\
				ft_strlen(buffer) + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (save[i] != '\0')
	{
		temp[i] = save[i];
		i++;
	}
	l = 0;
	while (buffer[l] != '\0')
		temp[i++] = buffer[l++];
	temp[i] = '\0';
	free(save);
	return (temp);
}


void	free_double_Str(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(&s[i]);
		i++;
	}
}

char	**ft_double_strcpy(char **s, int i)
{
	char **map;
	int		a;
	int		c;

	c = i;
	a = 0;
	while (s[c])
		c++;
	map = (char **)malloc(sizeof(char *) * c);
	while (s[i])
	{
		map[a] = (char *)malloc(sizeof(char) * ft_strlen(s[i]));
		map[a] = ft_strcpy(map[a], s[i]);
		i++;
		a++;
	}
	map[a] = NULL;
	return (map);
}

void	set_direction(t_cub3d *main, char s, int c, int b)
{
	main->mini_map = malloc(sizeof (t_cub3d_mini_map));
	main->player = malloc(sizeof (t_player));
	main->player->player_x = (double)b;
	main->player->player_y = (double)c;
	main->player->player_y *= MINI_MAP_HEIGHT / main->map->map_lines_num;
	main->player->player_x *= MINI_MAP_WIDTH / main->map->map_max_line;
	//printf("x:%d y:%d MX:%0.2f MY:%0.2f\n", b, c, main->player->player_x, main->player->player_y)
	main->map->map[c][b]  = '0';
	if (s == 'W')
		main->player->angle = 180.0;
	else if (s == 'S')
		main->player->angle = 270.0;
	else if (s == 'E')
		main->player->angle = 0.0;
	else if (s == 'N')
		main->player->angle = 90.0;
}