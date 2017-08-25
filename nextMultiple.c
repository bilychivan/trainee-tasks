/*
Задача nextMultiple

Условие задачи
Считать с клавиатуры два целых числа - делимое и делитель, причем делитель не равен нулю.
Вывести на экран наименьшее число, кратное делителю, не меньшее делимого.
Пример ввода
15 6
Пример вывода
18

*/

#include <stdio.h>

int main(void) {
	int dividend = 0;
	int	divider = 0;

	scanf("%d %d", &dividend, &divider);
	while ((dividend % divider) != 0) {
		dividend++;
	}
	printf("%d\n", dividend);

	return 0;
}