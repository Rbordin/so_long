/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:56:40 by riccardobor       #+#    #+#             */
/*   Updated: 2023/03/07 15:58:06 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_w(t_vars *vars)
{
    
    printf("move W 1");
    if (vars->map[vars->player_y - 1][vars->player_x] == 'X')
        death(vars, vars->player_y, vars->player_x);
    //vars->player_x +=1;
    else
    {
        while(vars->map[vars->player_y - 1][vars->player_x] != '1')
        {
            printf("move W 2");
            mlx_clear_window(vars->mlx, vars->win);
            //player_loops(vars, keycode);
            if (vars->map[vars->player_y][vars->player_x] == 'C')
                vars->collectable -= 1;
            vars->map[vars->player_y][vars->player_x] = '0';
            vars->map[vars->player_y - 1][vars->player_x] = 'P';
            printf("move W 3");
            draw_map(vars);
        }//vars->player_y -=1;
    }        
}
//while (vars->map[vars->player_y][vars->player_x - 1] != '1')
void move_s(t_vars *vars)
{  
    if (vars->map[vars->player_y][vars->player_x + 1] == 'X')
        death(vars, vars->player_y, vars->player_x);
    //vars->player_x +=1;
    else
    {
        mlx_clear_window(vars->mlx, vars->win);
        if (vars->map[vars->player_y][vars->player_x] == 'C')
            vars->collectable -= 1;
        vars->map[vars->player_y][vars->player_x] = '0';
        vars->map[vars->player_y + 1][vars->player_x] = 'P';
        draw_map(vars);
        //vars->player_y -=1;
    }        
}
void move_a(t_vars *vars)
{  
    if (vars->map[vars->player_y - 1][vars->player_x] == 'X')
        death(vars, vars->player_y, vars->player_x);
    //vars->player_x +=1;
    else
    {
        mlx_clear_window(vars->mlx, vars->win);
        if (vars->map[vars->player_y][vars->player_x] == 'C')
            vars->collectable -= 1;
        vars->map[vars->player_y][vars->player_x] = '0';
        vars->map[vars->player_y][vars->player_x - 1] = 'P';
        draw_map(vars);
        //vars->player_y -=1;
    }        
}
void move_d(t_vars *vars)
{  
    if (vars->map[vars->player_y + 1][vars->player_x] == 'X')
        death(vars, vars->player_y, vars->player_x);
    //vars->player_x +=1;
    else
    {
        
        if (vars->map[vars->player_y][vars->player_x] == 'C')
            vars->collectable -= 1;
        vars->map[vars->player_y][vars->player_x] = '0';
        vars->map[vars->player_y][vars->player_x + 1] = 'P';
        draw_map(vars);
        //vars->player_y -=1;
    }        
}

int move(int keycode, t_vars *vars)
{
    if (keycode == 13 || keycode == 126)
    {
        while (vars->map[vars->player_y - 1][vars->player_x] != '1')
        {
            printf("up\n");
            mlx_clear_window(vars->mlx, vars->win);
            mlx_destroy_image(vars->mlx, vars->go_up[0]);
            mlx_xpm_file_to_image(vars->mlx, vars->go_up[2], &vars->x, &vars->y);
            move_w(vars);
        }
        // mlx_destroy_image(vars->mlx, vars->go_up[2]);
        // mlx_xpm_file_to_image(vars->mlx, vars->go_up[0], &vars->x, &vars->y);
    }
    if (keycode == 1 || keycode == 125)
    {
        while (vars->map[vars->player_y + 1][vars->player_x] != '1')
        {
            printf("down\n");
            move_s(vars);
            //player_loops(vars, keycode);
            vars->player_y++;
        }
    }    
    if (keycode == 0 || keycode == 123)
    {
        while (vars->map[vars->player_y][vars->player_x - 1] != '1')
        {
            printf("sx\n");
            move_a(vars);
            //player_loops(vars, keycode);
            vars->player_x--;
        }
    }
    if (keycode == 2 || keycode == 124)
    {
        while (vars->map[vars->player_y][vars->player_x + 1] != '1')
        {
            printf("dx\n");
            move_d(vars);
            //player_loops(vars, keycode);
            vars->player_x++;
        }
    }
    return (1);
}