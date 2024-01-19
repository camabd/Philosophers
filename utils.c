/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:05:34 by cabdli            #+#    #+#             */
/*   Updated: 2024/01/19 13:21:10 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	ft_atoi(const char *str)
{
	int			i;
	int			m;
	long int	nb;

	i = 0;
	m = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			m *= (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i] - 48;
		i++;
	}
	return (m * nb);
}

void	free_all(t_data *data, pthread_mutex_t forks, t_philo *philo)
{
	if (pthread_mutex_destroy(data->check_status) != 0)
		return (printf("Error: check_status mutex destroy issue\n"), 0);
	if (pthread_mutex_destroy(data->write) != 0)
		return (printf("Error: write mutex destroy issue\n"), 0);
	
}
