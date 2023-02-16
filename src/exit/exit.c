/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:02:01 by uercan            #+#    #+#             */
/*   Updated: 2023/02/13 15:32:05 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

int	ft_close(void)
{
	exit (0);
	return (0);
}

void	write_error(char *s)
{
	write (2, "--------ERROR--------\n", 22);
	write (2, s, ft_strlen(s));
	write (2, "\n", 1);
	exit (EXIT_FAILURE);
}

void	exit_free(t_cub3d *main, int err_no)
{
	if (err_no == PROGRAM_ARG_ERROR)
		write_error("*101* PROGRAM_ARG_ERROR");
	else if (err_no == FILE_NOT_FOUND_ERROR)
		write_error("*102*: FILE_NOT_FOUND_ERROR");
	else if (err_no == WRONG_FILE_EXTENSION)
		write_error("*103*: WRONG_FILE_EXTENSION");
	else if (err_no == INVALID_MAP)
		write_error("*104*: INVALID_MAP");
	else if (err_no == INVALID_CHARACTER)
		write_error("*105*: INVALID_CHARACTER");
	else if (err_no == INVALID_COUNTS)
		write_error("*106*: INVALID_COUNTS");
	else if (err_no == MALLOC_ERROR)
		write_error("*107*: MALLOC_ERROR");
	else if (err_no == MLX_ERROR_INIT)
		write_error("*108*: MLX_ERROR_INIT");
	else if (err_no == MLX_ERROR_WINDOW)
		write_error("*109*: MLX_ERROR_WINDOW");
	else if (err_no == MLX_ERROR_IMG)
		write_error("*110*: MLX_ERROR_IMG");
	free(main->map->map);
}
