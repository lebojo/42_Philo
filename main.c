/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 03:30:10 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/06 07:40:59 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

void	*routine(void *philo)
{
	t_philo	*p;
	int		i;

	p = (t_philo *)philo;
	while (p->state != Dead)
	{
		i = 0;
		if (p->state == Fork)
		{
			p_state(get_now() - *p->gs, p->id, Thinking);
			p->state = Fork;
			while (*p->n_state != Fork && p->state != Fork)
			{
				printf("%lu\n", (get_now() - p->last_eat));
				if ((get_now() - p->last_eat) >= (unsigned long int)p->t->die)
				{
					pthread_mutex_lock(p->die);
					p->state = Dead;
					p_state(get_now() - *p->gs, p->id, p->state);
					exit(0);
				}
			}
			p->state = Thinking;
			*p->n_state = Thinking;
			pthread_mutex_lock(&p->fork[p->id]);
			p_state(get_now() - *p->gs, p->id, Fork);
			if (p->id + 1 == p->nb_philo)
				pthread_mutex_lock(&p->fork[0]);
			else
				pthread_mutex_lock(&p->fork[p->id + 1]);
			p_state(get_now() - *p->gs, p->id, Fork);
			p->state = Eating;
			p_state(get_now() - *p->gs, p->id, p->state);
			p->last_eat = get_now();
			usleep(p->t->eat * 1000);
			p->state = Fork;
			*p->n_state = Fork;
			pthread_mutex_unlock(&p->fork[p->id]);
			if (p->id + 1 == p->nb_philo)
				pthread_mutex_unlock(&p->fork[0]);
			else
				pthread_mutex_unlock(&p->fork[p->id + 1]);
			p_state(get_now() - *p->gs, p->id, p->state);
			usleep(p->t->sleep * 1000);
			p->state = Fork;
		}
	}
	return (0);
}

void	create_philo(t_data *d, int i)
{
	d->p[i].id = i;
	d->p[i].t = &d->time;
	d->p[i].start = get_now();
	d->p[i].gs = &d->start;
	d->p[i].nb_philo = d->nb_philo;
	d->p[i].last_eat = d->p[i].start;
	d->p[i].fork = d->forks;
	if (i + 1 == d->nb_philo)
		d->p[i].n_state = &d->p[0].state;
	else
		d->p[i].n_state = &d->p[i + 1].state;
	d->p[i].die = &d->die;
	pthread_mutex_init(&d->forks[i], NULL);
	pthread_create(&d->p[i].tr, NULL, &routine, &d->p[i]);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	i = -1;
	parse(&data, ac, av);
	data.forks = malloc(sizeof(pthread_mutex_t) * data.nb_philo);
	data.p = malloc(sizeof(t_philo) * data.nb_philo);
	pthread_mutex_init(&data.die, NULL);
	data.start = get_now();
	while (++i < data.nb_philo)
		data.p[i].state = Thinking;
	i = -1;
	while (++i < data.nb_philo)
		create_philo(&data, i);
	while (1)
		;
	return (0);
}
