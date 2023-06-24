/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_simulation_status.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 22:01:05 by bena              #+#    #+#             */
/*   Updated: 2023/06/24 22:03:20 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stat.h"

int	get_simulation_status(t_stat *stat)
{
	int	output;

	pthread_mutex_lock(&stat->mutex_status);
	output = stat->status;
	pthread_mutex_unlock(&stat->mutex_status);
	return (output);
}
