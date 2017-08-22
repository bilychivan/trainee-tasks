/*
Задача pascal

Условие задачи
Получить число lines, распечатать первые lines строк треугольника Паскаля. Числа
выводить с начала строки через пробел.

Если очертить треугольник Паскаля, то получится равнобедренный треугольник. В
этом треугольнике на вершине и по бокам стоят единицы. Каждое число равно сумме
двух, расположенных над ним чисел. Продолжать треугольник можно бесконечно.
Строки треугольника симметричны относительно вертикальной оси. Имеет применение
в теории вероятности и обладает занимательными свойствами.
© Wikipedia

Для решения этой задачи достаточно материала 1-го уикенда.

Пример ввода
6
Пример вывода
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
*/

#include <stdio.h>
#include<stdarg.h>

// сделал чуть более красивый вывод, снизу есть закомментированный код без смещений для "красивого" вывода
void printf_pretty(int line, int lines, const char* format, ...)
{
  va_list arglist;

  for (unsigned int i = line; i < lines; i++)
  {
      putc(' ', stdout);
  }

  va_start(arglist, format);
  vprintf(format, arglist);
  va_end(arglist);
}

int main()
{
    unsigned int lines;

    scanf("%u", &lines);

    unsigned int arr[lines];
    unsigned int temp[lines];

    for (unsigned int i = 0; i < lines; i++)
    {
        arr[i] = 1;
        temp[i] = 1;
    }

    if (lines < 1)
    {
        return 0;
    }
    printf_pretty(0, lines, "%2i\n", 1);

    if (lines < 2)
    {
        return 0;
    }
    arr[0] = 1;
    arr[1] = 1;
    printf_pretty(1, lines, "%2i %2i\n", 1, 1);

    for (unsigned int line = 2; line < lines; line++)
    {
        for (unsigned int row = 0; row <= line; row++)
        {
            if ((row != 0) && (row != line))
            {
                temp[row] = arr[row - 1] + arr[row];
                printf("%2i ", temp[row]);
            }
            else
            {
                if (row == 0)
                {
                    printf_pretty(line, lines, "%2i ", 1);
                }
                else
                {
                    printf("%2i ", 1);
                }
            }
        }
        for (unsigned int i = 0; i < lines; i++)
        {
            arr[i] = temp[i];
        }
        puts("");
    }
    return 0;
}

/*int main()
{
    unsigned int lines;

    scanf("%u", &lines);

    unsigned int arr[lines];
    unsigned int temp[lines];

    for (unsigned int i = 0; i < lines; i++)
    {
        arr[i] = 1;
        temp[i] = 1;
    }

    if (lines < 1)
    {
        return 0;
    }
    puts("1");

    if (lines < 2)
    {
        return 0;
    }
    arr[0] = 1;
    arr[1] = 1;
    puts("1 1");

    for (unsigned int line = 2; line < lines; line++)
    {
        for (unsigned int row = 0; row <= line; row++)
        {
            if ((row != 0) && (row != line))
            {
                temp[row] = arr[row - 1] + arr[row];
                printf("%i ", temp[row]);
            }
            else
            {
                printf("1 ");
            }
        }
        for (unsigned int i = 0; i < lines; i++)
        {
            arr[i] = temp[i];
        }
        puts("");
    }
    return 0;
}*/
