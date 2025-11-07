/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonandri <jonandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:23:11 by jonandri          #+#    #+#             */
/*   Updated: 2025/08/21 10:53:11 by jonandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_zoom(t_data *vars, int x)
{
	if (x == 1)
		vars->scale = vars->scale / 1.01;
	else if (x == 0)
		vars->scale = vars->scale * 1.01;
	if (vars->img)
		mlx_destroy_image(vars->mlx, vars->img);
	ft_julia_if(vars);
}

static int	mouse_hook(int button, int x, int y, t_data *vars)
{
	(void)x;
	(void)y;
	if (button == 4)
		ft_zoom(vars, 1);
	else if (button == 5)
		ft_zoom(vars, 0);
	return (1);
}

static int	key_hook(int keycode, t_data *vars)
{
	if (keycode == 65307)
	{
		ft_free_all(vars);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

static	void	ft_var_to_julia_if(t_v *v, t_data *vars)
{
	v->c_im = vars->im;
	v->c_re = vars->re;
	v->z_im = ft_im(vars, v->y);
	v->z_re = ft_re(vars, v->x);
	v->i = 0;
}

void	ft_julia_if(t_data *vars)
{
	t_v	v;

	v.y = 0;
	vars->img = mlx_new_image(vars->mlx, vars->x, vars->y);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_lenght, &vars->endian);
	while ((v.y++) < vars->y)
	{
		v.x = 0;
		while ((v.x++) < vars->x)
		{
			ft_var_to_julia_if(&v, vars);
			while (v.i < 200)
			{
				if (ft_complex(&v) > 4)
					break ;
				v.i++;
			}
			my_mlx_pixel_put(vars, v.x, v.y, (ft_color(v.i, 200)));
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->windows, vars->img, 0, 0);
	mlx_mouse_hook(vars->windows, mouse_hook, vars);
	mlx_hook(vars->windows, 17, 0, close_window, vars);
	mlx_key_hook(vars->windows, key_hook, vars);
}
