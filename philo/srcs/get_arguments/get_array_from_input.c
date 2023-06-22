/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_array_from_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:41:31 by bena              #+#    #+#             */
/*   Updated: 2023/06/22 17:01:55 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ga_is_this_space(int c);
static int	ft_atoi_extended(const char *str, int *overflow_checker);

int	ga_get_array_from_input(int *array, int number_of_args, char *ptr)
{
	int		i;
	int		overflow_occured;

	overflow_occured = 0;
	i = -1;
	while (++i < number_of_args)
	{
		while (ga_is_this_space(*ptr))
			ptr++;
		array[i] = ft_atoi_extended(ptr, &overflow_occured);
		if (overflow_occured)
			return (-1);
		while (*ptr && ga_is_this_space(*ptr) == 0)
			ptr++;
	}
	return (0);
}

static int	ft_atoi_extended(const char *str, int *overflow_checker)
{
	int			sign;
	long long	output;

	while (ga_is_this_space(*str))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	output = 0;
	while ('0' <= *str && *str <= '9')
	{
		output = output * 10 + *str - '0';
		str++;
	}
	output = sign * output;
	if (output < -2147483648 || 2147483647 < output)
		*overflow_checker = 1;
	return (output);
}
