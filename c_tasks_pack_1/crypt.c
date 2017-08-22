/*
Задача crypt

Условие задачи
Числа шифруются по определенному алгоритму с двумя секретными числовыми ключами – A и B.
Число умножается на значение ключа A, затем к результату прибавляется значение ключа B.
Шифруемые числа и значения ключей не превышают по модулю 30000.
В ходе разведывательной операции стали известны зашифрованные эквиваленты двух чисел.
Необходимо найти подходящие ключи и расшифровать зашифрованную последовательность чисел.

Входные данные:
plain1 encrypted1
plain2 encrypted2
length
<последовательность length зашифрованных чисел>
Пример ввода
1 3
2 5
5
7 9 11 13 15
Пример вывода
3 4 5 6 7
Пояснение
В процессе шифрования числа умножали на A = 2, затем к результату добавляли B = 1.
1 * A + B = 3
2 * A + B = 5

*/

#include <stdio.h>

int main()
{
	int plain1;
	int encrypted1;
	int plain2;
	int encrypted2;
	int length;
	
	scanf("%i %i %i %i %i", &plain1, &encrypted1, &plain2, &encrypted2, &length);
	
	int inputs[length];
	
	for (int i = 0; i < length; i++)
	{
		scanf("%u", &inputs[i]);
	}
	
	printf("\nplain1: %i | encrypted1: %i\nplain2: %i | encrypted2: %i\nlength: %i\n", plain1, encrypted1, plain2, encrypted2, length);
	for (int i = 0; i < length; i++)
	{
		printf("%u ", inputs[i]);
	}
	puts("");
	
	int factor = 1;
	while ((plain1 * (factor+1)) < encrypted1)
	{
		factor++;
	}
	int difference = encrypted1 - (plain1 * factor);
	printf("key A between plain1 and encrypted1 is: %i\n", factor);
	printf("key B between plain1 and encrypted1 is: %i\n", difference);
	
	puts("Decrypted data:");
	for (int i = 0; i < length; i++)
	{
		printf("%i ", (inputs[i] - difference) / factor);
	}
	puts("");
	return 0;
}