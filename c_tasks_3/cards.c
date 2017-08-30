/*
Игральные карты

Создать struct для игры в карты. Понадобится пара enum-ов.
Обеспечить соответствие между достоинством карты и его числовым эквивалентом,
т.е., к примеру, числовой эквивалент "девятки" должен быть равен 9.
*/

#include <stdio.h>

typedef enum
{
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    JACK,
    QUEEN,
    KING,
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

const char* cardNames[] =
{
    "ACE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "JACK", "QUEEN", "KING" 
};

const char* nameToString(Card card)
{
    return cardNames[card.name - 1];
}

int nameToValue(Card card)
{
    return card.name;
}

void test()
{
    const Card cards[] =
    {
        {TWO, HEARTS}, {ACE, DIAMONDS}, {JACK, SPADES}, {KING, CLUBS}
    };

    const int size = sizeof(cards) / sizeof(Card);

    for (int i = 0; i < size; ++i)
    {
        printf("%s = %d\n", nameToString(cards[i]), nameToValue(cards[i]));
    }
}

int main()
{
    test();

    return 0;
}