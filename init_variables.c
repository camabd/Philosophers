/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:07:15 by cabdli            #+#    #+#             */
/*   Updated: 2024/01/17 12:28:07 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

/*pourquoi mettre struct avant timeval alors qu'on ne fait
pas comme ça habituellement pour déclarer des structures que
 l'on crée nous meme ?
 */
static long long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		return (printf("gettimeofday function error !\n", 0));
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

static int	init_data_philo(t_philo **philo, pthread_mutex_t **forks, t_data *data)
{
	int	i;

	i = -1;
	(*philo) = malloc(data->nb_philos * sizeof(t_philo));
	if (!(*philo))
		return (0);
	while (++i < data->nb_philos)
	{
		set_forks(philo, forks, i, data->nb_philos);
		(*philo)[i].thread_id = 0;
		(*philo)[i].status = alive;
		(*philo)[i].pos = i + 1;
		(*philo)[i].meals_eaten = 0;
		(*philo)[i].last_meal = 0;
		(*philo)[i].time = get_time(void);
		if ((*philo)[i].time == 0)
			return (0);
		
	}
	
}

static int	init_mutex_forks(pthread_mutex_t **forks, t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	(*forks) = malloc(data->nb_philos * sizeof(pthread_mutex_t));
	if (!(*forks))
		return (0);
	while (++i < data->nb_philos)
	{
		if (pthread_mutex_init((&((*forks)[i])), NULL) != 0)
		{
			while (++j < i)
			{
				if (pthread_mutex_destroy((&((*forks)[j]))) != 0)
					return (printf("Error, fork mutex destroy issue !\n"), 0);
			}
			return (printf("Error, fork[%d] mutex_init issue !\n", i), 0);
		}
	}
	return (1);
}

int	init_var(char **str, pthread_mutex_t **forks, t_philo **philo, t_data *data)
{
	if (!init_mutex_forks(forks, data))
		return (0);
	if (!init_data_philo(philo, forks, data))
}
