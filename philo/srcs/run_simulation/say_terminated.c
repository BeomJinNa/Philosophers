/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   say_terminated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:04:32 by bena              #+#    #+#             */
/*   Updated: 2023/06/24 20:09:05 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "say_terminated.h"

void	say_terminated(t_stat *stat)
{
	pthread_mutex_lock(&stat->termination);
	stat->terminated_threads++;
	pthread_mutex_unlock(&stat->termination);
}
