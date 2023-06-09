/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:58:09 by bena              #+#    #+#             */
/*   Updated: 2023/06/25 21:47:05 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "s_stat.h"

int		get_elapsed_time(int init);
int		get_simulation_status(t_stat *stat);
void	set_simulation_status(t_stat *stat, int value);

int	die(t_philo *info)
{
	int	time;

	pthread_mutex_lock(&info->stat->mutex_print);
	if (get_simulation_status(info->stat))
	{
		pthread_mutex_unlock(&info->stat->mutex_print);
		return (1);
	}
	set_simulation_status(info->stat, 1);
	time = get_elapsed_time(0);
	printf("\033[1m%d \033[35m%d \033[31mdied\033[0m\n", time - 100, info->index);
	pthread_mutex_unlock(&info->stat->mutex_print);
	return (1);
}
