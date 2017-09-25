/*
Задача isPrime()

Условие задачи
Написать функцию:
int isPrime(int n)

Проверить, является ли данное число простым.

*/

#include <stdio.h>

#define TRUE	1
#define FALSE	0

int isPrime(int n) {
	if (n > 1) {
		for (int i = 2; i <= n / 2; i++) {
			if ((n % i) == 0) {
				return FALSE;
			}
		}
	} else if (n >= 0) { 
		return FALSE;
	}

	return TRUE;
}