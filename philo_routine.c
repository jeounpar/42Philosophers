/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 23:09:55 by jeounpar          #+#    #+#             */
/*   Updated: 2022/06/26 18:23:24 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static void	philo_eat(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&(info->eating_mutex));
	p_printf(info, philo->p_id, "is eating");
	philo->time = get_time();
	pthread_mutex_unlock(&(info->eating_mutex));
	(philo->eat_cnt)++;
	ft_usleep(info, EATING);
}

static int	philo_routine(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&(info->forks_mutex[philo->left_fork]));
	p_printf(info, philo->p_id, "has taken a fork");
	pthread_mutex_lock(&(info->forks_mutex[philo->right_fork]));
	p_printf(info, philo->p_id, "has taken a fork");
	philo_eat(philo->info, philo);
	pthread_mutex_unlock(&(info->forks_mutex[philo->left_fork]));
	pthread_mutex_unlock(&(info->forks_mutex[philo->right_fork]));
	if (info->eat_check)
		return (1);
	return (0);
}

static void	*ft_philo_func(void *data)
{
	t_info	*info;
	t_philo	*philo;

	philo = (t_philo *)data;
	info = philo->info;
	if (philo->p_id % 2)
		usleep(10000);
	while (!(info->die_check))
	{
		if (philo_routine(info, philo))
			break ;
		p_printf(info, philo->p_id, "is sleeping");
		ft_usleep(info, SLEEPING);
		p_printf(info, philo->p_id, "is thinking");
	}
	return (0);
}

void	ft_end_philo(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
		pthread_join(philo[i++].philo_thread, NULL);
	i = 0;
	while (i < info->num_philo)
		pthread_mutex_destroy(&(info->forks_mutex[i++]));
	free(info->philos);
	free(info->forks_mutex);
	pthread_mutex_destroy(&(info->eating_mutex));
	pthread_mutex_destroy(&(info->buffer_mutex));
}

int	ft_philo_start(t_info *info, t_philo *philo)
{
	int		i;
	t_ull	current_time;
	void	*philo_data;

	i = 0;
	info->start_time = get_time();
	while (i < info->num_philo)
	{	
		philo[i].time = get_time();
		philo_data = (void *)&(philo[i]);
		if (pthread_create(&(philo[i].philo_thread), NULL, ft_philo_func, philo_data))
			return (FALSE);
		i++;
	}
	ft_death_check(info, info->philos);
	ft_end_philo(info, info->philos);
	return (0);
}