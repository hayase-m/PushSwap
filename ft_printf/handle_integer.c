/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 02:33:07 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/05/11 13:04:57 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_decimal(va_list *ap)
{
	char	*num_str;
	int		num_len;

	num_str = ft_itoa(va_arg(*ap, int));
	if (!num_str)
		return (-1);
	num_len = ft_strlen(num_str);
	if (ft_putstr_write_check_fd(num_str, 1) == -1)
		return (-1);
	free(num_str);
	return (num_len);
}

int	handle_unsigned(va_list *ap)
{
	return (ft_putunbr_write_check_fd(va_arg(*ap, unsigned int), 1));
}
