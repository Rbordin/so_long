/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:51:48 by rbordin           #+#    #+#             */
/*   Updated: 2023/03/22 14:19:11 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
# include <sys/time.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct enemy_animation{
	int			enemy_x;
	int			enemy_y;
	int			e_stance;
	void		*e_frame;
	void		*e_frame1;
	void		*e_frame2;
	void		*e_frame3;
}				t_enemy;

typedef struct pg_player{
	void		*player;
	int			player_x;
	int			player_y;
	int			move_count;
	void		*ship;
}				t_player;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			steps;
	char		*s1;
	int			fd;
	char		*pd;
	int			i;
	int			flag;
	char		**map;
	int			map_x;
	int			map_y;
	void		*wall;
	void		*background;
	void		*food;
	int			collectable;
	void		*exit;
	void		*death;
	void		*death1;
	void		*death2;
	t_enemy		enemy;
	int			enemy_stage;
	int			enemy_loop;
	t_player	tardis;
	int			x;
	int			y;
	int			game_status;
}				t_vars;

//main: so_long.c ok
int			xclose(void);
int			key_close(int keycode, t_vars *vars);
int			ft_row_count(char *s1);
int			main(int argc, char **argv);
int			control_format(char	*argv);

//gestisce animazione, display mosse, e parte del movimento: time.c ok

int			animation(t_vars *vars);
void		info_display(t_vars *vars);
void		terminal_display(t_vars *vars);
void		horizontal_death(t_vars *vars, int keycode);
void		vertical_death(t_vars *vars, int keycode);

//movement_utils.c
int			horizontal_control( int keycode, t_vars *vars);
int			vertical_control(int keycode, t_vars *vars);
void		move_vertical(t_vars *vars, int keycode);
void		move_horizontal(t_vars *vars, int keycode);
void		change_image(t_vars *vars);

//funzionalità del gioco: game.c (4 funzioni) ok
t_vars		start(t_vars *vars, char *argv);
void		map_generator(t_vars *vars, char *argv);
void		death(t_vars *vars, int y, int x, int keycode);
void		ft_putstr(char *s1);
void		cleaner(t_vars *vars);

//controllo mappa: control.c
int			ft_control(t_vars *vars);
int			checking_stucture(t_vars *vars);
int			checking_middles(t_vars *vars);
int			checking_edges(t_vars *vars);
int			checking_elements(t_vars *vars);

//parte grafica 1: map.c ok 
int			draw_map(t_vars *vars);
void		char_definer(t_vars *vars, int y, int x);
void		win(t_vars *vars);
void		winning_strings(t_vars *vars);

//parte grafica 2: map_utils.c (4 funzioni) ok
void		draw_d(t_vars *vars, int x, int y);
void		draw_1_and_0(t_vars *vars, int x, int y);
void		draw_p_and_x(t_vars *vars, int x, int y);
void		draw_e_and_c(t_vars *vars, int x, int y);

//parte grafica 3: get_sprites.c ok
int			get_background_and_walls(t_vars *vars);
void		get_sprites(t_vars *vars);
int			get_player(t_vars *vars);
int			get_food_and_enemies(t_vars *vars);
int			get_exit_and_death(t_vars *vars);

//movimenti: new_movement.c ok
int			move(int keycode, t_vars *vars);
int			move_w(t_vars *vars, int keycode);
int			move_d(t_vars *vars, int keycode);
int			move_a(t_vars *vars, int keycode);
int			move_s(t_vars *vars, int keycode);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif
#endif
