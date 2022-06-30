/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 23:09:42 by jeounpar          #+#    #+#             */
/*   Updated: 2022/06/26 18:05:12 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"
#include <stdio.h>

int	print_how_to_use()
{
	printf("./philo number_of_philosophers time_to_die time_to ");
	printf("eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	return (1);
}

int	ft_print_error(char *str)
{
	printf("%s\n", str);
	return FALSE;
}

void	print_arg_num_error()
{
	printf("Program argc need 5 or 6 arguments\n");
}

void	print_arg_minus_error()
{
	printf("arguments must be positive number\n");
}

int	check_minus(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '-')
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	check_arguments(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		ft_print_error("Program argc need 5 or 6 arguments");
		return (FALSE);
	}
	if (check_minus(argc, argv) == FALSE)
	{
		ft_print_error("Arguments must be positive number");
		return (FALSE);
	}
	return (TRUE);
}