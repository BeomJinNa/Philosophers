/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_left_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:58:09 by bena              #+#    #+#             */
/*   Updated: 2023/06/25 18:19:45 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "s_stat.h"

int		get_elapsed_time(int init);
int		get_simulation_status(t_stat *stat);
void	set_simulation_status(t_stat *stat, int value);

void	take_left_fork(t_philo *info)
{
	const int	time = get_elapsed_time(0);

	if (get_simulation_status(info->stat))
		return ;
	pthread_mutex_lock(&info->left->mutex);
	if (info->left->owner == 0)
		info->left->index = info->index;
	else
	{
		pthread_mutex_unlock(&info->left->mutex);
		return ;
	}
	pthread_mutex_unlock(&info->left->mutex);
	printf("%d %d is eating\n", time, info->index);
	info->status = M_PHILO_STAT_EATING;
	info->count_of_eating++;
}
