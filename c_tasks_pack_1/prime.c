/*
Задача prime

Условие задачи
Вывести N-ное по счёту простое число (см. Википедию).
N считать с клавиатуры.
Оптимизировать работу программы, насколько это возможно.
В случае неопределенности ответа вывести -1.

Пример ввода
3
Пример вывода
5

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

int main(void) {
	int N;
	int counter;
	int res;

	scanf("%d", &N);
	if (N < 1) {
		printf("-1\n");
		return 1s;
	}
	for (int i = 2; counter < N; i++) {
		if (isPrime(i)) {
			counter += 1;
			res = i;
		}
	}
	printf("%d\n", res);

	return 0;
}