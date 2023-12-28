/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:24:55 by cabdli            #+#    #+#             */
/*   Updated: 2023/12/28 16:25:59 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	only_numbers(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] < '0' || str[i][j] > '9')
				return (printf("Error, please enter only numeric chars"), 0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	at_least_1_philo(char **str, t_philo *data)
{
	int	philo;

	philo = ft_atoi(str[0]);
	if (philo == 0)
		return (printf("Error, there should be at leat 1 philo !"), 0);
	else
		data->nb_philos = philo;
	return (1);
}

int	check_args(char **str, t_philo *data)
{
	if (!only_numbers(str))
		return (0);
	if (!at_least_1_philo(str, data))
		return (0);
	if (!in_limits(str, ))
	return (1);
}

