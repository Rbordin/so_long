/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:44:31 by riccardobor       #+#    #+#             */
/*   Updated: 2023/03/06 16:51:32 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 5 FUNZIONI //
// caricano gli sprite nel programma //
#include "so_long.h"

int	get_background_and_walls(t_vars *vars)
{
	int	x = 64;
	int	y = 64;
	
	vars->background = mlx_xpm_file_to_image(vars->mlx, "icleblock.xpm", &x, &y);
	if (!vars->background)
		return(0);
    vars->wall = mlx_xpm_file_to_image(vars->mlx, "Penguins_game_sprite/wall/icewall.xpm", &x, &y);
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
	vars->go_down[0] = mlx_xpm_file_to_image(vars->mlx, "Penguins_game_sprite/penguin_down/file da convertire/final_stand_down.xpm", &x, &y);
	vars->go_down[1] = mlx_xpm_file_to_image(vars->mlx, "Penguins_game_sprite/penguin_down/file da convertire/final_bend_down.xpm", &x, &y);
	vars->go_down[2] = mlx_xpm_file_to_image(vars->mlx, "Penguins_game_sprite/penguin_down/file da convertire/final_slide_down.xpm", &x, &y);
	vars->go_left[0] = mlx_xpm_file_to_image(vars->mlx, "Penguins_game_sprite/penguin_left/file da convertire/final_stand_left.xpm", &x, &y);
	vars->go_left[1] = mlx_xpm_file_to_image(vars->mlx, "Penguins_game_sprite/penguin_left/file da convertire/final_bend_left.xpm", &x, &y);
	vars->go_left[2] = mlx_xpm_file_to_image(vars->mlx, "Penguins_game_sprite/penguin_left/file da convertire/final_slide_left.xpm", &x, &y);
	vars->go_right[0] = mlx_xpm_file_to_image(vars->mlx, "Penguins_game_sprite/penguin_right/file da convertire/final_stand_right.xpm", &x, &y);
	vars->go_right[1] = mlx_xpm_file_to_image(vars->mlx, "Penguins_game_sprite/penguin_right/file da convertire/final_bend_right.xpm", &x, &y);
	vars->go_right[2] = mlx_xpm_file_to_image(vars->mlx, "Penguins_game_sprite/penguin_right/file da convertire/final_slide_right.xpm", &x, &y);
	vars->go_up[0] = mlx_xpm_file_to_image(vars->mlx, "Penguins_game_sprite/penguin_up/file da convertire/final_stand_up.xpm", &x, &y);
	vars->go_up[1] = mlx_xpm_file_to_image(vars->mlx, "Penguins_game_sprite/penguin_up/file da convertire/final_bend_up.xpm", &x, &y);
	vars->go_up[2] = mlx_xpm_file_to_image(vars->mlx, "Penguins_game_sprite/penguin_up/file da convertire/final_slide_up.xpm", &x, &y);
	printf("go_down: %p\n", &vars->go_down[0]);
	printf("go_down: %p\n", &vars->go_down[1]);
	printf("go_down: %p\n", &vars->go_down[2]);
	printf("go_left: %p\n", &vars->go_left[0]);
	printf("go_left: %p\n", &vars->go_left[1]);
	printf("go_left: %p\n", &vars->go_left[2]);
	printf("go_right: %p\n", &vars->go_right[0]);
	printf("go_right: %p\n", &vars->go_right[1]);
	printf("go_right: %p\n", &vars->go_right[2]);
	printf("go_up: %p\n", &vars->go_up[0]);
	printf("go_up: %p\n", &vars->go_up[1]);
	printf("go_up: %p\n", &vars->go_up[2]);
	// if (!vars->go_down[0] || !vars->go_down[1] || !vars->go_down[2] || !vars->go_left[0] || !vars->go_left[1] || vars->go_left[2])
	// {
		
	// 	return (0);
	// }
	// else if (!vars->go_right[0] || !vars->go_right[1] || !vars->go_right[2] || !vars->go_up[0] || !vars->go_up[1] || !vars->go_up[2])
	// {
		
	// 	return (0);
	// }
	return (1);
}

int	get_food_and_enemies(t_vars *vars)
{
	int	x;
	int	y;
		
	x = 64;
	y = 64;
	vars->food = mlx_xpm_file_to_image(vars->mlx, "Penguins_game_sprite/food/final_food.xpm", &x, &y);
	if (!vars->food)
		return(0);
	vars->enemy[0] = mlx_xpm_file_to_image(vars->mlx, "Penguins_game_sprite/dog_attack/dog_attack1.xpm", &x, &y);
	vars->enemy[1] = mlx_xpm_file_to_image(vars->mlx, "Penguins_game_sprite/dog_attack/dog_attack2.xpm", &x, &y);
	vars->enemy[2] = mlx_xpm_file_to_image(vars->mlx, "Penguins_game_sprite/dog_attack/dog_attack3.xpm", &x, &y);
	vars->enemy[3] = mlx_xpm_file_to_image(vars->mlx, "Penguins_game_sprite/dog_attack/dog_attack4.xpm", &x, &y);
	printf("enemy: %p\n", vars->enemy[0]);
	printf("enemy: %p\n", vars->enemy[1]);
	printf("enemy: %p\n", vars->enemy[2]);
	printf("enemy: %p\n", vars->enemy[3]);
	if (!vars->enemy[0] || !vars->enemy[1] || !vars->enemy[2] || !vars->enemy[3])
		return (0);
	return(1);	
}

int	get_exit_and_death(t_vars *vars)
{
	int	x;
	int	y;
		
	x = 64;
	y = 64;
	vars->exit[0] = mlx_xpm_file_to_image(vars->mlx, "Penguins_game_sprite/exit/final_exitblock.xpm", &x, &y);
	vars->exit[1] = mlx_xpm_file_to_image(vars->mlx, "Penguins_game_sprite/exit/ice_exit.xpm", &x, &y);
	//vars->death = mlx_xpm_file_to_image(vars->mlx, "Penguins_game_sprite/skull/final_skull.xpm", &x, &y);
	printf("exit 0: %p\n", vars->exit[0]);
	printf("exit 1: %p\n", vars->exit[1]);
	//printf("death: %p\n", vars->death);
	if (!vars->exit[0] || !vars->exit[1] /*|| !vars->death*/)
		return (0);
	return (1);
}

int get_sprites(t_vars *vars)
{
	int	i;
	printf("SPRITE\n");
	i = 0;
	i += get_background_and_walls(vars);
	printf("SPRITE1: %d\n", i);

	i += get_player(vars);
	printf("SPRITE2: %d\n", i);
	
	i += get_food_and_enemies(vars);
	printf("SPRITE3: %d\n", i);

	i += get_exit_and_death(vars);
	printf("SPRITE4: %d\n", i);

	if (i != 4)
	{
		ft_putstr("Error:\nit seems something went wrong. Please try again!");
		exit (1);
	}
	return (i);
	
}