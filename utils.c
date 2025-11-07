/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonandri <jonandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:13:01 by jonandri          #+#    #+#             */
/*   Updated: 2025/08/21 10:05:11 by jonandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_color(int index, int max_index)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (index == max_index)
		return (0x00000000);
	else if (index == 0)
		return (0x00000000);
	else
	{
		t = (double)index / max_index;
		r = (255 * t);
		g = (255 * t);
		b = (255 * t);
		return ((r << 16) | (g) | b << 2);
	}
	return (0);
}

float	ft_re(t_data *vars, int x)
{
	float	x_max;
	float	x_min;
	float	re;

	x_max = ((vars->x) * (vars->scale)) / 2;
	x_min = -x_max;
	re = x_min + x * (vars->scale);
	return (re);
}

float	ft_im(t_data *vars, int y)
{
	float	y_max;
	float	y_min;
	float	im;

	y_max = ((vars->y) * (vars->scale)) / 2;
	y_min = -y_max;
	im = y_min + y * (vars->scale);
	return (im);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel) / 8);
	*(unsigned int *)dst = color;
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (1);
		else if ((unsigned char)s1[i] < (unsigned char)s2[i])
		{
			return (-1);
		}
		i++;
	}
	return (0);
}
