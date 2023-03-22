/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:44:31 by riccardobor       #+#    #+#             */
/*   Updated: 2023/03/22 13:02:40 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 5 FUNZIONI //
// caricano gli sprite nel programma //
#include "so_long.h"

int	get_background_and_walls(t_vars *vars)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	vars->background = mlx_xpm_file_to_image(vars->mlx,
			"./sprites/space_background.xpm", &x, &y);
	if (!vars->background)
		return (0);
	vars->wall = mlx_xpm_file_to_image(vars->mlx,
			"./sprites/inner_wall.xpm", &x, &y);
	if (!vars->wall)
		return (0);
	return (1);
}

int	get_player(t_vars *vars)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	vars->tardis.ship = mlx_xpm_file_to_image(vars->mlx,
			"./sprites/new_tardis.xpm", &x, &y);
	if (!vars->tardis.ship)
		return (0);
	return (1);
}

int	get_food_and_enemies(t_vars *vars)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	vars->food = mlx_xpm_file_to_image(vars->mlx,
			"./sprites/sonic_screwdriver.xpm", &x, &y);
	if (!vars->food)
		return (0);
	vars->enemy.e_frame1 = mlx_xpm_file_to_image(vars->mlx,
			"./sprites/e_frame1.xpm", &x, &y);
	if (!vars->enemy.e_frame1 || !vars->food)
		return (0);
	return (1);
}

int	get_exit_and_death(t_vars *vars)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	vars->exit = mlx_xpm_file_to_image(vars->mlx,
			"./sprites/space_exit.xpm", &x, &y);
	vars->death1 = mlx_xpm_file_to_image(vars->mlx,
			"./sprites/upper_tardis.xpm", &x, &y);
		vars->death2 = mlx_xpm_file_to_image(vars->mlx,
			"./sprites/lower_tardis.xpm", &x, &y);
	if (!vars->exit || !vars->death1 || !vars->death2)
		return (0);
	return (1);
}

void	get_sprites(t_vars *vars)
{
	int	i;

	i = 0;
	i += get_background_and_walls(vars);
	i += get_player(vars);
	i += get_food_and_enemies(vars);
	i += get_exit_and_death(vars);
	if (i != 4)
	{
		ft_putstr("Error:\nit seems something went wrong. Please try again!");
		exit (1);
	}
}
