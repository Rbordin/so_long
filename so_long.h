/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:51:48 by rbordin           #+#    #+#             */
/*   Updated: 2023/03/07 16:08:30 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define COLLECTABLE 4
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <unistd.h>
# include "minilibx_opengl_20191021/mlx.h"
# include "libft/libft.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	char    *s1;
	int		fd;
	char	*pd;
    int     i;
    char	**map;
	int		map_x;
	int		map_y;
	void	*wall;
	void	*background;
	void	*food;
	int		collectable;
	void	*exit[3];
	void	*death;
	void	*enemy[4];
	int		enemy_stage;
	int		enemy_loop;
	void	*player;
	int		player_x;
	int		player_y;
	int		player_loop;
	void	*go_up[3];
	void	*go_down[3];
	void	*go_left[3];
	void	*go_right[3];
	int		x;
	int		y;

}				t_vars;

//main: so_long.c
int			xclose();
int			key_close(int keycode, t_vars *vars);
int 		ft_count(char *s1);
int			main(int argc, char **argv);
int			control_format(char	*argv);

//get_next_line
char		*get_next_line(int fd);
char		*forget(char *mem);
char		*extract(char *mem);
char		*ft_link(char *mem, char *tmp);
char		*place_holder(int fd, char *mem);
char		*ft_finder(char *mem);

//funzionalità del gioco: game.c
t_vars 		start(t_vars *vars, char *argv);
void		death(t_vars *vars, int y, int x);
void		ft_putstr(char *s1);
int			enemy_attack(t_vars *vars, int x, int y);

//controllo mappa: control.c
int 		ft_control(t_vars *vars);
int 		checking_stucture(t_vars *vars);
int 		checking_middles(t_vars *vars);
int 		checking_edges(t_vars *vars);
int 		checking_elements(t_vars *vars);

//parte grafica 1: map.c
void		draw_map(t_vars *vars);
void		draw_1_and_0(t_vars *vars, int x, int y);
void		draw_p_and_x(t_vars *vars, int x, int y);
void		draw_e_and_c(t_vars *vars, int x, int y);
void    	free_exit(t_vars *vars, int x, int y);

//parte grafica 2: get_sprites.c
int			get_background_and_walls(t_vars *vars);
void 		get_sprites(t_vars *vars);
int			get_player(t_vars *vars);
int			get_food_and_enemies(t_vars *vars);
int			get_exit_and_death(t_vars *vars);

//movimenti: movement.c
int			move(int keycode, t_vars *vars);
void		move_w(t_vars *vars);
void		move_d(t_vars *vars);
void		move_a(t_vars *vars);
void		move_s(t_vars *vars);

//player loops: player_loops.c
int 		player_loops(t_vars *vars, int keycode);
int 		player_doops(t_vars *vars);
int			player_aoops(t_vars *vars);
int			player_soops(t_vars *vars);
int			player_woops(t_vars *vars);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif
#endif