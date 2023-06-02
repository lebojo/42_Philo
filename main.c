/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:16:15 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/02 01:47:04 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

int	invalid_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (0);
	(void)argv;
	return (0);
}

void	*routine(void *philo)
{
	t_philo			p;
	int				tmp;

	p = *(t_philo *)philo;
	while (p.state != 'D')
	{
		if (p.state == 'T')
		{
			can_eat(&p);
		}
		if (p.state == 'S')
		{
			tmp = get_now(p.time);
			philo_state(get_now(p.time), p.id, p.state);
			while (get_now(p.time) - tmp < p.time->sleep && p.state != 'D')
				dying(&p);
			if (p.state != 'D')
				p.state = 'T';
		}
		philo_state(get_now(p.time), p.id, p.state);
	}
	exit (error("I ate a bananas"));
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	if (invalid_args(argc, argv))
		return (error("Args"));
	init_data(&data, &data.time, argc, argv);
	i = -1;
	data.forks = malloc(sizeof(int) * data.nb_philo);
	pthread_mutex_init(&data.lock, NULL);
	while (++i < data.nb_philo)
	{
		data.philo[i].time = &data.time;
		data.philo[i].max = &data.nb_philo;
		data.philo[i].forks = data.forks;
		data.philo[i].id = i;
		data.philo[i].state = 'T';
		data.philo[i].last_eat = 0;
		data.forks[i] = 1;
		data.philo[i].lock = &data.lock;
		pthread_create(&data.philo[i].tr, NULL, &routine, &data.philo[i]);
	}
	while (1)
		;
	return (0);
}
