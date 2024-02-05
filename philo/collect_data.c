/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:57:33 by cabdli            #+#    #+#             */
/*   Updated: 2024/02/05 01:18:06 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex_philo(t_philo **philo, t_data *data)
{
	int						i;
	static pthread_mutex_t	check_status;
	static pthread_mutex_t	write;

	i = -1;
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
	while (++i < data->nb_philos)
	{
		(*philo)[i].check_status = &check_status;
		(*philo)[i].write = &write;
	}
	return (1);
}

int	collect_data(char **str, t_data *data)
{
	data->t_die = ft_atoi(str[1]);
	data->t_eat = ft_atoi(str[2]);
	data->t_sleep = ft_atoi(str[3]);
	data->i = -1;
	if (str[4])
		data->nb_meals = ft_atoi(str[4]);
	else
		data->nb_meals = 0;
	return (1);
}
