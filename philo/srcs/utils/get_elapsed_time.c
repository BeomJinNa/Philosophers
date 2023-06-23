/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elapsed_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:31:10 by bena              #+#    #+#             */
/*   Updated: 2023/06/23 17:49:25 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_elapsed_time.h"

int	get_elapsed_time(int init)
{
	static struct timeval	zero_time;
	struct timeval			current_time;

	if (init)
		return (gettimeofday(&zero_time, NULL));
	if (gettimeofday(&current_time, NULL))
		return (-1);
	return (
		(current_time.tv_sec - zero_time.tv_sec) * 1000
		+ (current_time.tv_usec - zero_time.tv_usec) / 1000
	);
}
