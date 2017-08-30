/*
Игральные карты

Создать struct для игры в карты. Понадобится пара enum-ов.
Обеспечить соответствие между достоинством карты и его числовым эквивалентом,
т.е., к примеру, числовой эквивалент "девятки" должен быть равен 9.
*/

typedef enum
{
    CARDVALUE_2  = 2,  CARDVALUE_TWO   = 2,
    CARDVALUE_3  = 3,  CARDVALUE_THREE = 3,
    CARDVALUE_4  = 4,  CARDVALUE_FOUR  = 4,
    CARDVALUE_5  = 5,  CARDVALUE_FIVE  = 5,
    CARDVALUE_6  = 6,  CARDVALUE_SIX   = 6,
    CARDVALUE_7  = 7,  CARDVALUE_SEVEN = 7,
    CARDVALUE_8  = 8,  CARDVALUE_EIGHT = 8,
    CARDVALUE_9  = 9,  CARDVALUE_NINE  = 9,
    CARDVALUE_10 = 10, CARDVALUE_TEN   = 10,

    CARDVALUE_JACK  = 11,
    CARDVALUE_QUEEN = 12,
    CARDVALUE_KING  = 13,
    CARDVALUE_ACE   = 14
} cardValue;

typedef enum
{
    CARDSUIT_SPADES,
    CARDSUIT_HEARTS,
    CARDSUIT_DIAMONDS,
    CARDSUIT_CLUBS
} cardSuit;

typedef struct
{
    cardValue value;
    cardSuit  suit;
} playingCard;