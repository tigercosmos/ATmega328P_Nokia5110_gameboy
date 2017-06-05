void enter_menu()
{
    unsigned char cursor = 1;
    print_menu(cursor);
    while (1)
    {
        print_menu(cursor);

        if (isBtnUp() && check_cursor_boundary(cursor - 1))
        {
            cursor -= 1;
            print_menu(cursor);
            tone(0, 50);
        }
        if (isBtnDown() && check_cursor_boundary(cursor + 1))
        {
            cursor += 1;
            print_menu(cursor);
            tone(0, 50);
        }

        if (isBtnCtrl())
        {
            tone(0, 50);
            enter_game(cursor);
        }
    }
}

unsigned char check_cursor_boundary(unsigned char cur)
{
    return (cur >= MENU_FIST && cur <= MENU_LAST);
}

void enter_game(unsigned char cur)
{
    if (cur == 1)
    {
        enter_snake();
    }
    else if (cur == 1)
    {
        enter_shoot();
    }
    else
    {
        return;
    }
}