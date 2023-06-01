/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:16:15 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/01 20:00:14 by jchapell         ###   ########.fr       */
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
	t_philo	p;

	p = *(t_philo *)philo;
	printf("EAT: %i\n", p.time->eat);
	philo_state(2, p.id, p.state);
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
	while (++i < data.nb_philo)
	{
		data.philo[i].time = &data.time;
		data.philo[i].forks = data.forks;
		data.philo[i].id = i + 1;
		data.philo[i].state = 'T';
		data.forks[i] = 1;
		pthread_create(&data.philo[i].tr, NULL, &routine, &data.philo[i]);
		usleep(199);
	}
	while (++i < data.nb_philo)
	{
		pthread_kill(data.philo[i].tr, i);
	}
	return (0);
}
