/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:15:52 by cabdli            #+#    #+#             */
/*   Updated: 2024/01/23 14:21:35 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

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

static int	joind_threads(t_philo *philo, t_data *data)
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

//peut-on join juste apres la creation d'un thread,
// avant de les avoirs tous crées ? donc le faire au fur et a mesure ?
// Quel est l'intyeret de init check et check init == verifier si pb dans initialisation et arreter si oui avant modif
int	init_join_threads(t_philo *philo, t_data *data)
{
	if (!init_threads(philo, data))
		return (0);
	if (!join_threads())
		return (0);
	return (1);
}
