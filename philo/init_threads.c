/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:15:52 by cabdli            #+#    #+#             */
/*   Updated: 2024/02/05 13:04:40 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_threads(t_philo *philo, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
	{
		if (pthread_create(&(philo[i].thread_id), NULL, routine, \
		(void *)(&philo[i])) != 0)
		{
			write(2, "Error : pthread_create function failure\n", 41);
			while (--i >= 0)
			{
				if (pthread_join(philo[i].thread_id, NULL) != 0)
					return (write(2, "Error : pthread_join failure\n", 30), 0);
			}
			return (0);
		}
	}
	return (1);
}

static int	join_threads(t_philo *philo, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
	{
		if (pthread_join((philo[i].thread_id), NULL) != 0)
			return (write(2, "Error : pthread_join function failure\n", 39), 0);
	}
	return (1);
}

int	init_join_threads(t_philo *philo, t_data *data)
{
	if (!init_threads(philo, data))
		return (0);
	if (!join_threads(philo, data))
		return (0);
	return (1);
}
