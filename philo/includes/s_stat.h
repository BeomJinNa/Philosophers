/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:29:48 by bena              #+#    #+#             */
/*   Updated: 2023/06/22 22:30:29 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_STAT_H
# define S_STAT_H

# include "s_philo.h"
# include "s_fork.h"

typedef struct s_stat
{
	int		total_num;
	t_philo	*philo;
	t_fork	*fork;
}			t_stat;
#endif
