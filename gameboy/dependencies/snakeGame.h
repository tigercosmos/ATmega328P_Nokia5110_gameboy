typedef struct Direction
{
    signed char dirX;
    signed char dirY;
} Direction;

typedef struct Position
{
    unsigned char x;
    unsigned char y;
} Position;

void snake_play();
void enter_snake();
void snake_init();
void snake_show_score();
void make_food();
void make_snake();
void move();
void snake_set_grids();
uint8_t collide();
uint8_t isFull();
uint8_t eat();
void grow(Position pos);
void snake_win();
void snake_lose();