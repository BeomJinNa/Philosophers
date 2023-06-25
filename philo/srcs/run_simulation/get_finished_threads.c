/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_finished_threads.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:58:04 by bena              #+#    #+#             */
/*   Updated: 2023/06/25 18:08:36 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stat.h"

int	get_finished_threads(t_stat *stat)
{
	int	output;

	pthread_mutex_lock(&stat->mutex_finished);
	output = stat->finished_num;
	pthread_mutex_unlock(&stat->mutex_finished);
	return (output);
}
