#define MAX_QUEUE 254

Position snake_body[MAX_QUEUE];
Position set_empty_grid = {.x = 87, .y = 47}; // set to boundary as empty
Position next_grid = {.x = 0, .y = 0};
Position food_pos;

Direction next_dir = {.dirX = -1, .dirY = 0};

int front = 0, rear = 0;

unsigned score = 0;

void enter_snake()
{
    print_snake_hello();
    snake_init();
    snake_play();
}

void snake_init()
{
    srand(BTN_CLICKS);
    nokia_lcd_clear();
    score = 0;
    front = 0;
    rear = 0;
    for (register unsigned i = 0; i < MAX_QUEUE; i++)
    {
        snake_body[i] = set_empty_grid;
    }
    make_snake();
    make_food();
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

    Position pos = {.x = 48, .y = 24};
    for (register unsigned i = 0; i < 5; i++)
    {
        pos.y += 1;
        grow(pos);
    }
}

void make_food()
{
    // random food, avoiding next to boundary
    food_pos.x = rand() % 82 + 2;
    food_pos.y = rand() % 35 + 12;
}

void snake_play()
{
    // while(!collide){
    while (1)
    {
        /*
        **  Buttons Control
        */
        if (isBtnUp())
        {
            next_dir = (struct Direction){.dirX = 0, .dirY = -1};
            tone(0, 50);
        }
        if (isBtnDown())
        {
            next_dir = (struct Direction){.dirX = 0, .dirY = 1};
            tone(0, 50);
        }
        if (isBtnRight())
        {
            next_dir = (struct Direction){.dirX = 1, .dirY = 0};
            tone(0, 50);
        }
        if (isBtnLeft())
        {
            next_dir = (struct Direction){.dirX = -1, .dirY = 0};
            tone(0, 50);
        }
        if (isBtnCtrl())
        {
            tone(0, 50);
            enter_menu();
        }

        // Predict next position
        next_grid = (struct Position){
            .x = snake_body[rear].x + next_dir.dirX,
            .y = snake_body[rear].y + next_dir.dirY};

        if (eat())
        {
            grow(food_pos);
            make_food();
        }

        if (!collide())
        {
            move();
        }
        else
        {
            snake_lose();
        }

        print_snake_update();
    }
}

uint8_t eat()
{
    if (next_grid.x == food_pos.x && next_grid.y == food_pos.y)
    {
        score += 1;
        return 1;
    }
    return 0;
}

uint8_t collide()
{
    // Collide boundary
    if (next_grid.x == 0 || next_grid.x == 87)
    {
        return 1;
    }
    else if (next_grid.y == 10 || next_grid.y == 47)
    {
        return 1;
    }

    // Collide itself
    for (register unsigned i = 0; i < MAX_QUEUE; i++)
    {
        if (snake_body[i].x == next_grid.x && snake_body[i].y == next_grid.y)
        {
            return 1;
        }
    }

    return 0;
}

void snake_set_grids()
{
    register unsigned i;
    // Boundary
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

    // Snake
    for (i = 0; i < MAX_QUEUE; i++)
    {
        nokia_lcd_set_pixel(snake_body[i].x, snake_body[i].y, 1);
    }

    // Food
    nokia_lcd_set_pixel(food_pos.x, food_pos.y, 1);
}

void move()
{
    /*
    **  Delete grid as the snake tail
    */
    snake_body[front] = set_empty_grid;
    front = (front + 1) % MAX_QUEUE;

    /*
    ** Push new grid as the snake head
    */
    rear = (rear + 1) % MAX_QUEUE;
    snake_body[rear] = next_grid;
}

uint8_t isFull()
{
    return ((rear + 1) % MAX_QUEUE) == front;
}

void grow(Position pos)
{

    if (isFull())
    {
        snake_win();
    }
    rear = (rear + 1) % MAX_QUEUE;
    snake_body[rear] = pos;

    // Grow at head, so need to refresh next grid
    next_grid = (struct Position){
        .x = snake_body[rear].x + next_dir.dirX,
        .y = snake_body[rear].y + next_dir.dirY};
}

void snake_win()
{
    print_win();
    enter_menu();
}

void snake_lose()
{
    print_lose();
    enter_menu();
}