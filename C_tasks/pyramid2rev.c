/*
Задача pyramid2rev

Условие задачи
Вывести числовую пирамидку на total строк. Порядок строк – обратный.
В первой строке стоит число 1. В последующих строках стоят увеличивающиеся числа
через пробел.

Пример ввода
3
Пример вывода
4 5 6
2 3
1

*/

#include "stdio.h"

int main()
{
	unsigned int total;
	unsigned int first_in_row;

	scanf("%u", &total);

	first_in_row = total * (total + 1) / 2 - total;

	for ( ; total ; --total)
	{
		for (int j = 1; j < total; ++j)
		{
			printf("%d ", first_in_row + j);
		}
		printf("%d\n", first_in_row + total);

		first_in_row -= total - 1;
	}

	return 0;
}