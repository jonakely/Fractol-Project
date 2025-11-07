/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonandri <jonandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:33:36 by jonandri          #+#    #+#             */
/*   Updated: 2025/08/21 10:04:43 by jonandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"

typedef struct s_data
{
	int		y_min;
	int		x_min;
	int		y_max;
	int		x_max;
	float	scale;
	int		y;
	int		x;
	void	*mlx;
	void	*windows;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	float	im;
	float	re;
}			t_data;

typedef struct s_v
{
	int		x;
	int		y;
	int		i;
	int		max_i;
	float	z_im;
	float	z_re;
	float	c_im;
	float	c_re;
	float	sign;
	float	temp;
	int		color;
}			t_v;

int		ft_complex(t_v *v);
int		ft_color(int index, int max_index);
float	ft_re(t_data *vars, int x);
float	ft_im(t_data *vars, int y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_mandelbrot(t_data *vars);
void	ft_julia(t_data *vars);
void	ft_julia_if(t_data *vars);
float	ft_atof(const char *nptr);
void	ft_comment(t_data *vars);
void	ft_is_float(char *tab, t_data *vars);
void	ft_valid(char **argv, int argc, t_data *vars);
void	ft_free_all(t_data *vars);
int		close_window(t_data *vars);
void	ft_free_for_comment(t_data *vars);
#endif