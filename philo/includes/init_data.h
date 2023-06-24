/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:07:52 by bena              #+#    #+#             */
/*   Updated: 2023/06/24 19:06:41 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_DATA_H
# define INIT_DATA_H

# include <stdlib.h>
# include <string.h>
# include "s_stat.h"
# include "s_args.h"

static void	set_data(int index, t_stat *stat, t_args *args);
static int	alloc_philo(t_stat *stat);
static int	alloc_fork(t_stat *stat);
#endif
