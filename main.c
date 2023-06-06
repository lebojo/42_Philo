/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan <jordan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:16:15 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/06 02:07:21 by jordan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

int	invalid_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (1);
	(void)argv;
	return (0);
}

void	*routine(void *philo)
{
	t_philo			*p;

	p = (t_philo *)philo;
	while (p->state != 'D')
	{
		if (p->state == 'T')
		{
			pthread_mutex_lock(&p->fork[p->id - 1]);
			philo_state(get_now_rel(p), p->id, 'F');
			if (p->id == p->max)
				pthread_mutex_lock(&p->fork[0]);
			else
				pthread_mutex_lock(&p->fork[p->id]);
			philo_state(get_now_rel(p), p->id, 'F');
			philo_state(get_now_rel(p), p->id, 'E');
			p->state = 'E';
			usleep(p->time->eat * 1000);
			p->last_eat = get_now();
			p->state = 'S';
			pthread_mutex_unlock(&p->fork[p->id - 1]);
			if (p->id == p->max)
				pthread_mutex_unlock(&p->fork[0]);
			else
				pthread_mutex_unlock(&p->fork[p->id]);
		}
		if (p->state == 'S')
		{
			philo_state(get_now_rel(p), p->id, p->state);
			usleep(p->time->sleep * 1000);
			if (p->state != 'D')
				p->state = 'T';
		}
		philo_state(get_now_rel(p), p->id, p->state);
	}
	return (0);
}

void	*dying(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (1)
	{
		if (get_now() - p->last_eat >= p->time->die
			&& p->state != 'E')
		{
			pthread_mutex_lock(p->die);
			philo_state(get_now_rel(p), p->id, 'D');
			exit(1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data			data;
	int				i;

	if (invalid_args(argc, argv))
		return (error("Args"));
	init_data(&data, &data.time, argc, argv);
	data.philo = malloc(sizeof(t_philo) * data.nb_philo);
	data.forks = malloc(sizeof(pthread_mutex_t) * data.nb_philo);
	i = -1;
	while (++i < data.nb_philo)
		create_philo(&data, i);
	i = 0;
	while (1)
		;
	return (0);
}
