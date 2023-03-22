/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:41:18 by rbordin           #+#    #+#             */
/*   Updated: 2023/03/22 14:13:19 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_vertical(t_vars *vars, int keycode)
{
	while (vars->steps > 0)
	{
		if (keycode == 13 || keycode == 126)
			move_w(vars, keycode);
		else if (keycode == 1 || keycode == 125)
			move_s(vars, keycode);
		vars->steps--;
	}
}

void	move_horizontal(t_vars *vars, int keycode)
{
	while (vars->steps > 0)
	{
		if (keycode == 0 || keycode == 123)
			move_a(vars, keycode);
		else if (keycode == 2 || keycode == 124)
			move_d(vars, keycode);
		vars->steps--;
	}
}

int	horizontal_control(int keycode, t_vars *vars)
{
	int	x;
	int	y;
	int	step;

	step = 0;
	x = vars->tardis.player_x;
	y = vars->tardis.player_y;
	while (vars->map[y][x] != '1')
	{
		step++;
		if (keycode == 0 || keycode == 123)
			x--;
		else if (keycode == 2 || keycode == 124)
			x++;
	}
	return (step - 1);
}

int	vertical_control(int keycode, t_vars *vars)
{
	int	x;
	int	y;
	int	step;

	step = 0;
	x = vars->tardis.player_x;
	y = vars->tardis.player_y;
	while (vars->map[y][x] != '1')
	{
		if (keycode == 13 || keycode == 126)
			y--;
		else if (keycode == 1 || keycode == 125)
			y++;
		step++;
	}
	return (step - 1);
}

void	change_image(t_vars *vars)
{
	int	x;
	int	y;

	if (vars->enemy.e_stance == 1)
	{
		vars->enemy.e_frame1 = mlx_xpm_file_to_image(vars->mlx,
				"./sprites/e_frame3.xpm", &x, &y);
	}
	else if (vars->enemy.e_stance == 2)
	{
		vars->enemy.e_frame1 = mlx_xpm_file_to_image(vars->mlx,
				"./sprites/e_frame2.xpm", &x, &y);
	}
	else
	{
		vars->enemy.e_frame1 = mlx_xpm_file_to_image(vars->mlx,
				"./sprites/e_frame1.xpm", &x, &y);
		vars->enemy.e_stance = 0;
	}
}
