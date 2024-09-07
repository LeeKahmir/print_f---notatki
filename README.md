# ft_printf - README WIKTORII MISZKIEWICZ 42 WARSAW

## Opis projektu
Projekt `ft_printf` polega na zaimplementowaniu własnej wersji funkcji `printf` w języku C. Głównym celem jest nauczenie się obsługi funkcji o zmiennej liczbie argumentów oraz zrozumienie działania standardowej funkcji `printf`.

## Wymagania
W projekcie należy zaimplementować funkcję `ft_printf`, która będzie obsługiwała następujące konwersje:
- `%c` - pojedynczy znak
- `%s` - ciąg znaków
- `%p` - wskaźnik w formacie szesnastkowym
- `%d` - liczba dziesiętna (signed)
- `%i` - liczba dziesiętna (signed)
- `%u` - liczba dziesiętna (unsigned)
- `%x` - liczba szesnastkowa (lowercase)
- `%X` - liczba szesnastkowa (uppercase)
- `%%` - znak procenta

## Struktura projektu
Projekt składa się z następujących plików:

- **src/ft_printf.c**: Główna funkcja `ft_printf`.
- **src/ft_printf_conversion.c**: Funkcja pomocnicza obsługująca konwersje.
- **src/ft_putchar.c**: Funkcja wypisująca pojedynczy znak.
- **src/ft_putstr.c**: Funkcja wypisująca ciąg znaków.
- **src/ft_putnbr.c**: Funkcja wypisująca liczbę całkowitą.
- **include/ft_printf.h**: Plik nagłówkowy z deklaracjami funkcji i ochroną przed wielokrotnym dołączaniem.
- **Makefile**: Plik makefile do kompilacji projektu.

## Kompilacja
Aby skompilować projekt, użyj polecenia `make` w katalogu głównym projektu. Spowoduje to utworzenie biblioteki statycznej `libftprintf.a`.

Aby użyć funkcji ft_printf w swoim projekcie, dołącz plik nagłówkowy ft_printf.h i skompiluj projekt z biblioteką libftprintf.a.


## Użycie
#include "ft_printf.h"

int main() {
    ft_printf("Hello, %s!\n", "world");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    return 0;
}
