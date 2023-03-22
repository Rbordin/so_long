/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 11:40:29 by riccardobor       #+#    #+#             */
/*   Updated: 2023/03/22 13:01:30 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_d(t_vars *vars, int x, int y)
{
	vars->flag = 2;
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->background, x * 64, y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->death2, x * 64, y * 64);
}

void	draw_1_and_0(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->wall, x * 64, y * 64);
	if (vars->map[y][x] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->background, x * 64, y * 64);
}

void	draw_p_and_x(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->background, x * 64, y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->tardis.ship, x * 64, y * 64);
		vars->tardis.player_y = y;
		vars->tardis.player_x = x;
	}
	if (vars->map[y][x] == 'X')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->background, x * 64, y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->enemy.e_frame1, x * 64, y * 64);
		vars->enemy.enemy_x = x;
		vars->enemy.enemy_y = y;
	}
}

void	draw_e_and_c(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->background, x * 64, y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->food, x * 64, y * 64);
	}
	if (vars->map[y][x] == 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->background, x * 64, y * 64);
		if (vars->collectable == 0)
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->exit, x * 64, y * 64);
	}
}
