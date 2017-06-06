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

void enter_snake();
void snake_init();
void snake_show_score();
void make_snake();
void snake_set_grids();
uint8_t isFull();
uint8_t isEmpty();
void grow(Position *snake_body, Position current_position);