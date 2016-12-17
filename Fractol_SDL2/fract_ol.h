/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:30:54 by cledant           #+#    #+#             */
/*   Updated: 2016/01/24 12:12:34 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <SDL.h>
# include <SDL_ttf.h>
# include <math.h>
# include <string.h>
# include <stdio.h>
# define MANDELBROT 0
# define JULIA 1
# define BURNING_SHIP 2
# define JULIA_BURNING_SHIP 3
# define FONT "gnuolane_rg.ttf"

typedef enum		 e_err
{
	E_INIT,
	E_WINDOW,
	E_SURFACE,
	E_RENDERER,
	E_TEXTURE,
	E_COPY_RENDERER,
	E_CLEAR_RENDERER,
	E_TTF_INIT,
	E_TTF_OPEN,
	E_TTF_SIZE,
	E_TTF_SURF,
	NONE,
}					t_err;

typedef struct      s_texture
{
	SDL_Surface		*surf;
	SDL_Texture		*tex;
	SDL_Rect		rect_s;
	SDL_Rect		rect_d;
}					t_texture;

typedef struct		s_env
{
	/*SYSTEM*/
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	SDL_Event		ev;
	/*TEXTURES*/
	t_texture		fractal;
	t_texture		mandel_name;
	t_texture		julia_name;
	t_texture		bs_name;
	t_texture		julia_bs_name;
	t_texture		iter_name;
	t_texture		iter_counter;
	t_texture		zoom_name;
	t_texture		zoom_counter;
	/*FONT*/
	TTF_Font		*font_m;
	/*COLOR*/
	SDL_Color		c_white;
	SDL_Color		c_black;
	SDL_Color		c_transparent;
	/*VARIABLES*/
	char			render;
	char			s[2048];
	size_t			iter;
	size_t			win_width;
	size_t			win_height;
	int				m_width;
	int				m_height;
	int				m_width_old;
	int				m_height_old;
	int				offset_width;
	int				offset_height;
	double			width_min;
	double			width_max;
	double			height_min;
	double			height_max;
	double			width_pitch;
	double			height_pitch;
	double			zoom;
	char			color;
	char			fractal_nb;
	char			mouse_tracking;
}					t_env;

/*SYSTEM*/
void			fractol_main_loop(t_env *e);
void			fractol_sdl_exit(t_env *e);
void			fractol_error(t_env *e, t_err err);
/*TOOLS*/
t_err			fractol_create_texture_name(t_texture *t, const SDL_Renderer *renderer,
					const TTF_Font *font, const int pos_width, const int pos_height,
					const SDL_Color color, const char *s);
void			fractol_init_texture(t_texture *t);
void			fractol_destroy_texture(t_texture *t);
void			fractol_set_rect(SDL_Rect *rect, const int pos_width,
					const int pos_height, const int width, const int height);
void			fractol_color_pixel(t_texture *t, const char color,
					const size_t win_width, const int i, const int j,
					const size_t cur_it);
void			fractol_set_sdl_color(SDL_Color *color, const unsigned char r,
					const unsigned char g, const unsigned char b,
					const unsigned char a);
/*EVENT*/
void			fractol_reset_view(t_env *e);
void			fractol_zoom_in(t_env *e);
void			fractol_zoom_out(t_env *e);
void			fractol_change_color(t_env *e);
void			fractol_change_iter(t_env *e, size_t type);
void			fractol_move_camera(t_env *e, size_t type);
void			fractol_set_mouse_tracking(t_env *e);
void			fractol_change_fractal(t_env *e);
void			fractol_mouse_position(t_env *e);
char			fractol_resize_window(t_env *e);
int				fractol_seek_offset(int size, int pos);
double			fractol_offset_value(double value, int offset, double pitch);
double			fractol_pitch_value(double min, double max, size_t size);
/*DRAW*/
t_err			fractol_draw_fractal(t_env *e);
t_err			fractol_create_renderer_image(t_env *e);
t_err			fractol_update_iter_zoom(t_env *e);
void			fractol_mandelbrot(t_env *e);
void			fractol_julia(t_env *e);
void			fractol_burningship(t_env *e);
void			fractol_julia_burningship(t_env *e);
int				fractol_calc_mb(double *init_x, double *init_y, double x, double y);
int				fractol_calc_bs(double *init_x, double *init_y, double x, double y);

#endif