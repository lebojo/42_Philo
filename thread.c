/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 06:39:26 by jordan            #+#    #+#             */
/*   Updated: 2023/09/21 02:04:15 by lebojo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

void	take_forks(t_philo	*p)
{
	p->state = Fork;
	pthread_mutex_lock(p->fork);
	p_state(p);
	pthread_mutex_lock(p->next_fork);
	p_state(p);
	p->state = Eating;
	pthread_mutex_lock(p->l);
	p->last_eat = get_now();
	pthread_mutex_unlock(p->l);
	p_state(p);
	wait_time(p->t->eat);
	p->nb_eat += 1;
	pthread_mutex_unlock(p->fork);
	pthread_mutex_unlock(p->next_fork);
}

void	take_a_nap(t_philo *p)
{
	p->state = Sleeping;
	p_state(p);
	wait_time(p->t->sleep);
	p->state = Thinking;
}

void	*routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (1)
	{
		p_state(p);
		take_forks(p);
		take_a_nap(p);
	}
}

void	*life(void *philo)
{
	t_philo				*p;
	unsigned long int	time;

	p = (t_philo *)philo;
	while (1)
	{
		time = get_now();
		if (time - p->last_eat >= p->t->die)
		{
			p->state = Dead;
			p_state(p);
			*p->nb_meals = -42;
		}
		if (p->nb_eat == p->t->must_eat)
		{
			pthread_mutex_lock(p->l);
			*p->nb_meals += 1;
			p->nb_eat += 1;
			pthread_mutex_unlock(p->l);
		}
	}
}

void	clean_exit(t_data *d)
{
	int	i;

	i = -1;
	while (++i < d->nb_philo)
		pthread_mutex_destroy(&d->forks[i]);
	pthread_mutex_destroy(&d->lock);
	free(d->forks);
	free(d->p);
	exit(0);
}
