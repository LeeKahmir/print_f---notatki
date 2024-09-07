/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmiszkie <wmiszkie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:59:10 by wmiszkie          #+#    #+#             */
/*   Updated: 2024/04/22 15:23:34 by wmiszkie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_print.h"

/*Character*/

/*void: Typ zwracany przez funkcję. void oznacza, że funkcja nie zwraca żadnej
wartości. ft_putcharacter_length: Nazwa funkcji. char character: Argument
funkcji, który jest pojedynczym znakiem do wypisania. int *length: Argument
funkcji, wskaźnik na zmienną typu int, który przechowuje długość wypisanego
ciągu znaków.*/
/*Linia 1: write(1, &character, 1); write: Funkcja systemowa używana do
wypisywania danych. 1: Pierwszy argument write, oznacza standardowe wyjście
(stdout), czyli ekran komputera. &character: Drugi argument write, adres
zmiennej character, czyli miejsce w pamięci, gdzie znajduje się znak do
wypisania. 1: Trzeci argument write, liczba bajtów do zapisania, czyli jeden
bajt (jeden znak). Co robi write? write(1, &character, 1); wypisuje znak
character na ekran. Linia 2: (*length)++; (*length): Wskaźnik length jest
dereferencjonowany, czyli odwołujemy się do wartości, na którą wskazuje
wskaźnik. ++: Operator inkrementacji, zwiększa wartość zmiennej o 1. Co robi
(*length)++;? Zwiększa wartość zmiennej length o 1. W praktyce oznacza to, że do
długości wypisanego ciągu znaków dodajemy 1, ponieważ właśnie wypisaliśmy jeden
znak.
*/
void	ft_putcharacter_length(char character, int *length)
{
	write(1, &character, 1);
	(*length)++;
}

/*String*/

/*char *args: Argument funkcji, wskaźnik na ciąg znaków (string), który chcemy
wypisać. int *length: Argument funkcji, wskaźnik na zmienną typu int, która
przechowuje długość wypisanego ciągu znaków.*/
/*int *length: Argument funkcji, wskaźnik na zmienną typu int, która przechowuje
długość wypisanego ciągu znaków.*/

/*size_t i: Deklaracja zmiennej i typu size_t, używanej do iteracji po ciągu
znaków.Inicjalizacja zmiennej i na 0.*/
/*if (!str): Sprawdzenie, czy wskaźnik str jest pusty (NULL).*/
/**/
/*write(1, "(null)", 6);: Jeśli str jest pusty, wypisujemy ciąg znaków "(null)"
na standardowe wyjście (ekran).(*length) += 6;: Zwiększamy długość wypisanego
ciągu znaków o 6, ponieważ "(null)" ma 6 znaków.return ;: Kończymy funkcję,
ponieważ nie ma więcej znaków do wypisania.*/

/*while (str[i] != '\0'): Pętla, która iteruje po ciągu znaków str dopóki nie
napotka znaku null ('\0'), który oznacza koniec stringu.*/
/*ft_putcharacter_length(str[i], length);: Wywołuje funkcję
ft_putcharacter_length, aby wypisać znak str[i] i zaktualizować długość
wypisanego ciągu znaków.i++;: Zwiększa wartość i o 1, aby przejść do następnego
znaku w ciągu.*/
void	ft_string(char *str, int *length)
{
	size_t i;
	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		(*length) += 6;
		return ;
	}
	while (str[i] != '\0')
	{
		ft_putcharacter_length(str[i], length);
		i++;
	}
}