/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 06:39:26 by jordan            #+#    #+#             */
/*   Updated: 2023/09/24 01:04:03 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

void	set_state(t_philo *p, enum e_s state)
{
	pthread_mutex_lock(p->l);
	p->state = state;
	pthread_mutex_unlock(p->l);
}

void	take_forks(t_philo	*p)
{
	set_state(p, Fork);
	pthread_mutex_lock(p->fork);
	p_state(p);
	pthread_mutex_lock(p->next_fork);
	p_state(p);
	set_state(p, Eating);
	pthread_mutex_lock(p->l);
	p->last_eat = get_now();
	pthread_mutex_unlock(p->l);
	p_state(p);
	wait_time(p->t->eat);
	pthread_mutex_lock(p->l);
	p->nb_eat += 1;
	pthread_mutex_unlock(p->l);
	pthread_mutex_unlock(p->fork);
	pthread_mutex_unlock(p->next_fork);
}

void	take_a_nap(t_philo *p)
{
	set_state(p, Sleeping);
	p_state(p);
	wait_time(p->t->sleep);
	set_state(p, Thinking);
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
