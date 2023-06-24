/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fall_a_sleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:58:09 by bena              #+#    #+#             */
/*   Updated: 2023/06/24 22:44:15 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "s_stat.h"

int		get_elapsed_time(int init);
int		get_simulation_status(t_stat *stat);

void	fall_a_sleep(t_philo *info)
{
	const int	time = get_elapsed_time(0);

	if (get_simulation_status(info->stat))
		return ;
	pthread_mutex_lock(&info->left->mutex);
	info->left->index = 0;
	pthread_mutex_unlock(&info->left->mutex);
	pthread_mutex_lock(&info->right->mutex);
	info->right->index = 0;
	pthread_mutex_unlock(&info->right->mutex);
	printf("%d %d is sleeping\n", time, info->index);
	info->status = M_PHILO_STAT_SLEEPING;
}
