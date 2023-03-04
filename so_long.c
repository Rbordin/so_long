/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:06:33 by rbordin           #+#    #+#             */
/*   Updated: 2023/03/04 15:00:35 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

int	xclose()
{
	exit(0);
	return (0);
}

int	key_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else
		move(keycode, vars);
	return (0);
}

int ft_count(char *s1)
{
    int i;
    int count;

    count = 0 ;
    i = 0;
    while (s1[i])
    {
        if (s1[i] == '\n')
            count++;
        i++;
    }
    return (count + 1);
}

int	main(void)
{
	t_vars	vars;
	
	start(&vars);
    if (ft_control(&vars) == 0)
       return(0);
	mlx_hook(vars.win, 2, 1L<<0, key_close, &vars);
	mlx_hook(vars.win, 17, 0, xclose, &vars);
	get_sprites(&vars);
	draw_map(&vars);
	mlx_loop(vars.mlx);
}


