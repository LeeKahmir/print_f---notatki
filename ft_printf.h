/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                         :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: wmiszkie <wmiszkie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:56:32 by wmiszkie          #+#    #+#             */
/*   Updated: 2024/04/22 15:08:48 by wmiszkie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#ifndef FT_PRINTF_H: Ta linia sprawdza, czy makro FT_PRINTF_H nie jest
zdefiniowane. Jeśli nie jest zdefiniowane, to kod między #ifndef i #endif
zostanie włączony.*/
/*#define FT_PRINTF_H: Definiuje makro FT_PRINTF_H. To zapobiega wielokrotnemu
dołączaniu tego samego pliku nagłówkowego, co mogłoby spowodować błędy
kompilacji.*/
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*#include <stdarg.h>: Dołącza bibliotekę, która pozwala na obsługę zmiennej
liczby argumentów w funkcji (va_list, va_start, va_arg, va_end)*/
/*#include <unistd.h>: Dołącza funkcje systemowe POSIX, takie jak write, które
mogą być używane do bezpośredniego wypisywania na standardowe wyjście.*/
/*#include <stdlib.h>: Dołącza standardowe funkcje biblioteki C, takie jak
malloc, free, itp.*/
/*Biblioteka stddef.h w C dostarcza definicje typów size_t, ptrdiff_t i makra
NULL, które są kluczowe do operacji na wskaźnikach i rozmiarach.*/

// Standard C Libraries
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

// Protoypes
void	ft_putcharacter_length(char character, int *length);
void	ft_string(char *args, int *length);

void	ft_number(int number, int *length);
void	ft_hexadecimal(unsigned int x, int *length, char x_or_x);
void	ft_unsigned_int(unsigned int u, int *length);
void	ft_pointer(size_t pointer, int *length);

int		ft_printf(const char *string, ...);

#endif
