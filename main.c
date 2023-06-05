/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan <jordan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:16:15 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/05 01:32:59 by jordan           ###   ########.fr       */
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
	t_philo			p;

	p = *(t_philo *)philo;
	while (p.state != 'D')
	{
		if (p.state == 'T')
			eat(&p);
		if (p.state == 'S')
		{
			philo_state(get_now_rel(philo), p.id, p.state, p.od);
			usleep(p.time->sleep * 1000);
			if (p.state != 'D')
				p.state = 'T';
		}
		philo_state(get_now_rel(philo), p.id, p.state, p.od);
	}
	return (0);
}

void	*dying(void *philo)
{
	t_philo	p;

	p = *(t_philo *)philo;
	while (1)
	{
		if (get_now_rel(&p) - p.last_eat >= p.time->die
			&& p.state != 'E')
		{
			pthread_mutex_lock(p.die);
			philo_state(get_now_rel(&p), p.id, 'D', p.od);
			p.od = 1;
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
	i = -1;
	while (++i < data.nb_philo)
		pthread_mutex_init(&data.philo[i].fork, NULL);
	i = -1;
	while (++i < data.nb_philo - 1)
		create_philo(&data, &data.philo[i], &data.philo[i + 1], i);
	create_philo(&data, &data.philo[i], &data.philo[0], i);
	i = 0;
	while (1)
		;
	return (0);
}
