/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:07:15 by cabdli            #+#    #+#             */
/*   Updated: 2024/01/11 13:50:23 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	if (!init_mutex_forks(forks, data))
}
