/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:48:54 by cabdli            #+#    #+#             */
/*   Updated: 2024/01/11 13:15:08 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

typedef enum s_bool { alive, dead }	t_bool;

typedef struct s_data
{
	int				nb_philos;
	long long		t_die;
	long long		t_eat;
	long long		t_sleep;
	int				nb_meals;
	pthread_mutex_t	*check_status;
	pthread_mutex_t	*write;
}t_data;

typedef struct s_philo
{
	pthread_t		thread_id;
	t_bool			status;
	int				pos;
	int				meals_eaten;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	long long		last_meal;
	long long		time;
}t_philo;

/* Check_args.c */
int			check_args(char **str, t_data *data);

/* Utils.c */
long int	ft_atoi(const char *str);

/* Collect_data.c */
int			collect_data(char **str, t_data *data);

/* Init_variables.c */
int			init_var(char **str, pthread_mutex_t **forks, t_philo **philo, t_data *data);

#endif