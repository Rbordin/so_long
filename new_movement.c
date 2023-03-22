/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:58:32 by riccardobor       #+#    #+#             */
/*   Updated: 2023/03/22 13:06:01 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(int keycode, t_vars *vars)
{
	if (keycode == 13 || keycode == 126 || keycode == 1 || keycode == 125)
	{
		vars->steps += vertical_control(keycode, vars);
		if (vars->steps > 0)
			vars->tardis.move_count += 1;
		move_vertical(vars, keycode);
	}
	if (keycode == 0 || keycode == 123 || keycode == 2 || keycode == 124)
	{
		vars->steps += horizontal_control(keycode, vars);
		if (vars->steps > 0)
			vars->tardis.move_count += 1;
		move_horizontal(vars, keycode);
	}
	terminal_display(vars);
	draw_map(vars);
	return (1);
}

int	move_w(t_vars *vars, int keycode)
{
	if (vars->map[vars->tardis.player_y - 1][vars->tardis.player_x] == '1')
		return (0);
	else if (vars->map[vars->tardis.player_y - 1][vars->tardis.player_x] == 'X')
		death(vars, vars->tardis.player_y, vars->tardis.player_x, keycode);
	else if (vars->map[vars->tardis.player_y - 1][vars->tardis.player_x] == 'E'
		&& vars->collectable != 0)
		return (0);
	else if (vars->map[vars->tardis.player_y - 1][vars->tardis.player_x] == 'E')
	{
		vars->map[vars->tardis.player_y - 1][vars->tardis.player_x] = 'P';
		vars->map[vars->tardis.player_y][vars->tardis.player_x] = '0';
		win(vars);
	}
	else
	{
		if (vars->map[vars->tardis.player_y - 1][vars->tardis.player_x] == 'C')
			vars->collectable -= 1;
		vars->map[vars->tardis.player_y - 1][vars->tardis.player_x] = 'P';
		vars->map[vars->tardis.player_y][vars->tardis.player_x] = '0';
		mlx_clear_window(vars->mlx, vars->win);
		draw_map(vars);
	}
	return (0);
}

int	move_s(t_vars *vars, int keycode)
{
	if (vars->map[vars->tardis.player_y + 1][vars->tardis.player_x] == '1')
		return (0);
	else if (vars->map[vars->tardis.player_y + 1][vars->tardis.player_x] == 'X')
		death(vars, vars->tardis.player_y, vars->tardis.player_x, keycode);
	else if (vars->map[vars->tardis.player_y + 1][vars->tardis.player_x] == 'E'
		&& vars->collectable != 0)
		return (0);
	else if (vars->map[vars->tardis.player_y + 1][vars->tardis.player_x] == 'E')
	{
		vars->map[vars->tardis.player_y + 1][vars->tardis.player_x] = 'P';
		vars->map[vars->tardis.player_y][vars->tardis.player_x] = '0';
		win(vars);
	}
	else
	{
		if (vars->map[vars->tardis.player_y + 1][vars->tardis.player_x] == 'C')
			vars->collectable -= 1;
		vars->map[vars->tardis.player_y + 1][vars->tardis.player_x] = 'P';
		vars->map[vars->tardis.player_y][vars->tardis.player_x] = '0';
		mlx_clear_window(vars->mlx, vars->win);
		draw_map(vars);
	}
	return (0);
}

int	move_a(t_vars *vars, int keycode)
{
	if (vars->map[vars->tardis.player_y][vars->tardis.player_x - 1] == '1')
		return (0);
	else if (vars->map[vars->tardis.player_y][vars->tardis.player_x - 1] == 'X')
		death(vars, vars->tardis.player_y, vars->tardis.player_x, keycode);
	else if (vars->map[vars->tardis.player_y][vars->tardis.player_x - 1] == 'E'
		&& vars->collectable != 0)
		return (0);
	else if (vars->map[vars->tardis.player_y][vars->tardis.player_x - 1] == 'E')
	{
		vars->map[vars->tardis.player_y][vars->tardis.player_x - 1] = 'P';
		vars->map[vars->tardis.player_y][vars->tardis.player_x] = '0';
		win(vars);
	}
	else
	{
		if (vars->map[vars->tardis.player_y][vars->tardis.player_x - 1] == 'C')
			vars->collectable -= 1;
		vars->map[vars->tardis.player_y][vars->tardis.player_x - 1] = 'P';
		vars->map[vars->tardis.player_y][vars->tardis.player_x] = '0';
		mlx_clear_window(vars->mlx, vars->win);
		draw_map(vars);
	}
	return (0);
}

int	move_d(t_vars *vars, int keycode)
{
	if (vars->map[vars->tardis.player_y][vars->tardis.player_x + 1] == '1')
		return (0);
	else if (vars->map[vars->tardis.player_y][vars->tardis.player_x + 1] == 'X')
		death(vars, vars->tardis.player_y, vars->tardis.player_x, keycode);
	else if (vars->map[vars->tardis.player_y][vars->tardis.player_x + 1] == 'E'
		&& vars->collectable != 0)
		return (0);
	else if (vars->map[vars->tardis.player_y][vars->tardis.player_x + 1] == 'E')
	{
		vars->map[vars->tardis.player_y][vars->tardis.player_x] = 'P';
		vars->map[vars->tardis.player_y][vars->tardis.player_x - 1] = '0';
		win(vars);
	}
	else
	{
		if (vars->map[vars->tardis.player_y][vars->tardis.player_x + 1] == 'C')
					vars->collectable -= 1;
		vars->tardis.player_x += 1 ;
		vars->map[vars->tardis.player_y][vars->tardis.player_x] = 'P';
		vars->map[vars->tardis.player_y][vars->tardis.player_x - 1] = '0';
		mlx_clear_window(vars->mlx, vars->win);
		draw_map(vars);
	}
	return (0);
}
