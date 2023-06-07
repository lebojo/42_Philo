/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan <jordan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 03:34:42 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/07 14:52:18 by jordan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

char	**copy_av(char **av, int ac)
{
	int		i;
	char	**tmp;
	int		tmp2;

	i = -1;
	tmp = malloc(sizeof(char *) * (ac - 1));
	while (++i < ac - 1)
	{
		tmp2 = zz_atoi(av[i + 1]);
		tmp[i] = zz_itoa(tmp2);
	}
	return (tmp);
}

void	free_tab(char **t, int i)
{
	while (i >= 0)
		free(t[i--]);
	free(t);
}

int	parse(t_data *d, int ac, char **av)
{
	char	**tmp;

	d->nb_philo = zz_atoi(av[1]);
	if (d->nb_philo < 1)
		return (error("Not enough philosophers"));
	d->time.die = zz_atoi(av[2]);
	d->time.eat = zz_atoi(av[3]);
	d->time.sleep = zz_atoi(av[4]);
	if (ac == 6)
	{
		d->time.must_eat = zz_atoi(av[5]);
		if (d->time.must_eat < 1)
			return (error("Not enough meals"));
	}
	else
		d->time.must_eat = -1;
	tmp = copy_av(av, ac);
	if (zz_strcmp(tmp[0], av[1]) || zz_strcmp(tmp[1], av[2])
		|| zz_strcmp(tmp[2], av[3]) || zz_strcmp(tmp[3], av[4]))
		return (error("not a number"));
	free_tab(tmp, ac - 2);
	return (0);
}

unsigned long int	get_now(void)
{
	struct timeval	now;

	if (gettimeofday(&now, NULL))
		return (error("gettimeofday() FAILURE"));
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}
