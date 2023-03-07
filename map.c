/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:54:52 by riccardobor       #+#    #+#             */
/*   Updated: 2023/03/07 16:09:18 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// 5 FUNZIONI: applicano gli sprites ai relativi valori

void	draw_map(t_vars *vars)
{
	int		x;
	int		y;
	y = 0;
	if (!vars->map)
		return ;

	while (y < vars->i)
	{
		x = 0;
		while (x < vars->width / 64)
		{
			if (vars->map[y][x] == '1' || vars->map[y][x] == '0')
			{
				draw_1_and_0(vars, x, y);
					
			}
			else if (vars->map[y][x] == 'P' || vars->map[y][x] == 'X')
			{
				draw_p_and_x(vars, x, y);
			}
			else if (vars->map[y][x] == 'C' || vars->map[y][x] == 'E')
			{
					draw_e_and_c(vars, x, y);
			}
			x++;
		}
		y++;
	}
}

void	draw_1_and_0(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, x * 64, y * 64);

	}
	if (vars->map[y][x] == '0')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->background, x * 64, y * 64);
	}
}

void	draw_p_and_x(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->background, x * 64, y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->go_down[1], x * 64, y * 64);
		vars->player_y = y;
    	vars->player_x = x;
	}
	if (vars->map[y][x] == 'X')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->background, x * 64, y * 64);
		enemy_attack(vars, y, x);
	}
}

void	draw_e_and_c(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->background, x * 64, y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->food, x * 64, y * 64);
	}
	if (vars->map[y][x] == 'E')
	{
		// if (vars->collectable == 0)
		// 	free_exit(vars, y, x);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->background, x * 64, y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exit[1], x * 64, y * 64);
	}
}

void    free_exit(t_vars *vars, int x, int y)
{
        mlx_destroy_image(vars->mlx, vars->exit[1]);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exit[2], x * 64, y * 64);
        draw_map(vars);
}