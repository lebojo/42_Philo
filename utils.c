/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan <jordan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 03:34:42 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/07 05:30:15 by jordan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

int	parse(t_data *d, int ac, char **av)
{
	d->nb_philo = zz_atoi(av[1]);
	if (d->nb_philo < 1)
		return (error("Not enough philosophers"));
	d->time.die = zz_atoi(av[2]);
	d->time.eat = zz_atoi(av[3]);
	d->time.sleep = zz_atoi(av[4]);
	if (ac == 6)
	{
		d->time.must_eat = zz_atoi(av[5]);
		if (zz_strcmp(zz_itoa(d->time.must_eat), av[5]))
			return (error("not a number"));
		if (d->time.must_eat < 1)
			return (error("Not enough meals"));
	}
	else
		d->time.must_eat = -1;
	if (zz_strcmp(zz_itoa(d->nb_philo), av[1])
		|| zz_strcmp(zz_itoa(d->time.die), av[2])
		|| zz_strcmp(zz_itoa(d->time.eat), av[3])
		|| zz_strcmp(zz_itoa(d->time.sleep), av[4]))
		return (error("not a number"));
	return (0);
}

unsigned long int	get_now(void)
{
	struct timeval	now;

	if (gettimeofday(&now, NULL))
		return (error("gettimeofday() FAILURE"));
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}
