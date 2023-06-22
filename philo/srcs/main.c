/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:31:44 by bena              #+#    #+#             */
/*   Updated: 2023/06/22 14:31:45 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char **av)
{
	t_args	args;
	int		ga_errno;
	int		temp_args[5];

	if (ac != 5 && ac != 6)
		return (wrong_arg_numbers());
	temp_args[4] = -1;
	ga_errno = get_arguments(temp_args, 5, ac, av);
	if (ga_errno < 0)
		return (argument_error(ga_errno));
	set_arguments(&args, array);
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
	return (1);
}

static int	argument_error(int ga_errno)
{
	const char	* const str = ga_strerr(ga_errno);
	const char	*ptr;

	if (str == NULL)
		return (1);
	ptr = str;
	while (*ptr)
		ptr++;
	write(2, "Error: ", 7);
	write(2, str, ptr - str);
	write(2, "\n", 1);
	return (1);
}

static void	set_arguments(t_args *args, int *array)
{
	s_args->number_of_philosophers = array[0];
	s_args->time_to_die = array[1];
	s_args->time_to_eat = array[2];
	s_args->time_to_sleep = array[3];
	s_args->number_of_times_each_philosoper_must_eat = array[4];
}
