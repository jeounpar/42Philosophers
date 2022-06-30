/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 23:09:49 by jeounpar          #+#    #+#             */
/*   Updated: 2022/06/30 14:27:03 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "philo.h"
#include <stdlib.h>
#include <stdio.h>

static int	init_philo(t_info *info)
{
	int	i;

	info->philos = (t_philo *)malloc(info->num_philo * sizeof(t_philo));
	if (info->philos == NULL)
		return (FALSE);
	i = 0;
	while (i < info->num_philo)
	{
		info->philos[i].p_id = i;
		info->philos[i].left_fork = i;
		info->philos[i].right_fork = (i + 1) % info->num_philo;
		info->philos[i].eat_cnt = 0;
		info->philos[i].time = 0;
		info->philos[i].info = info;
		i++;
	}
	return (TRUE);
}

static int	init_mutex(t_info *info)
{
	int	i;

	if (pthread_mutex_init(&(info->buffer_mutex), NULL))
		return (FALSE);
	if (pthread_mutex_init(&(info->eating_mutex), NULL))
		return (FALSE);
	info->forks_mutex = malloc(sizeof(pthread_mutex_t) * info->num_philo);
	if (info->forks_mutex == NULL)
		return (FALSE);
	i = 0;
	while (i < info->num_philo)
	{
		if (pthread_mutex_init(&(info->forks_mutex[i]), NULL))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	check_info(t_info *info)
{
	if (info->num_philo < 2
		|| info->time_to_die < 60 || info->time_to_eat < 60
		|| info->time_to_sleep < 60)
		return (FALSE);
	return (TRUE);
}

int	init_info(int argc, char **argv, t_info *info)
{
	info->num_philo = (int)ft_atoull(argv[1]);
	info->time_to_die = ft_atoull(argv[2]);
	info->time_to_eat = ft_atoull(argv[3]);
	info->time_to_sleep = ft_atoull(argv[4]);
	info->num_must_eat = -1;
	info->die_check = 0;
	info->eat_check = 0;
	info->start_time = 0;
	if (argc == 6)
	{
		info->num_must_eat = (int)ft_atoull(argv[5]);
		if (info->num_must_eat <= 0)
			return (FALSE);
	}
	if (init_mutex(info) == FALSE)
		return (FALSE);
	if (init_philo(info) == FALSE)
		return (FALSE);
	return (TRUE);
}
