/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 23:10:03 by jeounpar          #+#    #+#             */
/*   Updated: 2022/07/01 23:30:47 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define TRUE		1
# define FALSE		0
# define EATING		1
# define SLEEPING	2

# include <pthread.h>

typedef unsigned long long	t_ull;

struct						s_info;

typedef struct s_philo {
	int				p_id;
	int				left_fork;
	int				right_fork;
	int				eat_cnt;
	pthread_t		philo_thread;
	struct s_info	*info;
	t_ull			time;
}	t_philo;

typedef struct s_info {
	int				num_philo;
	int				num_must_eat;
	int				eat_check;
	int				die_check;
	t_ull			time_to_die;
	t_ull			time_to_eat;
	t_ull			time_to_sleep;
	t_ull			start_time;
	pthread_mutex_t	buffer_mutex;
	pthread_mutex_t	*forks_mutex;
	t_philo			*philos;
}	t_info;

int		check_arguments(int argc, char **argv);
int		init_info(int argc, char **argv, t_info *info);
int		ft_philo_start(t_info *info, t_philo *philo);
int		ft_print_error(char *str);
void	p_printf(t_info *info, int p_id, char *str);
void	ft_death_check(t_info *info, t_philo *philo);
void	ft_usleep(t_info *info, int type);
t_ull	ft_atoull(char *str);
t_ull	get_time(void);

#endif
