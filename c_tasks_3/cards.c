/*
Игральные карты

Создать struct для игры в карты. Понадобится пара enum-ов.
Обеспечить соответствие между достоинством карты и его числовым эквивалентом,
т.е., к примеру, числовой эквивалент "девятки" должен быть равен 9.
*/

#include <stdio.h>

#define SIZE 4

typedef enum
{
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    JACK,
    QUEEN,
    KING,
    ACE
} Name;

typedef enum
{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
} Suit;

typedef struct
{
    Name name;
    Suit suit;
} Card;

const int cardValues[] =
{
    6, 7, 8, 9, 10, 11, 12, 1
};

const char* cardNames[] =
{
    "SIX", "SEVEN", "EIGHT", "NINE", "JACK", "QUEEN", "KING", "ACE"
};

const char* nameToString(Card card)
{
    return cardNames[card.name];
}

int nameToValue(Card card)
{
    return cardValues[card.name];
}

void test()
{
    const Card cards[] =
    {
        {SIX, HEARTS}, {ACE, DIAMONDS}, {JACK, SPADES}, {EIGHT, CLUBS}
    };

    for (int i = 0; i < SIZE; ++i)
    {
        printf("%s = %d\n", nameToString(cards[i]), nameToValue(cards[i]));
    }
}

int main()
{
    test();

    return 0;
}