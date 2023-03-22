/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:42:13 by rbordin           #+#    #+#             */
/*   Updated: 2023/03/22 14:16:55 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	animation(t_vars *vars)
{
	if (vars->flag == 1)
	{
		if (vars->enemy_loop < 2000)
		{
			vars->enemy_loop++;
			return (0);
		}
		vars->enemy_loop = 0;
		change_image(vars);
		draw_map(vars);
		vars->enemy.e_stance++;
	}
	return (0);
}

void	info_display(t_vars *vars)
{
	char	*s1;

	s1 = ft_itoa(vars->tardis.move_count);
	mlx_string_put(vars->mlx, vars->win, 150, vars->height + 22,
		0x00FFFFFF, "moves: ");
	mlx_string_put(vars->mlx, vars->win, 250, vars->height + 22,
		0x00FFFFFF, s1);
	free(s1);
}

void	terminal_display(t_vars *vars)
{
	char	*str;

	str = ft_itoa(vars->tardis.move_count);
	ft_putstr("Moves: ");
	ft_putstr(str);
	ft_putstr("\n");
	free(str);
}

void	vertical_death(t_vars *vars, int keycode)
{
	if (keycode == 13 || keycode == 126)
	{
		vars->map[vars->tardis.player_y][vars->tardis.player_x] = '0';
		vars->map[vars->tardis.player_y - 1][vars->tardis.player_x + 1] = 'P';
		vars->map[vars->tardis.player_y - 1][vars->tardis.player_x - 1] = 'D';
	}
	else if (keycode == 1 || keycode == 125)
	{
		vars->map[vars->tardis.player_y][vars->tardis.player_x] = '0';
		vars->map[vars->tardis.player_y + 1][vars->tardis.player_x + 1] = 'P';
		vars->map[vars->tardis.player_y - 1][vars->tardis.player_x + 1] = 'D';
	}
}

void	horizontal_death(t_vars *vars, int keycode)
{
	if (keycode == 0 || keycode == 123)
	{
		vars->map[vars->tardis.player_y][vars->tardis.player_x] = '0';
		vars->map[vars->tardis.player_y - 1][vars->tardis.player_x - 1] = 'P';
		vars->map[vars->tardis.player_y + 1][vars->tardis.player_x - 1] = 'D';
	}
	if (keycode == 2 || keycode == 124)
	{
		vars->map[vars->tardis.player_y][vars->tardis.player_x] = '0';
		vars->map[vars->tardis.player_y + 1][vars->tardis.player_x + 1] = 'P';
		vars->map[vars->tardis.player_y + 1][vars->tardis.player_x - 1] = 'D';
	}
}
