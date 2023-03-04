/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riccardobordin <riccardobordin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:51:29 by riccardobor       #+#    #+#             */
/*   Updated: 2023/03/04 16:25:51 by riccardobor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// 5 FUNZIONI: controllano la validità della mappa

int checking_edges(t_vars *vars)
{
    int y;
    y = 0;
    while (vars->map[y])
    {
        if ((vars->map[0][y] != '1') && (vars->map[vars->i][y] != '1'))
            return (0);
        y++;
    }
    return (1);
}

int checking_middles(t_vars *vars)
{
    while (vars->i-- > 0)
    {
        if ((vars->map[vars->i][0] != '1') && (vars->map[vars->i][ft_strlen(vars->map[vars->i])] != '1'))
            return (0);
    }
    return (1);
}

int checking_stucture(t_vars *vars)
{
    int x;
    int ret;
    int max;

    x = 1;
    max = ft_strlen(vars->map[0]);
    while (vars->map[x])
	{
		ret = ft_strlen(vars->map[x]);
		if (ret != max)
			return (0);
		x++;
	}
    if (max == x)
		return (0);
    return (1);
}

int checking_elements(t_vars *vars)
{
    int i;
    int player;
    int food;
    int exit;

    i = 0;
    player = 0;
    food = 0;
    exit = 0;
    while (vars->s1)
    {
        if (vars->s1[i] == 'P')
            player += 1;
        else if (vars->s1[i] == 'C')
            food += 1;
        else if (vars->s1[i] == 'E')
            exit += 1;
        i++;
    }
    if (player != 1 || exit != 1 || food == 0)
        return (0);
    return (1);
}

int ft_control(t_vars *vars)
{
    if (!vars->map)
        return (0);
    if (checking_edges(vars) == 0)
        return (0);
	if (checking_stucture(vars) == 0)
        return (0);
    if (checking_middles(vars) == 0)
        return (0);
    if (checking_elements(vars) == 0)
        return (0);
    return (1);
}

