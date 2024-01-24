/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:07:15 by cabdli            #+#    #+#             */
/*   Updated: 2024/01/24 17:59:06 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_mutex_forks(pthread_mutex_t **forks, t_data *data)
{
	(*forks) = malloc(data->nb_philos * sizeof(pthread_mutex_t));
	if (!(*forks))
		return (0);
	while (++data->i < data->nb_philos)
	{
		if (pthread_mutex_init((&((*forks)[data->i])), NULL) != 0)
			return (printf("Error, fork[%d] mutex_init issue !\n", data->i), 0);
	}
	return (1);
}

/*Pourquoi mettre struct avant timeval alors qu'on ne fait
pas comme ça habituellement pour déclarer des structures que
 l'on crée nous meme ?
 */
long long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		return (printf("gettimeofday function error !\n", 0));
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

static void	set_forks(t_philo **philo, pthread_mutex_t **forks, int i, int nb_philos)
{
	if (nb_philos == 1)
	{
		(*philo)[i].l_fork = (*fork);
		(*philo)[i].r_fork = NULL;
	}
	else if (i == 0)
	{
		(*philo)[i].l_fork = (*fork);
		(*philo)[i].r_fork = (*fork) + (nb_philos - 1);
	}
	else
	{
		(*philo)[i].l_fork = (*fork) + i;
		(*philo)[i].r_fork = (*fork) + (i - 1);
	}
}

/* Variable sync et  variables init_check nécessaires ?*/
static int	init_data_philo(t_philo **philo, pthread_mutex_t **forks, t_data *data)
{
	int			i;
	long long	time;

	i = -1;
	(*philo) = malloc(data->nb_philos * sizeof(t_philo));
	if (!(*philo))
		return (0);
	time = get_time();
	if (!time)
		return (0);
	while (++i < data->nb_philos)
	{
		set_forks(philo, forks, i, data->nb_philos);
		(*philo)[i].thread_id = 0;
		(*philo)[i].nb_philos = data->nb_philos;
		(*philo)[i].pos = i + 1;
		(*philo)[i].meals_eaten = 0;
		(*philo)[i].last_meal = 0;
		(*philo)[i].time = time;
		(*philo)[i].data = data;
	}
	return (1);
}


int	init_var(char **str, pthread_mutex_t **forks, t_philo **philo, t_data *data)
{
	if (!init_mutex_forks(forks, data))
		return (printf("Error in init_mutex_forks function\n"), 0);
	if (!init_data_philo(philo, forks, data))
		return (printf("Error in init_data_philo function\n"), 0);
	return (1);
}
