/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:17:32 by uercan            #+#    #+#             */
/*   Updated: 2023/02/16 15:48:29 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	check_invallid_chracters(char s, t_cub3d *main, int status)
{
	static int	player_c;

	if (status == 0 && check_isspace(s) == 1)
	{
		if (s != 'K' && s != 'A' && s != 'L')
		{
			if (s != '1')
			{
				if (s != '0')
				{
					if (s == 'N' || s == 'W' || s == 'S' || s == 'E')
					{
						player_c++;
						if (player_c > 1)
							exit_free (main, INVALID_COUNTS);
					}
					else
						exit_free (main, INVALID_CHARACTER);
				}
			}
		}
	}
	if (status == 1 && player_c != 1)
		exit_free (main, INVALID_COUNTS);
}

void	set_c_f(t_cub3d *main, int i, int k, int *code)
{
	if (main->map->map[i][k] == 'F')
		main->map->f_rgb_code
			= rgb_to_hex(color_assignment(0, code[0], code[1], code[2]));
	else if (main->map->map[i][k] == 'C')
		main->map->c_rgb_code
			= rgb_to_hex(color_assignment(0, code[0], code[1], code[2]));
}

int	get_val(t_cub3d *main, int a, char *path)
{
	int	b;

	b = 0;
	main->map->val = ft_split(path, ',');
	while (main->map->val[a])
	{
		while (main->map->val[a][b])
		{
			if (main->map->val[a][b] < '0' && main->map->val[a][b] > '9')
				exit_free(main, INVALID_CHARACTER);
			b++;
		}
		a++;
	}
	return (a);
}
