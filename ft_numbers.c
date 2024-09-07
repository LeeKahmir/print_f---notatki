/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmiszkie <wmiszkie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:59:10 by wmiszkie          #+#    #+#             */
/*   Updated: 2024/04/22 15:23:34 by wmiszkie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_print.h"

// ft_putnbr - liczby całkowite (ujemne i dodatnie)

/*if (number == -2147483648): Sprawdza, czy liczba jest równa -2147483648, co
jest najmniejszą liczbą możliwą do przechowywania w typie int. write(1,
"-2147483648", 11);: Wypisuje ciąg znaków "-2147483648" na standardowe wyjście
(ekran). (*length) += 11;: Zwiększa długość wypisanego ciągu znaków o 11,
ponieważ "-2147483648" ma 11 znaków. return ;: Kończy działanie funkcji,
ponieważ liczba została już wypisana.*/

/*if (number < 0): Sprawdza, czy liczba jest mniejsza niż 0, czyli jest ujemna.
ft_putcharacter_length('-', length);: Wypisuje znak minus ('-') i aktualizuje
długość wypisanego ciągu znaków. ft_number(number * -1, length);: Rekurencyjnie
wywołuje ft_number z liczbą przekształconą na dodatnią (mnożąc przez -1).
Rekurencyjne wywołanie oznacza, że funkcja wywołuje sama siebie w swoim kodzie.
Jest to technika programowania, w której funkcja rozwiązuje problem, dzieląc go
na mniejsze podproblemy tego samego typu, aż do osiągnięcia najprostszego
przypadku, który można rozwiązać bez dalszych wywołań.*/

/*else: Ta część kodu jest wykonywana, jeśli liczba jest dodatnia lub równa 0.
if (number > 9): Sprawdza, czy liczba jest większa niż 9. Jeśli tak, oznacza to,
że liczba ma więcej niż jedną cyfrę. ft_number(number / 10, length);:
Rekurencyjnie wywołuje ft_number z liczbą podzieloną przez 10, co pozwala na
wypisanie wszystkich cyfr liczby. ft_putcharacter_length(number % 10 + '0',
length);: Wypisuje ostatnią cyfrę liczby (resztę z dzielenia przez 10) jako
znak. + '0' przekształca cyfrę na odpowiedni znak ASCII.*/
/*Dzielenie przez 10 pozwala na usunięcie ostatniej cyfry liczby. Dzięki temu,
wywołując funkcję rekurencyjnie, możemy „rozbić” liczbę na pojedyncze cyfry od
najbardziej znaczącej (najbardziej na lewo) do najmniej znaczącej (najbardziej
na prawo).
Przykład:
Początkowa liczba: 123
123 / 10 = 12 (usuwa cyfrę 3)
12 / 10 = 1 (usuwa cyfrę 2)
1 / 10 = 0 (usuwa cyfrę 1)*/
/*Wypisanie ostatniej cyfry: ft_putcharacter_length(number % 10 + '0', length);
number % 10: Reszta z dzielenia liczby przez 10 daje ostatnią cyfrę liczby.
Przykład: 123 % 10 = 3, 12 % 10 = 2, 1 % 10 = 1.
+ '0': Dodanie znaku '0' do cyfry przekształca ją w odpowiedni znak ASCII. ASCII
  dla '0' wynosi 48. Dodając cyfrę, otrzymujemy odpowiedni znak:
	0 + '0' = '0' (48)
	1 + '0' = '1' (49)
	2 + '0' = '2' (50) i tak dalej...
  ft_putcharacter_length(number % 10 + '0', length);: Wypisuje ostatnią cyfrę
  liczby jako znak ASCII i aktualizuje długość wypisanego ciągu znaków.
  Cyfra 0:Kod ASCII dla cyfry '0' wynosi 48.
  Cyfra 0 w formie liczby całkowitej to po prostu 0.
  Dodajemy kod ASCII znaku '0' do naszej cyfry: 0 + 48 = 48.
  48 to kod ASCII znaku '0', więc wynik to znak '0'.
  Cyfra 1: Kod ASCII dla cyfry '0' wynosi 48.
  Cyfra 1 w formie liczby całkowitej to 1.
  Dodajemy kod ASCII znaku '0' do naszej cyfry: 1 + 48 = 49.
  49 to kod ASCII znaku '1', więc wynik to znak '1'.*/

// ft_putnbr - liczby całkowite (ujemne i dodatnie)
void	ft_number(int number, int *length)
{
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*length) += 11;
		return ;
	}
	if (number < 0)
	{
		ft_putcharacter_length("-", length);
		ft_number(number * -1, length);
	}
	else
	{
		if (number > 9)
		{
			ft_number(number / 10, length);
			ft_putcharacter_length(number % 10 + '0', length);
		}
	}
}

// unsigned int (Liczba całkowita nieujemna !!)

/*if (u >= 10): Sprawdza, czy liczba u jest większa lub równa 10.
ft_unsigned_int(u / 10, length);: Jeśli liczba u jest większa lub równa 10,
funkcja wywołuje sama siebie z wartością u podzieloną przez 10. To usuwa
ostatnią cyfrę liczby.u % 10: Reszta z dzielenia liczby u przez 10 daje ostatnią
cyfrę liczby. u % 10 + '0': Dodanie znaku '0' przekształca cyfrę w odpowiedni
znak ASCII. ft_putcharacter_length(u % 10 + '0', length);: Wypisuje ostatnią
cyfrę liczby jako znak ASCII i aktualizuje długość wypisanego ciągu znaków.*/

// unsigned int (Liczba całkowita nieujemna !!)
void	ft_unsigned_int(unsigned int u, int *length)
{
	if (u >= 10)
		ft_unsigned_int(u / 10, length);
	ft_putcharacter_length(u % 10 + '0', length);
}

// pointer - Funkcja ft_pointer konwertuje wartość wskaźnika na reprezentację
// szesnastkową, wypisuje ją w formacie "0x..." i aktualizuje liczbę wypisanych
// znaków poprzez wskaźnik length.

/*char string[25]: Tablica znaków używana do przechowywania wyników konwersji
liczby na system szesnastkowy. Przyjęto rozmiar 25, aby pomieścić maksymalny
rozmiar liczby w systemie szesnastkowym dla size_t. int i: Zmienna pomocnicza
używana jako indeks w tablicy string. char *base_character: Wskaźnik na łańcuch
znaków, który zawiera znaki używane do reprezentacji cyfr szesnastkowych
("0123456789abcdef").*/

/*base_character = "0123456789abcdef";: Inicjalizujemy wskaźnik base_character,
aby wskazywał na ciąg znaków reprezentujących cyfry szesnastkowe. i = 0;:
Ustawiamy początkową wartość zmiennej i na 0. write(1, "0x", 2);: Wypisujemy na
standardowe wyjście ciąg znaków "0x", który jest prefiksem adresu
szesnastkowego. (*length) += 2;: Zwiększamy wartość length o 2, ponieważ
wypisaliśmy dwa znaki ("0x").*/

/*if (pointer == 0): Sprawdzamy, czy wartość pointer wynosi 0.
ft_putcharacter_length('0', length);: Jeśli pointer wynosi 0, wywołujemy funkcję
ft_putcharacter_length, aby wypisać '0' i zwiększyć wartość length. return ;:
Kończymy działanie funkcji, ponieważ adres 0 został już wypisany.*/

/*while (pointer != 0): Pętla wykonuje się tak długo, jak pointer jest różne od
0. string[i] = base_character[pointer % 16];: Obliczamy resztę z dzielenia
pointer przez 16 (pointer % 16), aby uzyskać kolejną cyfrę szesnastkową.
Następnie pobieramy odpowiedni znak z base_character i zapisujemy go w string
pod indeksem i. pointer = pointer / 16;: Dzielimy pointer przez 16, aby
przesunąć się do następnej cyfry szesnastkowej. i++;: Zwiększamy indeks i, aby
przejść do następnej pozycji w tablicy string.*/

/*while (i--): Pętla wykonuje się, dopóki i jest większe od 0. Zmniejszamy i o 1
przy każdej iteracji. ft_putcharacter_length(string[i], length);: Wypisujemy
znaki z tablicy string w odwrotnej kolejności (od końca do początku) przy użyciu
funkcji ft_putcharacter_length. Funkcja ta również zwiększa wartość length za
każdym razem, gdy wypisuje znak.*/
/*Pierwsza iteracja pętli Warunek pętli: pointer != 0 (1234 != 0), więc pętla
się wykonuje. Obliczenie reszty: pointer % 16 daje 1234 % 16 = 2. Zapisanie
znaku: base_character[2] to '2', więc string[0] = '2'. Aktualizacja wskaźnika:
pointer = pointer / 16 daje 1234 / 16 = 77 (zaokrąglone w dół). Inkrementacja
indeksu: i++ daje i = 1.*/

// pointer
void	ft_pointer(size_t pointer, int *length)
{
	char	string[25];
	int		i;
	char	*base_character;

	base_character = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	(*length) += 2;
	if (pointer == 0)
	{
		ft_putcharacter_length('0', length);
		return ;
	}
	while (pointer != 0)
	{
		string[i] = base_character[pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	while (i--)
/*i-- oznacza, że najpierw sprawdzamy warunek,a potem zmniejszamy wartość
i.Pętla wykonuje się tak długo, jak i jest większe od zera. Kiedy i staje się
zero, warunek i-- zwraca fałsz (ponieważ i zmniejsza się po porównaniu, ale
przed sprawdzeniem warunku), i pętla się kończy. Dzięki temu pętla zaczyna się
od wartości i-1 i kończy się, gdy i wynosi zero.*/
	{
		ft_putcharacter_length(string[i], length);
	}
}

// hexadecimal - x or X
/*// Definiujemy funkcję o nazwie ft_hexadecimal, która przyjmuje trzy
argumenty: // 1. unsigned int x - liczba, którą chcemy zamienić na zapis
szesnastkowy (heksadecymalny). // 2. int *length - wskaźnik do zmiennej, w
której będziemy przechowywać długość naszego wyniku. // 3. char x_or_x - znak,
który określa, czy chcemy użyć dużych ('X') czy małych ('x') liter w zapisie
heksadecymalnym.*/

// hexadecimal - x or X

void ft_hexadecimal(unsigned int x, int *length, char x_or_x)
{
	char string[25];
	int i;
	char *base_characters;

	if (x_or_x == 'X')
		base_characters = "0123456789ABCDEF";
	else
		base_characters = "0123456789abcdef";
	i = 0;
	if ( x == 0)
	{
		ft_putcharacter_length('0', length);
		return;
	}
	while (x != 0)
	{
		string[i] = base_characters[x % 16];
		x = x / 16;
		i ++;
	}
	while (i--)
		ft_putcharacter_length(string[i],length);
}