#define MAX_QUEUE 255

Position snake_body[MAX_QUEUE];
int front = 0, rear = 0;

unsigned score = 0;

void enter_snake()
{
    print_snake_hello();
    snake_init();
    // snake_play();
}

void snake_init()
{
    make_snake();
    // make_food();
    print_snake_update();
}

void snake_show_score()
{
    nokia_lcd_set_cursor(0, 0);
    char score_string[12];
    sprintf(score_string, "Score: %d", score);
    nokia_lcd_write_string(score_string, 1);
}

void make_snake()
{

    Position temp = {.x = 24, .y = 0};
    for (register unsigned i = 0; i < 5; i++)
    {
        temp.y = i;
        grow(snake_body, temp);
    }
}

void make_food()
{
}

void sanke_play()
{
}

void snake_set_grids()
{
    register unsigned i;
    for (i = 0; i < 84; i++)
    {
        nokia_lcd_set_pixel(i, 10, 1);
        nokia_lcd_set_pixel(i, 47, 1);
    }
    for (i = 10; i < 48; i++)
    {
        nokia_lcd_set_pixel(0, i, 1);
        nokia_lcd_set_pixel(83, i, 1);
    }
    for (i = 0; i < MAX_QUEUE; i++)
    {
        nokia_lcd_set_pixel(snake_body[i].x, snake_body[i].y, 1);
    }
}

void move()
{
}

uint8_t isFull()
{
    return rear == MAX_QUEUE && front == 0;
}

uint8_t isEmpty()
{
    return front == rear;
}

void grow(Position *snake_body, Position current_position)
{
    if (isFull())
    {
        //snake_win();
        return;
    }
    snake_body[rear++] = current_position;
}