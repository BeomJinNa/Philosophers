/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:10:42 by bena              #+#    #+#             */
/*   Updated: 2023/06/22 17:01:50 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ga_is_this_wrong_character(int c);
int			ga_is_this_space(int c);
int			ga_is_this_sign(int c);
int			ga_isdigit(int c);
static int	is_there_wrong_character(const char *ptr);
static int	is_there_bad_position_of_sign(const char *ptr);
static int	check_the_bad_sign(const char **ptr);

int	ga_does_input_error_exist(char *str)
{
	if (is_there_wrong_character(str))
		return (1);
	if (is_there_bad_position_of_sign(str))
		return (1);
	return (0);
}

static int	is_there_wrong_character(const char *ptr)
{
	while (*ptr)
		if (ga_is_this_wrong_character(*ptr++))
			return (1);
	return (0);
}

static int	is_there_bad_position_of_sign(const char *ptr)
{
	while (ga_is_this_space(*ptr))
		ptr++;
	while (*ptr)
	{
		if (check_the_bad_sign(&ptr))
			return (1);
		while (ga_is_this_space(*ptr))
			ptr++;
	}
	return (0);
}

static int	check_the_bad_sign(const char **ptr)
{
	int	sign_stack;

	sign_stack = 0;
	while (ga_is_this_sign(**ptr))
	{
		sign_stack++;
		*ptr += 1;
	}
	if (sign_stack > 1 || ga_isdigit(**ptr) == 0)
		return (1);
	while (**ptr && ga_is_this_space(**ptr) == 0)
	{
		if (ga_is_this_sign(**ptr))
			return (1);
		*ptr += 1;
	}
	return (0);
}

int	ga_does_any_overflow_occur(const char *ptr)
{
	int			count_digits;

	while (*ptr)
	{
		count_digits = 0;
		while (*ptr && (ga_is_this_sign(*ptr) || ga_is_this_space(*ptr)))
			ptr++;
		while (*ptr == '0')
			ptr++;
		while (ga_isdigit(*ptr))
		{
			count_digits++;
			ptr++;
			if (count_digits > 10)
				return (1);
		}
	}
	return (0);
}
