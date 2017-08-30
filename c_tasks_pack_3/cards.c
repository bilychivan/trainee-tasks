/*
Игральные карты

Создать struct для игры в карты. Понадобится пара enum-ов.
Обеспечить соответствие между достоинством карты и его числовым эквивалентом,
т.е., к примеру, числовой эквивалент "девятки" должен быть равен 9.
*/

typedef enum {
    Clubs,
    Diamonds,
    Hearts,
    Spades
} Suit;

typedef enum {
    ACE = 1,
    CARD_2,
    CARD_3,
    CARD_4,
    CARD_5,
    CARD_6,
    CARD_7,
    CARD_8,
    CARD_9,
    CARD_10,
    JACK,
    QUEEN,
    KING
} Rank;

typedef struct {
    Suit suit;
    Rank card;
} PlayingCard;