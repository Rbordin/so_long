/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:43:36 by riccardobor       #+#    #+#             */
/*   Updated: 2023/03/04 16:57:43 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    death(t_vars *vars, int y, int x)
{
    mlx_clear_window;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->death, x * 64, y * 64 + 64);
	draw_map(vars);
}

t_vars start(t_vars *vars, char *argv)
{
    vars.mlx = mlx_init();
	vars.player_x = 0;
	vars.player_y = 0;
	vars.s1 = "";
	if (control_format(argv) == 0);
		return (0);
	vars.fd = open(argv, O_RDONLY);
	if (vars.fd < 0)
		return (0);
	vars.pd = get_next_line(vars.fd);
	while (vars.pd != NULL)
	{
		vars.s1 = ft_strjoin(vars.s1, vars.pd);
		free(vars.pd);
		vars.pd = get_next_line(vars.fd);
		if (!vars.pd)
			break;
	}
	free(vars.pd);
    vars.map = ft_split(vars.s1, '\n');
	vars.i = ft_count(vars.s1);
    vars.height = vars.i * 64 ;
	vars.width = ft_strlen(vars.map[0]) * 64;
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height + 64, "so_long");
    return (vars);
}