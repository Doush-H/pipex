/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:52:38 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/04/27 13:28:08 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdint.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

//--------------print_ptr_hex-------------------
int		ptr_to_hex(uintptr_t ptr, char c);
char	*ft_get_base_hex(char c);

//---------------print_hex----------------------
int		dec_to_hex(unsigned int nbr, char c);

//--------------print_uint----------------------
int		putnbr_uint(unsigned int n);

//---------------print_int----------------------
int		putnbr_int(int n);

//--------------core_functions------------------
int		check_args(va_list args, char c);

//----------------print_str---------------------
int		print_str(char *s);

//----------------ft_printf--------------------
int		ft_printf(const char *format_str, ...);

#endif