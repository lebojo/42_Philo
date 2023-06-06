/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan <jordan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:55:28 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/06 02:06:44 by jordan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

void	eat(t_philo *p)
{
	pthread_mutex_lock(p->fork);
	philo_state(get_now_rel(p), p->id, 'F');
	pthread_mutex_lock(p->fork + 1);
	philo_state(get_now_rel(p), p->id, 'F');
	p->state = 'E';
	philo_state(get_now_rel(p), p->id, p->state);
	p->last_eat = get_now();
	usleep(p->time->eat * 1000);
	pthread_mutex_unlock(p->fork);
	pthread_mutex_unlock(p->fork + 1);
	p->state = 'S';
}

void	create_philo(t_data *d, int i)
{
	d->philo[i].philo_start = get_now();
	d->philo[i].id = i + 1;
	d->philo[i].state = 'T';
	d->philo[i].last_eat = get_now();
	d->philo[i].time = &d->time;
	d->philo[i].max = d->nb_philo;
	d->philo[i].die = &d->died;
	if (pthread_create(&d->philo[i].tr, NULL, &routine, &d->philo[i])
		|| pthread_create(&d->philo[i].gm, NULL, &dying, &d->philo[i]))
	{
		error(add_str("Creating threads n°", zz_itoa(i), 2));
		exit(1);
	}
	d->philo[i].fork = d->forks;
	pthread_mutex_init(&d->philo[i].fork[i], NULL);
}
