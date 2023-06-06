/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan <jordan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 03:29:07 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/06 12:02:06 by jordan           ###   ########.fr       */
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

/*UTILS				*/
void				parse(t_data *d, int ac, char **av);
unsigned long int	get_now();

/*CONSOLE			*/
void				p_state(unsigned long int time, t_philo *p);
int					info(char *str);
int					error(char *str);

/*MINI_LIBFT		*/
char				*zz_itoa(int n);
int					zz_atoi(char *str);
int					zz_strlen(char *str);
char				*ft_strdup(char *s1);
void				*ft_calloc(size_t count, size_t size);

#endif