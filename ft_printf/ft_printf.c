/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 01:53:52 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/05/11 12:29:28 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_str_specifier(const char *str, size_t *i_ptr, va_list *ap)
{
	int	handler_result;

	(*i_ptr)++;
	if (str[*i_ptr] == 'c')
		handler_result = handle_char(ap);
	else if (str[*i_ptr] == 's')
		handler_result = handle_string(ap);
	else if (str[*i_ptr] == 'p')
		handler_result = handle_pointer(ap);
	else if (str[*i_ptr] == 'd' || str[*i_ptr] == 'i')
		handler_result = handle_decimal(ap);
	else if (str[*i_ptr] == 'u')
		handler_result = handle_unsigned(ap);
	else if (str[*i_ptr] == 'x')
		handler_result = handle_hex_lower(ap);
	else if (str[*i_ptr] == 'X')
		handler_result = handle_hex_upper(ap);
	else if (str[*i_ptr] == '%')
		handler_result = handle_percent(ap);
	else
		return (-1);
	if (handler_result == -1)
		return (-1);
	(*i_ptr)++;
	return (handler_result);
}

static int	process_char(char c, int fd)
{
	if (write(fd, &c, 1) < 0)
		return (-1);
	return (1);
}

static int	ft_printf_loop(const char *str, va_list *ap)
{
	size_t	i;
	int		total_count;
	int		result;

	total_count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			result = process_str_specifier(str, &i, ap);
		else
		{
			result = process_char(str[i], 1);
			i++;
		}
		if (result == -1)
			return (-1);
		total_count += result;
	}
	return (total_count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		total_count;

	if (!str)
		return (-1);
	va_start(ap, str);
	total_count = ft_printf_loop(str, &ap);
	va_end(ap);
	return (total_count);
}

// int	main(void)
// {
// 	ft_printf("test%c%c", 'd', 'a');
// 	return (0);
// }
