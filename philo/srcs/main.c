/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:31:44 by bena              #+#    #+#             */
/*   Updated: 2023/06/25 20:53:19 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char **av)
{
	t_stat	stat;
	t_args	args;
	int		philo_errno;
	int		temp_args[5];

	if (ac != 5 && ac != 6)
		return (wrong_arg_numbers());
	temp_args[4] = -1;
	philo_errno = get_arguments(temp_args, 5, ac, av);
	if (philo_errno < 0)
		return (ga_parsing_error(philo_errno));
	if (philo_errno != 4 && philo_errno != 5)
		return (wrong_arg_numbers());
	if (do_any_wrong_values_exist(temp_args))
		return (0);
	set_arguments(&args, temp_args);
	if (init_data(&stat, &args) || get_elapsed_time(1) < 0)
		return (print_error(M_ERROR_DATA_INIT, &stat));
	if (run_simulation(&stat, &philo_errno))
		return (print_error(philo_errno, &stat));
	free(stat.philo);
	free(stat.fork);
	return (0);
}

static int	wrong_arg_numbers(void)
{
	printf("%s %s %s %s %s %s\n",
		"Usage: ./philo",
		"<number_of_philosophers>",
		"<time_to_die>",
		"<time_to_eat>",
		"<time_to_sleep>",
		"[<number_of_times_each_philosoper_must_eat>]");
	return (0);
}

static int	do_any_wrong_values_exist(int *array)
{
	if (array[0] <= 0)
		printf("philo: <the number of philosophers> must be more than 0.\n");
	else if (array[1] < 0)
		printf("philo: <time to die> can't be negative.\n");
	else if (array[2] < 0)
		printf("philo: <time to eat> can't be negative.\n");
	else if (array[3] < 0)
		printf("philo: <time to sleep> can't be negative.\n");
	else
		return (0);
	return (1);
}
