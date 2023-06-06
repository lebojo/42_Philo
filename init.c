/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan <jordan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 03:40:19 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/06 00:53:42 by jordan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

void	init_data(t_data *d, t_time *t, int argc, char **args)
{
	d->nb_philo = zz_atoi(args[1]);
	d->philo = malloc(d->nb_philo * sizeof(t_philo));
	t->eat = zz_atoi(args[3]);
	t->die = zz_atoi(args[2]);
	t->sleep = zz_atoi(args[4]);
	t->start = get_now();
	pthread_mutex_init(&d->died, NULL);
	if (argc > 5)
		t->end = zz_atoi(args[5]);
}
