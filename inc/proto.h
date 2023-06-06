/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan <jordan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:14:25 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/06 01:08:14 by jordan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include "struct.h"

/*MAIN				*/
void		*routine(void *philo);
void		*dying(void *philo);

/*CONSOLE			*/
int			error(char *str);
int			info(char *str);
void		philo_state(long int time, int philo, char type);

/*UTILS				*/
char		*add_str(char *s1, char *s2, int f);
int			zz_strlen(char *s);
long int	get_now(void);
long int	get_now_rel(t_philo *p);
void		clean_exit(t_data *d);

/*MINI_LIBFT		*/
char		*zz_itoa(int n);
int			zz_atoi(char *str);
char		*ft_strdup(char *s1);
void		*ft_calloc(size_t count, size_t size);

/*INIT				*/
void		init_data(t_data *d, t_time *t, int argc, char **args);

/*STATE				*/
void		eat(t_philo *p);
void		create_philo(t_data *data, int i);

#endif