/*
Игральные карты

Создать struct для игры в карты. Понадобится пара enum-ов.
Обеспечить соответствие между достоинством карты и его числовым эквивалентом,
т.е., к примеру, числовой эквивалент "девятки" должен быть равен 9.
*/

typedef enum {
    clubs,
    diamonds,
    hearts,
    spades
} Suit;

typedef enum {
    ace,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king
} Card;

typedef struct {
    Suit suit;
    Card card;
} PlayingCard;