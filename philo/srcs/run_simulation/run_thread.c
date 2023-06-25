/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:42:16 by bena              #+#    #+#             */
/*   Updated: 2023/06/25 21:40:44 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_thread.h"

void	*run_thread(void *arg)
{
	t_philo *const	info = (t_philo *)arg;

	while (get_elapsed_time(0) < info->time_to_start)
		usleep(250);
	while (1)
	{
		if (thread_actions(info))
			break ;
		usleep(1000);
	}
	say_terminated(info->stat);
	return (NULL);
}

static int	thread_actions(t_philo *info)
{
	const int	time = get_elapsed_time(0);

	if (get_simulation_status(info->stat))
		return (1);
	if (time - info->last_meal_time >= info->time_to_die)
		return (die(info));
	if (info->is_this_already_over == 0
		&& info->goal >= 0 && info->count_of_eating >= info->goal)
		say_finished(info);
	if (info->status == M_PHILO_STAT_THINKING)
		take_right_fork(info);
	if (info->status == M_PHILO_STAT_1FORK)
		take_left_fork(info);
	if (info->status == M_PHILO_STAT_EATING
		&& time - info->last_meal_time >= info->time_to_eat)
		fall_a_sleep(info);
	if (info->status == M_PHILO_STAT_SLEEPING
		&& time - info->last_sleep_time >= info->time_to_sleep)
		wake_up(info);
	return (0);
}
