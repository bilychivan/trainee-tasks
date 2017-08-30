/*
Игральные карты

Создать struct для игры в карты. Понадобится пара enum-ов.
Обеспечить соответствие между достоинством карты и его числовым эквивалентом,
т.е., к примеру, числовой эквивалент "девятки" должен быть равен 9.
*/

#include <stdio.h>

typedef enum 
{
    SIX = 6,
    SEVEN,
    EIGHT,
    NINE,
    JACK,
    QUEEN,
    KING,
    ACE
} Value;

typedef enum
{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
} Suit;


typedef struct
{
    Value val;
    Suit suit;
} Card;

void test()
{
    Card cards[] =
    {
        {SIX, HEARTS},{ACE, DIAMONDS}
    };

    printf("%d\n", cards[0].val);
    printf("%d\n", cards[1].val);
}

int main()
{
    test();

    return 0;
}