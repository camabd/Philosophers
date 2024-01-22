/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:57:33 by cabdli            #+#    #+#             */
/*   Updated: 2024/01/22 11:45:50 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	init_mutex_data(t_data *data)
{
	if (pthread_mutex_init(data->check_status, NULL) != 0)
		return (printf("Error, check_status mutex initialisation issue !\n"), 0);
	if (pthread_mutex_init(data->write, NULL) != 0)
	{
		if (pthread_mutex_destroy(data->check_status) != 0)
			return (printf("Error, check_status mutex destroy issue !\n"), 0);
		return (printf("Error, write mutex initialisation issue !\n"), 0);
	}
	return (1);
}

//multiplier t_die/eat/sleep * 1000 ? Pk ?
int	collect_data(char **str, t_data *data)
{
	data->t_die = ft_atoi(str[2]);
	data->t_eat = ft_atoi(str[3]);
	data->t_sleep = ft_atoi(str[4]);
	data->i = -1;
	if (str[5])
		data->nb_meals = ft_atoi(str[5]);
	else
		data->nb_meals = 0;
	if (!init_mutex_data(data))
		return (0);
	return (1);
}
