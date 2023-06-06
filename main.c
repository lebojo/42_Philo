/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan <jordan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 03:30:10 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/06 12:09:52 by jordan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

void	*routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (1)
	{
		if (p->state == Thinking)
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
			pthread_mutex_unlock(p->fork);
			pthread_mutex_unlock(p->next_fork);
		}
		if (p->state == Eating)
		{
			p->state = Sleeping;
			p_state(get_now() - *p->gs, p);
			usleep(p->t->sleep * 1000);
		}
		if (p->state == Sleeping)
			p->state = Thinking;
		p_state(get_now() - *p->gs, p);
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
			pthread_mutex_lock(p->l);
			p->state = Dead;
			p_state(get_now() - *p->gs, p);
			exit(0);
		}
	}
}

void	create_philo(t_data *d, int i)
{
	d->p[i].id = i;
	d->p[i].nb_philo = d->nb_philo;
	d->p[i].t = &d->time;
	d->p[i].fork = &d->forks[i];
	d->p[i].next_fork = &d->forks[(i + 1) % d->nb_philo];
	d->p[i].state = Thinking;
	d->p[i].start = get_now();
	d->p[i].last_eat = d->p[i].start;
	d->p[i].gs = &d->start;
	d->p[i].l = &d->lock;
	pthread_create(&d->p[i].tr, NULL, &routine, &d->p[i]);
	pthread_create(&d->p[i].life, NULL, &life, &d->p[i]);
	usleep(150);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	parse(&data, ac, av);
	data.start = get_now();
	data.p = malloc(sizeof(t_philo) * data.nb_philo);
	data.forks = malloc(sizeof(pthread_mutex_t) * data.nb_philo);
	pthread_mutex_init(&data.lock, NULL);
	i = -1;
	while (++i < data.nb_philo)
		pthread_mutex_init(&data.forks[i], NULL);
	i = -1;
	while (++i < data.nb_philo)
		create_philo(&data, i);
	while(1)
		;
	return (0);
}
