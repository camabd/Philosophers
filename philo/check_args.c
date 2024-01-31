/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:24:55 by cabdli            #+#    #+#             */
/*   Updated: 2024/01/31 14:14:36 by cabdli           ###   ########.fr       */
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
				return (printf("Error, please enter only numeric chars !\n"), 0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	at_least_1_philo(char *str, t_data *data)
{
	int	philo;

	philo = ft_atoi(str);
	if (philo == 0)
		return (printf("Error, there should be at leat 1 philo !\n"), 0);
	else
		data->nb_philos = philo;
	return (1);
}

static int	in_limits(char **str)
{
	int			i;
	long int	val;

	i = -1;
	val = 0;
	while (str[++i])
	{
		val = ft_atoi(str[i]);
		if (val == 0 || val > INT_MAX)
			return (printf("Error, values should be != 0 && < INT_MAX !\n"), 0);
	}
	return (1);
}

int	check_args(char **str, t_data *data)
{
	if (!only_numbers(str))
		return (0);
	if (!at_least_1_philo(str[0], data))
		return (0);
	if (!in_limits(str))
		return (0);
	return (1);
}
