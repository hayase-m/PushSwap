/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 01:46:28 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/05/11 12:46:32 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_puthex_ptr_fd(uintptr_t num, int fd);
int		ft_puthex_uint_fd(unsigned int num, int fd, int is_upper);
int		ft_putunbr_write_check_fd(unsigned int n, int fd);
int		ft_printf(const char *str, ...);
int		ft_putstr_write_check_fd(char *s, int fd);

char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);

int		handle_char(va_list *ap);
int		handle_string(va_list *ap);
int		handle_pointer(va_list *ap);
int		handle_decimal(va_list *ap);
int		handle_unsigned(va_list *ap);
int		handle_hex_lower(va_list *ap);
int		handle_hex_upper(va_list *ap);
int		handle_percent(va_list *ap);

#endif
