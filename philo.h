/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:48:54 by cabdli            #+#    #+#             */
/*   Updated: 2024/01/28 13:50:26 by cabdli           ###   ########.fr       */
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
	t_bool			status;
	pthread_mutex_t	*write;
	int				i;
}t_data;

typedef struct s_philo
{
	pthread_t		thread_id;
	int				nb_philos;
	long long		t_die;
	long long		t_eat;
	long long		t_sleep;
	int				nb_meals;
	int				pos;
	int				meals_eaten;
	long long		last_meal;
	long long		time;
	t_data			*data;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}t_philo;

/* Check_args.c */
int			check_args(char **str, t_data *data);

/* Utils.c */
long int	ft_atoi(const char *str);
void		free_destroy_all(t_data *data, pthread_mutex_t *forks, t_philo *philo);
long long	get_time(void);

/* Collect_data.c */
int			collect_data(char **str, t_data *data);

/* Init_variables.c */
int			init_var(char **str, pthread_mutex_t **forks, t_philo **philo, t_data *data);

/* Init_threads.c */
int			init_join_threads(t_philo *philo, t_data *data);

/* Routine.c */
void		*routine(void *arg);

/* Routine_utils.c */
int			philo_dead(t_philo *philo);
int			print_message(t_philo *philo, char *str);

/* Take_forks.c */
int			take_forks(t_philo *philo);
int			eat(t_philo *philo);

#endif