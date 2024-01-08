/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:48:54 by cabdli            #+#    #+#             */
/*   Updated: 2024/01/08 13:26:56 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

typedef struct s_data
{
	int	nb_philos;
}t_data;

typedef struct s_philo
{
	int	n;
}t_philo;

/* Check_args.c */
int			check_args(char **str, t_data *data);

/* Utils.c */
long int	ft_atoi(const char *str);

#endif