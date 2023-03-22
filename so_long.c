/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:06:33 by rbordin           #+#    #+#             */
/*   Updated: 2023/03/22 12:19:14 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

// 5 FUNZIONI: main, controllo del formato e hook
int	xclose(void)
{
	exit(0);
	return (0);
}

int	key_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		cleaner(vars);
		exit(0);
	}
	else if (vars->flag == 1)
		move(keycode, vars);
	return (0);
}

int	ft_row_count(char *s1)
{
	int	i;
	int	count;

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

int	control_format(char	*argv)
{
	int	i;

	i = 0;
	if (!argv)
		return (0);
	while (argv[i] != '.')
		i++;
	if (argv[i + 1] != 'b' && argv[i + 2] != 'e'
		&& argv[i + 3] != 'r' && argv[i + 4] != '\0')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc == 2)
	{
		start(&vars, argv[1]);
		if (ft_control(&vars) == 0)
		{
			printf("no map\n");
			exit (1);
		}
		get_sprites(&vars);
		draw_map(&vars);
		mlx_hook(vars.win, 2, 1L << 0, key_close, &vars);
		mlx_hook(vars.win, 17, 0, xclose, &vars);
		mlx_loop_hook(vars.mlx, animation, &vars);
		mlx_loop(vars.mlx);
	}
	else
	{
		ft_putstr("Error:\nsomething looks wrong, please try again!");
		exit(1);
	}
	cleaner(&vars);
}
