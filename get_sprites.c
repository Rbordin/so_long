/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:44:31 by riccardobor       #+#    #+#             */
/*   Updated: 2023/03/04 17:03:37 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 5 FUNZIONI //
// caricano gli sprite nel programma //
#include "so_long.h"

int	get_background_and_walls(t_vars *vars)
{
	int	x = 64;
	int	y = 64;
	
	vars->background = mlx_xpm_file_to_image(vars->mlx, "/Users/rbordin/Desktop/so__long/sprites/ice_sprite.xpm", &x, &y);
	if (!vars->background)
		return(0);
    vars->wall = mlx_xpm_file_to_image(vars->mlx, "sprites/Penguins_game_sprite/wall/icewall.xpm", &x, &y);
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
	vars->go_down[0] = mlx_xpm_file_to_image(vars->mlx, "sprites/Penguins_game_sprite/penguin_down/file da convertire/final_stand_down.xpm", &x, &y);
	vars->go_down[1] = mlx_xpm_file_to_image(vars->mlx, "sprites/Penguins_game_sprite/penguin_down/file da convertire/final_bend_down.xpm", &x, &y);
	vars->go_down[2] = mlx_xpm_file_to_image(vars->mlx, "sprites/Penguins_game_sprite/penguin_down/file da convertire/final_slide_down.xpm", &x, &y);
	vars->go_left[0] = mlx_xpm_file_to_image(vars->mlx, "sprites/Penguins_game_sprite/penguin_left/file da convertire/final_stand_left.xpm", &x, &y);
	vars->go_left[1] = mlx_xpm_file_to_image(vars->mlx, "sprites/Penguins_game_sprite/penguin_left/file da convertire/final_bend_left.xpm", &x, &y);
	vars->go_left[2] = mlx_xpm_file_to_image(vars->mlx, "sprites/Penguins_game_sprite/penguin_left/file da convertire/final_slide_left.xpm", &x, &y);
	vars->go_right[0] = mlx_xpm_file_to_image(vars->mlx, "sprites/Penguins_game_sprite/penguin_right/file da convertire/final_stand_right.xpm", &x, &y);
	vars->go_right[1] = mlx_xpm_file_to_image(vars->mlx, "sprites/Penguins_game_sprite/penguin_right/file da convertire/final_bend_right.xpm", &x, &y);
	vars->go_right[2] = mlx_xpm_file_to_image(vars->mlx, "sprites/Penguins_game_sprite/penguin_right/file da convertire/final_slide_right.xpm", &x, &y);
	vars->go_up[0] = mlx_xpm_file_to_image(vars->mlx, "sprites/Penguins_game_sprite/penguin_up/file da convertire/final_stand_up.xpm", &x, &y);
	vars->go_up[1] = mlx_xpm_file_to_image(vars->mlx, "sprites/Penguins_game_sprite/penguin_up/file da convertire/final_bend_up.xpm", &x, &y);
	vars->go_up[2] = mlx_xpm_file_to_image(vars->mlx, "sprites/Penguins_game_sprite/penguin_up/file da convertire/final_slide_up.xpm", &x, &y);
	return (1);
}

int	get_food_and_enemies(t_vars *vars)
{
	int	x;
	int	y;
		
	x = 64;
	y = 64;
	vars->food = mlx_xpm_file_to_image(vars->mlx, "sprites/Penguins_game_sprite/food/final_food.xpm", &x, &y);
	if (!vars->food)
		return(0);
	vars->enemy[0] = mlx_xpm_file_to_image(vars->mlx, "Penguins_game_sprite/dog_attack/dog_attack1.xpm", &x, &y);
	vars->enemy[1] = mlx_xpm_file_to_image(vars->mlx, "Penguins_game_sprite/dog_attack/dog_attack2.xpm", &x, &y);
	vars->enemy[2] = mlx_xpm_file_to_image(vars->mlx, "Penguins_game_sprite/dog_attack/dog_attack3.xpm", &x, &y);
	vars->enemy[3] = mlx_xpm_file_to_image(vars->mlx, "Penguins_game_sprite/dog_attack/dog_attack4.xpm", &x, &y);
	return(1);	
}

int	get_exit_and_death(t_vars *vars)
{
	int	x;
	int	y;
		
	x = 64;
	y = 64;
	vars->exit[0] = mlx_xpm_file_to_image(vars->mlx, "sprites/Penguins_game_sprite/exit/final_exitblock.xpm", &x, &y);
	vars->exit[1] = mlx_xpm_file_to_image(vars->mlx, "sprites/Penguins_game_sprite/exit/ice_exit.xpm", &x, &y);
	vars->death = mlx_xpm_file_to_image(vars->mlx, "Penguins_game_sprite/skull/final_skull.xpm", &x, &y);
	if (!vars->exit[0] || !vars->exit[1] || !vars->death)
		return (0);
	return (1);
}

int get_sprites(t_vars *vars)
{
	int	i;
	
	i = 0;
	i += get_background_and_walls(vars);
	i += get_player(vars);
	i += get_food_and_enemies(vars);
	i += get_exit_and_death(vars);
	return (i);
	
}