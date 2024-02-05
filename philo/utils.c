/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:05:34 by cabdli            #+#    #+#             */
/*   Updated: 2024/02/05 12:59:00 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_atoi(const char *str)
{
	int			i;
	int			m;
	long long	nb;

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

void	*free_destroy_all(t_data *data, pthread_mutex_t *forks, t_philo *philo)
{
	int	j;

	j = -1;
	if (pthread_mutex_destroy(data->check_status) != 0)
		return (printf("Error: check_status mutex destroy issue\n"), NULL);
	if (pthread_mutex_destroy(data->write) != 0)
		return (printf("Error: write mutex destroy issue\n"), NULL);
	if (forks)
	{
		while (++j < data->i)
		{
			if (pthread_mutex_destroy(&(forks[j])) != 0)
				return (printf("Error, fork mutex destroy issue !\n"), NULL);
		}
		free(forks);
	}
	if (philo)
		free(philo);
	return (NULL);
}

/*Pourquoi mettre struct avant timeval alors qu'on ne fait
pas comme ça habituellement pour déclarer des structures que
 l'on crée nous meme ?
 */
long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000000) + (time.tv_usec));
}
