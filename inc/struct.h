/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 03:19:22 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/02 04:38:54 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "proto.h"

typedef struct s_time
{
	int				eat;
	int				die;
	int				sleep;
	int				end;
	struct timeval	timer;
}	t_time;

typedef struct s_philo
{
	char			state;
	int				id;
	int				last_eat;
	int				*max;
	pthread_mutex_t	fork;
	pthread_mutex_t	*next_fork;
	pthread_t		tr;
	t_time			*time;
}	t_philo;

typedef struct s_data
{
	int				nb_philo;
	t_time			time;
	t_philo			*philo;
}	t_data;

#endif