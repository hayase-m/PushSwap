/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 02:32:45 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/05/11 13:08:35 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_pointer(va_list *ap)
{
	uintptr_t	mem;
	int			len;
	ssize_t		write_ret;

	mem = (uintptr_t)va_arg(*ap, void *);
	if (mem == 0)
	{
		write_ret = write(1, "(nil)", 5);
		if (write_ret == -1)
			return (-1);
		return (5);
	}
	write_ret = write(1, "0x", 2);
	if (write_ret == -1)
		return (-1);
	len = ft_puthex_ptr_fd(mem, 1);
	if (len == -1)
		return (-1);
	return (2 + len);
}

int	handle_hex_lower(va_list *ap)
{
	return (ft_puthex_uint_fd((uintptr_t)va_arg(*ap, unsigned int), 1, 0));
}

int	handle_hex_upper(va_list *ap)
{
	return (ft_puthex_uint_fd((uintptr_t)va_arg(*ap, unsigned int), 1, 1));
}
