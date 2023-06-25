/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   say_finished.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:04:32 by bena              #+#    #+#             */
/*   Updated: 2023/06/25 18:21:48 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stat.h"

void	say_finished(t_philo *info)
{
	t_stat *const	stat = info->stat;

	info->is_this_already_over = 1;
	pthread_mutex_lock(&stat->mutex_finished);
	stat->finished_num++;
	pthread_mutex_unlock(&stat->mutex_finished);
}
