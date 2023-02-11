/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:58:03 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/02/04 14:44:38 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d	*main;

	main = (t_cub3d *)malloc(sizeof(t_cub3d));
	if (!main)
		exit_free(main, MALLOC_ERROR);
	main->map = (t_cub3d_map *)malloc(sizeof(t_cub3d_map));
	if (!main->map)
		exit_free(main, MALLOC_ERROR);
	map_full_check(argc, argv, main);
	mlx_inits(main);
	loop_window_and_game(main);
	return (EXIT_SUCCESS);
}
