/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:20:40 by bena              #+#    #+#             */
/*   Updated: 2023/06/25 17:21:01 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "s_stat.h"
# include "s_args.h"
# include "get_arguments.h"
# include "private_errors.h"

void		set_arguments(t_args *args, int *array);
int			init_data(t_stat *stat, t_args *args);
int			get_elapsed_time(int init);
int			run_simulation(t_stat *stat, int *philo_errno);
static int	wrong_arg_numbers(void);
static int	do_any_wrong_values_exist(int *array);
#endif
