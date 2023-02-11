/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:13:35 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/02/11 16:06:14 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "struct.h"

void	map_check(t_cub3d *main);
void	map_full_check(int index, char **str, t_cub3d *main);
void	map_down_control(t_cub3d *main);
void	check_invallid_chracters(char s, t_cub3d *main, int status);
void	name_check(char *str, t_cub3d *main);
void	set_direction(t_cub3d *main, char s, int c, int b);
void	get_prime_map(t_cub3d *main, int i);
void	get_rgb(t_cub3d *main, int i, int k);
void	set_c_f(t_cub3d *main, int i, int k, int *code);

char	**ft_double_strcpy(char **s, int i);
char	*ft_strjoin_2(char *save, char *buffer);
char	*get_texture_path(t_cub3d *main, int i, int k);

int		get_val(t_cub3d *main, int a, char *path);
int		get_map_parts(t_cub3d *main, int ret, int l, int k);
int		check_isspace(char s);
int		get_tex_dir_no(t_cub3d *main, int l, int i, int k);
int		get_tex_dir_so(t_cub3d *main, int l, int i, int k);
int		get_tex_dir_we(t_cub3d *main, int l, int i, int k);
int		get_tex_dir_ea(t_cub3d *main, int l, int i, int k);

#endif
