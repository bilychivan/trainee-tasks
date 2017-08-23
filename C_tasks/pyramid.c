/*
Задача pyramid

Условие задачи
Вывести в консоль числовую пирамидку на total строк.
В каждой строке числа идут от единицы до номера строки через пробел.
Пропустить rows строк и cols столбцов.
В выводе не должно быть пустых строк до и после чисел.
Целые положительные числа total, rows и cols считать с клавиатуры.

Пример ввода
5 3 2
Пример вывода
3 4
3 4 5

*/

#include "stdio.h"

int main()
{
	unsigned int total, rows, cols;

	scanf("%u%u%u", &total, &rows, &cols);

	for (unsigned int row_number = rows + 1; row_number <= total; ++row_number)
	{
		for (unsigned int col_number = cols + 1; col_number < row_number; ++col_number)
		{
			printf("%u ", col_number);
		}
		printf("%d\n", row_number);
	}

	return 0;
}