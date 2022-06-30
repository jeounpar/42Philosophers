/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:34:48 by jeounpar          #+#    #+#             */
/*   Updated: 2022/06/30 13:36:19 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>
#include <unistd.h>

t_ull	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * (t_ull) 1000 + t.tv_usec / 1000);
}

void	ft_usleep(t_info *info, int type)
{
	t_ull	target_time;
	t_ull	tmp_time;
	t_ull	current_time;

	if (type == EATING)
		target_time = (t_ull)(info->time_to_eat);
	else if (type == SLEEPING)
		target_time = (t_ull)(info->time_to_sleep);
	tmp_time = get_time();
	while (!(info->die_check))
	{
		current_time = get_time();
		if ((current_time - tmp_time) >= target_time)
			break ;
		usleep(100);
	}
}