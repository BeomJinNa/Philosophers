/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_simulation_status.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 22:01:05 by bena              #+#    #+#             */
/*   Updated: 2023/06/24 22:04:24 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stat.h"

void	set_simulation_status(t_stat *stat, int value)
{
	pthread_mutex_lock(&stat->mutex_status);
	stat->status = value;
	pthread_mutex_unlock(&stat->mutex_status);
}
