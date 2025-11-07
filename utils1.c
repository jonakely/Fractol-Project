/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonandri <jonandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:46:47 by jonandri          #+#    #+#             */
/*   Updated: 2025/08/21 10:11:31 by jonandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_is_mark(char *tab, int i, t_data *vars)
{
	int	mark;

	mark = 0;
	while (tab[i])
	{
		if (tab[i] == '.')
		{
			mark++;
			i++;
		}
		else if ((tab[i] >= '0' && tab[i] <= '9'))
			i++;
		else if (tab[i] == ' ' || tab[i] == '\t')
			i++;
		else
			ft_comment(vars);
	}
	return (mark);
}

void	ft_is_float(char *tab, t_data *vars)
{
	int	i;
	int	sign;
	int	mark;

	i = 0;
	sign = 0;
	while (tab[i] == ' ' || tab[i] == '\t')
		i++;
	while (tab[i] == '+' || tab[i] == '-')
	{
		sign++;
		i++;
	}
	if (tab[i] >= '0' && tab[i] <= '9')
	{
		mark = ft_is_mark(tab, i, vars);
		if (mark > 1 || sign > 1)
			ft_comment(vars);
	}
	else
		ft_comment(vars);
}

void	ft_valid(char **argv, int argc, t_data *vars)
{
	int	i;

	i = 2;
	while (i < argc)
	{
		ft_is_float(argv[i], vars);
		i++;
	}
}

static float	ft_is_it(const char *tab, int i, float nb)
{
	float	decimal;
	float	divisor;

	decimal = 0;
	divisor = 1;
	while (tab[i] >= '0' && tab[i] <= '9')
	{
		nb = nb * 10 + (tab[i] - '0');
		i++;
	}
	if (tab[i] == '.')
	{
		i++;
		while (tab[i] >= '0' && tab[i] <= '9')
		{
			decimal = decimal * 10 + (tab[i] - '0');
			divisor *= 10;
			i++;
		}
	}
	nb += decimal / divisor;
	return (nb);
}

float	ft_atof(const char *nptr)
{
	int		i;
	int		m_sign;
	float	nb;

	i = 0;
	m_sign = 1;
	nb = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			m_sign = -1;
		i++;
	}
	nb = ft_is_it(nptr, i, nb);
	return (nb * m_sign);
}
