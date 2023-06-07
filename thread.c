/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan <jordan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 06:39:26 by jordan            #+#    #+#             */
/*   Updated: 2023/06/07 07:14:00 by jordan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

void	take_forks(t_philo	*p)
{
	p->state = Fork;
	pthread_mutex_lock(p->fork);
	p_state(get_now() - *p->gs, p);
	pthread_mutex_lock(p->next_fork);
	p_state(get_now() - *p->gs, p);
	p->state = Eating;
	p->last_eat = get_now();
	p_state(get_now() - *p->gs, p);
	usleep(p->t->eat * 1000);
	p->nb_eat += 1;
	pthread_mutex_unlock(p->fork);
	pthread_mutex_unlock(p->next_fork);
}

void	take_a_nap(t_philo *p)
{
	p->state = Sleeping;
	p_state(get_now() - *p->gs, p);
	usleep(p->t->sleep * 1000);
}

void	*routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (1)
	{
		p_state(get_now() - *p->gs, p);
		if (p->state == Thinking)
			take_forks(p);
		if (p->state == Eating)
			take_a_nap(p);
		if (p->state == Sleeping)
			p->state = Thinking;
	}
}

void	*life(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (1)
	{
		if (get_now() - p->last_eat >= p->t->die)
		{
			p->state = Dead;
			p_state(get_now() - *p->gs, p);
			exit(0);
		}
		if (p->nb_eat == p->t->must_eat)
		{
			*p->nb_meals += 1;
			p->nb_eat += 1;
		}
	}
}
