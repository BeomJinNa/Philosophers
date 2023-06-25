/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wake_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:58:09 by bena              #+#    #+#             */
/*   Updated: 2023/06/25 20:52:29 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "s_stat.h"

int		get_elapsed_time(int init);
int		get_simulation_status(t_stat *stat);

void	wake_up(t_philo *info)
{
	const int	time = get_elapsed_time(0);

	pthread_mutex_lock(&info->stat->mutex_print);
	if (get_simulation_status(info->stat))
	{
		pthread_mutex_unlock(&info->stat->mutex_print);
		return ;
	}
	printf("\033[1m%d \033[35m%d \033[37mis thinking\033[0m\n",
		time - 100, info->index);
	pthread_mutex_unlock(&info->stat->mutex_print);
	info->status = M_PHILO_STAT_THINKING;
}
