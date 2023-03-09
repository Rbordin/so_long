/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_loops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 11:40:29 by riccardobor       #+#    #+#             */
/*   Updated: 2023/03/09 15:08:23 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// 5 FUNZIONI: gestiscono il cambio immagine per lo scivolamento

int player_loops(t_vars *vars, int keycode)
{
    if (vars->player_loop < 50000)
    {
        vars->player_loop++;
        return (0);
    }
    vars->player_loop = 0;
    mlx_clear_window(vars->mlx, vars->win);
    if  (keycode == 13 || keycode == 126)
        player_woops(vars);
    if  (keycode == 1 || keycode == 125)
        player_soops(vars);
    if  (keycode == 0 || keycode == 123)
        player_aoops(vars);
    if  (keycode == 2 || keycode == 124)
        player_doops(vars);
    draw_map(vars);
    return (0);
}

int player_woops(t_vars *vars)
{
    
    mlx_destroy_image(vars->mlx, vars->go_up[0]);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->go_up[1], vars->player_y, vars->player_x);
    mlx_destroy_image(vars->mlx, vars->go_up[1]);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->go_up[2], vars->player_y, vars->player_x);
    return (0);
}

int player_soops(t_vars *vars)
{
    mlx_destroy_image(vars->mlx, vars->go_down[0]);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->go_down[1], vars->player_y, vars->player_x);
    mlx_destroy_image(vars->mlx, vars->go_down[1]);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->go_down[2], vars->player_y, vars->player_x);
    return (0);
}

int player_aoops(t_vars *vars)
{
    mlx_destroy_image(vars->mlx, vars->go_left[0]);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->go_left[1], vars->player_y, vars->player_x);
    mlx_destroy_image(vars->mlx, vars->go_left[1]);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->go_left[2], vars->player_y, vars->player_x);
    return (0);
}

int player_doops(t_vars *vars)
{
    mlx_destroy_image(vars->mlx, vars->go_right[0]);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->go_right[1], vars->player_y, vars->player_x);
    mlx_destroy_image(vars->mlx, vars->go_right[1]);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->go_right[2], vars->player_y, vars->player_x);
    return (0);
}



