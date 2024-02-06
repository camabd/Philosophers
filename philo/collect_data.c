/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:57:33 by cabdli            #+#    #+#             */
/*   Updated: 2024/02/06 15:22:52 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex_philo(t_philo **philo, t_data *data)
{
	int						i;

	i = -1;
	while (++i < data->nb_philos)
	{
		(*philo)[i].check_status = data->check_status;
		(*philo)[i].write = data->write;
	}
	return (1);
}

static int	init_mutex_data(t_data *data)
{
	static pthread_mutex_t	check_status;
	static pthread_mutex_t	write;

	if (pthread_mutex_init(&check_status, NULL) != 0)
		return (printf("Error, check_status mutex initialisation issue !\n"), 0);
	if (pthread_mutex_init(&write, NULL) != 0)
	{
		if (pthread_mutex_destroy(&check_status) != 0)
			return (printf("Error, check_status mutex destroy issue !\n"), 0);
		return (printf("Error, write mutex initialisation issue !\n"), 0);
	}
	data->check_status = &check_status;
	data->write = &write;
	return (1);
}

int	collect_data(char **str, t_data *data)
{
	data->t_die = ft_atoi(str[1]) * 1000;
	data->t_eat = ft_atoi(str[2]) * 1000;
	data->t_sleep = ft_atoi(str[3]) * 1000;
	data->i = -1;
	if (str[4])
		data->nb_meals = ft_atoi(str[4]);
	else
		data->nb_meals = 0;
	init_mutex_data(data);
	return (1);
}
