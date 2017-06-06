void enter_snake()
{
    print_snake_hello();
    _delay_ms(1000);
    snake_init();
    snake_play();
}

void snake_init()
{
    make_boundary();
    make_snake();
    make_food();
    print_snake_grids();
}

void make_snake()
{
}

void make_food()
{
}

void sanke_play()
{
    typedef struct
    {
        signed char x;
        signed char y;
    } direction;
}

void set_grid()
{
}

void move()
{
}