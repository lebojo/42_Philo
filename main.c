/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 03:30:10 by jchapell          #+#    #+#             */
/*   Updated: 2023/09/21 02:05:40 by lebojo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

void	create_philo(t_data *d, int i)
{
	d->p[i].id = i;
	d->p[i].nb_philo = d->nb_philo;
	d->p[i].t = &d->time;
	d->p[i].fork = &d->forks[i];
	d->p[i].next_fork = &d->forks[(i + 1) % d->nb_philo];
	d->p[i].state = Thinking;
	d->p[i].l = &d->lock;
	d->p[i].last_eat = get_now();
	d->p[i].birth = d->p[i].last_eat;
	d->p[i].nb_eat = 0;
	d->p[i].nb_meals = &d->nb_meals;
	pthread_create(&d->p[i].tr, NULL, &routine, &d->p[i]);
	pthread_create(&d->p[i].life, NULL, &life, &d->p[i]);
	if (i % 2)
		usleep(1000000 / 200);
}

void	init_data(t_data *data)
{
	int	i;

	data->p = malloc(sizeof(t_philo) * data->nb_philo);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	data->nb_meals = 0;
	pthread_mutex_init(&data->lock, NULL);
	pthread_mutex_unlock(&data->lock);
	i = -1;
	while (++i < data->nb_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		create_philo(data, i);
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	if (parse(&data, ac, av))
		exit(error("Invalid arguments"));
	init_data(&data);
	while (1)
	{
		if (data.nb_meals == data.nb_philo)
		{
			pthread_mutex_lock(&data.lock);
			printf("\e[0;32m[PHILO] \033[0m%lums All philos ate enough\n",
				get_now());
			clean_exit(&data);
		}
		if (data.nb_meals == -42)
			clean_exit(&data);
	}
	return (0);
}
