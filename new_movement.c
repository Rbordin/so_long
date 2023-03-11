/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:58:32 by riccardobor       #+#    #+#             */
/*   Updated: 2023/03/11 13:27:13 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int move(int keycode, t_vars *vars)
{
    int steps;
    
    if (keycode == 13 || keycode == 126)
    {
        steps += vertical_control(keycode, vars);
            while (steps >= 0)
            {
                mlx_hook(vars->win, 2, 1L<<0, move_w, &vars);
                steps--;
            }
        player_loops(vars, keycode);
    }
    if (keycode == 1 || keycode == 125)
    {
        steps += vertical_control(keycode, vars);
            while (steps >= 0)
            {
                mlx_hook(vars->win, 2, 1L<<0, move_s, &vars);
                steps--;
            }
        player_loops(vars, keycode);
    }    
    if (keycode == 0 || keycode == 123)
    {
        steps += vertical_control(keycode, vars);
            while (steps >= 0)
            {
                mlx_hook(vars->win, 2, 1L<<0, move_a, &vars);
                steps--;
            }
        player_loops(vars, keycode);
    }
    if (keycode == 2 || keycode == 124)
    {
        steps += vertical_control(keycode, vars);
            while (steps >= 0)
            {
                mlx_hook(vars->win, 2, 1L<<0, move_d, &vars);
                steps--;
            }
        player_loops(vars, keycode);
    }
    return (1);
}

void    move_w(t_vars *vars)
{
    if (vars->map[vars->player_y - 1][vars->player_x] == 'X')
        death(vars, vars->player_y, vars->player_x);
    if (vars->map[vars->player_y - 1][vars->player_x] == 'C')
        vars->collectable -= 1;     
    vars->map[vars->player_y - 1][vars->player_x] = '0';
    vars->map[vars->player_y][vars->player_x] = 'P';
    draw_map(vars);
}

void    move_s(t_vars *vars)
{
    if (vars->map[vars->player_y + 1][vars->player_x] == 'X')
        death(vars, vars->player_y, vars->player_x);
    if (vars->map[vars->player_y + 1][vars->player_x] == 'C')
        vars->collectable -= 1;     
    vars->map[vars->player_y + 1][vars->player_x] = '0';
    vars->map[vars->player_y][vars->player_x] = 'P';
    draw_map(vars);
}

void    move_s(t_vars *vars)
{
    if (vars->map[vars->player_y][vars->player_x - 1] == 'X')
        death(vars, vars->player_y, vars->player_x);
    if (vars->map[vars->player_y][vars->player_x - 1] == 'C')
        vars->collectable -= 1;     
    vars->map[vars->player_y][vars->player_x - 1] = '0';
    vars->map[vars->player_y][vars->player_x] = 'P';
    draw_map(vars);
}

void    move_d(t_vars *vars)
{
    if (vars->map[vars->player_y][vars->player_x + 1] == 'X')
        death(vars, vars->player_y, vars->player_x);
    if (vars->map[vars->player_y][vars->player_x + 1] == 'C')
        vars->collectable -= 1;     
    vars->map[vars->player_y][vars->player_x + 1] = '0';
    vars->map[vars->player_y][vars->player_x] = 'P';
    draw_map(vars);
}