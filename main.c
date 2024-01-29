/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:47:34 by cabdli            #+#    #+#             */
/*   Updated: 2024/01/29 15:33:33 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	char			**str;
	t_data			data;
	t_philo			*philo;
	pthread_mutex_t	*forks;

	str = NULL;
	forks = NULL;
	philo = NULL;
	if (ac != 5 && ac != 6)
		return (printf("Error, wrong number of arguments !\n"), 0);
	str = &av[1];
	if (!check_args(str, &data))
		return (0);
	if (!collect_data(str, &data))
		return (0);
	if (!init_var(&forks, &philo, &data))
		return (free_destroy_all(&data, forks, philo), 0);
	if (!init_join_threads(philo, &data))
		return (free_destroy_all(&data, forks, philo), 0);
	free_destroy_all(&data, forks, philo);
	return (1);
}

/*Questions :
- take_forks.c fonction take forks
- routine_utils.c philo_dead : mettre le lock des mutex au tout début
et verifier d'abord si mon philo est mort..., si non, verifier si un
autre philo est mort et poursuivre ou arreter là ? choisir en fonction
de la fréquence de verification de la mort des autres philos
- si fonction join ne fonctionne pas, pk continuer quand meme le pgme ?
--> si elle ne fonctionne pas j'arrete le pgme
- Tester avec differents temps de creation d'un philo, dans handle departure
*/