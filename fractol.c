/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonandri <jonandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:33:21 by jonandri          #+#    #+#             */
/*   Updated: 2025/08/21 10:04:49 by jonandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_complex(t_v *v)
{
	v->temp = (v->z_re * v->z_re) - (v->z_im * v->z_im) + v->c_re;
	v->z_im = 2 * v->z_re * v->z_im + v->c_im;
	v->z_re = v->temp;
	v->sign = (v->z_im * v->z_im) + (v->z_re * v->z_re);
	return (v->sign);
}

void	ft_comment(t_data *vars)
{
	write(2, "Here is the list of valid parameters:\n", 39);
	write(2, "mandelbrot | julia | julia [real] [imaginary]\n", 46);
	ft_free_for_comment(vars);
	exit (EXIT_FAILURE);
}

static void	ft_is_argv2(char *argv, t_data *vars)
{
	if (ft_strncmp(argv, "mandelbrot", 12) == 0)
	{
		vars->windows = mlx_new_window(vars->mlx, vars->x, vars->y, "fractol");
		ft_mandelbrot(vars);
	}
	else if (ft_strncmp(argv, "julia", 8) == 0)
	{
		vars->windows = mlx_new_window(vars->mlx, vars->x, vars->y, "fractol");
		ft_julia(vars);
	}
	else
		ft_comment(vars);
}

static void	ft_is_argv4(char *av, char **argv, int argc, t_data *vars)
{
	ft_valid(argv, argc, vars);
	if (ft_strncmp(av, "julia", 8) == 0)
	{
		vars->windows = mlx_new_window(vars->mlx, vars->x, vars->y, "fractol");
		vars->re = ft_atof(argv[2]);
		vars->im = ft_atof(argv[3]);
		ft_julia_if(vars);
	}
	else
		ft_comment(vars);
}

int	main(int argc, char **argv)
{
	t_data	vars;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		exit(EXIT_FAILURE);
	vars.scale = 0.005;
	vars.y = 800;
	vars.x = 1280;
	if (argc == 2)
		ft_is_argv2(argv[1], &vars);
	else if (argc == 4)
		ft_is_argv4(argv[1], argv, argc, &vars);
	else
		ft_comment(&vars);
	mlx_loop(vars.mlx);
	ft_free_all(&vars);
	return (0);
}
