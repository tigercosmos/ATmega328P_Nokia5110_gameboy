void print_hello()
{
    nokia_lcd_clear();
    nokia_lcd_write_string("328P with 5110 ", 1);
    nokia_lcd_set_cursor(0, 15);
    nokia_lcd_write_string("GameBoy", 2);
    nokia_lcd_set_cursor(0, 40);
    nokia_lcd_write_string("By tigercosmos", 1);
    nokia_lcd_render();
}

void print_menu(unsigned char cursor)
{

    if (cursor < MENU_FIST || cursor > MENU_LAST)
    {
        return;
    }

    nokia_lcd_clear();
    nokia_lcd_write_string("Menu", 1);
    nokia_lcd_set_cursor(0, 15);
    if (cursor == 1)
    {
        nokia_lcd_write_string("* Snake", 1);
    }
    else
    {
        nokia_lcd_write_string("Snake", 1);
    }
    nokia_lcd_set_cursor(0, 25);
    if (cursor == 2)
    {
        nokia_lcd_write_string("* Shoot", 1);
    }
    else
    {
        nokia_lcd_write_string("Shoot", 1);
    }

    nokia_lcd_set_cursor(0, 40);
    nokia_lcd_write_string("==Press CTRL==", 1);
    nokia_lcd_render();
}
