/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:47:34 by cabdli            #+#    #+#             */
/*   Updated: 2024/01/31 14:12:44 by cabdli           ###   ########.fr       */
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
- si fonction join ne fonctionne pas, pk continuer quand meme le pgme ?
==> si elle ne fonctionne pas j'arrete le pgme
- Tester avec differents temps de creation d'un philo, dans handle departure
- take_forks.c : Pourquoi les forks prises en 1eres et lachees en premieres
varient en fonction de a position du philo (philo pair ou impair) ?
Permet d'être sur que lorsque le philo prend une fourchette les 2 sont
disponibles ? mais pourquoi puisque le temps d'attente semble
similaire dans les 2 cas ?
- routine.c fonction routine : wait_after_thinking(philo->sync); nécessaire ?
*/