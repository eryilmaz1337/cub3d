/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:10:05 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/02/14 18:07:58 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648
/*------------ERROR-CODE----------------*/
# define PROGRAM_ARG_ERROR		101
# define FILE_NOT_FOUND_ERROR	102
# define WRONG_FILE_EXTENSION	103
# define INVALID_MAP			104
# define INVALID_CHARACTER		105
# define INVALID_COUNTS			106
# define MALLOC_ERROR			107
# define MLX_ERROR_INIT			108
# define MLX_ERROR_WINDOW		109
# define MLX_ERROR_IMG			110
# define SUCCESSFUL				0
/*--------------------------------------*/

/*------------MAP-SIZE------------------*/
# define SCREEN_WIDTH			1000 / 1
# define SCREEN_HEIGHT			800 / 1
# define MINI_MAP_WIDTH_RATION	3
# define MINI_MAP_HEIGHT_RATION	3
# define MINI_MAP_WIDTH			SCREEN_WIDTH / MINI_MAP_WIDTH_RATION
# define MINI_MAP_HEIGHT		SCREEN_HEIGHT / MINI_MAP_HEIGHT_RATION
/*--------------------------------------*/

/*----------KEY-CODES-------------------*/
# define KEY_ESC				53
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_W					13
# define KEY_LEFT				123
# define KEY_DOWN				125
# define KEY_RIGHT				124
# define KEY_UP					126
# define KEY_SHIFT				257
# define KEY_E					14
# define KEY_T					17

/*--------------------------------------*/

/*----------------MOVE------------------*/
# define MOVE_BEAM_ANGLE_INCREASE_RATIO 0.5
# define MOVE_PERSPECTIVE 66
# define MOVE_PIXEL 1
# define MOVE_ANGLE 2.5
# define MOVE_PIXEL_FAST 5
# define MOVE_MOUSE_CENTER 123
/*--------------------------------------*/

/*----------------USER------------------*/
# define ROT_ANGLE 5
# define ROT_ANGLE_USER 66
/*-------------TEXTURE------------------*/
# define TEX_SIZE 64

#endif
