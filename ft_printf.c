/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmiszkie <wmiszkie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:59:10 by wmiszkie          #+#    #+#             */
/*   Updated: 2024/04/22 15:23:34 by wmiszkie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_print.h"
/*Wyjaśnienie Krok po Kroku va_arg(*args, char *):

Funkcja va_arg jest używana do pobierania następnego argumentu z listy
argumentów zmiennej długości. *args to wskaźnik do listy argumentów zmiennej
długości przekazanej do funkcji. char * to typ danych, który spodziewamy się
pobrać. W tym przypadku jest to wskaźnik do typu char, co oznacza, że oczekujemy
stringa (ciągu znaków). va_arg(*args, char *) pobiera następny argument z listy
args i interpretuje go jako wskaźnik do char (czyli string). ft_string(...):

Funkcja ft_string jest wywoływana z dwoma argumentami: String pobrany z listy
argumentów za pomocą va_arg. Wskaźnik do zmiennej len, która przechowuje długość
wynikowego ciągu znaków. len:

len to wskaźnik do zmiennej całkowitej, który przechowuje długość wynikowego
ciągu znaków. Funkcja ft_string będzie używać tego wskaźnika, aby zaktualizować
długość na podstawie wypisanego stringa.*/
static void	ft_printf_checker(char s, va_list *args, int *len, int *i)
{
	if (s == 's')
		ft_string(va_arg(*args, char *), len);
	else if (s == 'd' || s == 'i')
		ft_number(va_arg(*args, int), len);
	else if (s == 'u')
		ft_unsigned_int(va_arg(*args, unsigned int), len);
	else if (s == 'x')
		ft_hexadecimal(va_arg(*args, unsigned int), len, 'x');
	else if (s == 'X')
		ft_hexadecimal(va_arg(*args, unsigned int), len, 'X');
	else if (s == 'p')
		ft_pointer(va_arg(*args, size_t), len);
	else if (s == 'c')
		ft_putcharacter_length(va_arg(*args, int), len);
	else if (s == '%')
		ft_putcharacter_length('%', len);
	else
		(*i)--;
}

/*Deklaracje i Inicjalizacje:

va_list args;: Deklaruje zmienną args, która będzie przechowywać argumenty
zmiennej długości. int i; int length;: Deklaruje zmienne i (do iteracji) i
length (do przechowywania długości wynikowego ciągu znaków). i = 0; length = 0;:
Inicjalizuje i na 0 i length na 0. Inicjalizacja Listy Argumentów:

va_start(args, string);: Inicjalizuje args, aby można było pobierać kolejne
argumenty zmiennej długości. Funkcja va_start przyjmuje dwa argumenty: zmienną
typu va_list i ostatni nazwany argument funkcji (string w tym przypadku). Pętla
Przetwarzająca Każdy Znak:

while (string[i] != '\0'): Pętla iteruje po każdym znaku w stringu, dopóki nie
napotka końca ('\0'). Sprawdzenie i Przetwarzanie Specyfikatorów Formatu:

if (string[i] == '%'): Jeśli bieżący znak to '%', oznacza to, że mamy do
czynienia ze specyfikatorem formatu. i++;: Przesuwa indeks i o jeden, aby
sprawdzić następny znak po '%'. ft_printf_checker(string[i], &args, &length,
&i);: Wywołuje funkcję ft_printf_checker, aby przetworzyć specyfikator formatu.
Funkcja ta pobiera odpowiedni argument z listy args, przetwarza go i aktualizuje
długość wynikowego ciągu znaków (length). i++;: Przesuwa indeks i o jeden, aby
przejść do następnego znaku po specyfikatorze formatu. Wypisywanie Znaków Nie
Będących Specyfikatorami Formatu:

else: Jeśli bieżący znak nie jest '%', traktujemy go jako zwykły znak do
wypisania. ft_putcharacter_length((char)string[i], &length);: Wywołuje funkcję
ft_putcharacter_length, aby wypisać bieżący znak i zaktualizować długość
wynikowego ciągu znaków (length). i++;: Przesuwa indeks i o jeden, aby przejść
do następnego znaku. Zakończenie Przetwarzania Listy Argumentów:

va_end(args);: Kończy przetwarzanie listy argumentów zmiennej długości. Funkcja
va_end zwalnia wszelkie zasoby przydzielone do args. Zwrócenie Wynikowej
Długości Ciągu Znaków:

return (length);: Zwraca długość wynikowego ciągu znaków, który został wypisany
przez funkcję ft_printf.*/
int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			ft_printf_checker(string[i], &args, &length, &i);
			i++;
		}
		else
		{
			ft_putcharacter_length((char)string[i], &length);
			i++;
		}
	}
	va_end(args);
	return (length);
}