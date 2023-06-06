/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 03:34:42 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/06 06:13:48 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

void	parse(t_data *d, int ac, char **av)
{
	d->nb_philo = zz_atoi(av[1]);
	d->time.die = zz_atoi(av[2]);
	d->time.eat = zz_atoi(av[3]);
	d->time.sleep = zz_atoi(av[4]);
	if (ac == 6)
		d->time.must_eat = zz_atoi(av[5]);
}

unsigned long int	get_now(void)
{
	struct timeval	now;

	if (gettimeofday(&now, NULL))
		return (error("gettimeofday() FAILURE"));
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}
