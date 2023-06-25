/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_right_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:58:09 by bena              #+#    #+#             */
/*   Updated: 2023/06/25 19:21:24 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "s_stat.h"

int		get_elapsed_time(int init);
int		get_simulation_status(t_stat *stat);
void	set_simulation_status(t_stat *stat, int value);

void	take_right_fork(t_philo *info)
{
	const int	time = get_elapsed_time(0);

	if (get_simulation_status(info->stat))
		return ;
	pthread_mutex_lock(&info->right->mutex);
	if (info->right->owner == 0)
		info->right->owner = info->index;
	else
	{
		pthread_mutex_unlock(&info->right->mutex);
		return ;
	}
	pthread_mutex_unlock(&info->right->mutex);
	printf("\033[1m%d \033[35m%d \033[33mhas taken a fork\033[0m\n",
		time, info->index);
	info->status = M_PHILO_STAT_1FORK;
}