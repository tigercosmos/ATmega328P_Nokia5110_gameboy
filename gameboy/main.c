/*
** @author tigercosmos
*/
#define F_CPU 1000000UL

#include "./dependencies/index.h"

int main(void)
{
		sound_init();
		nokia_lcd_init();
		print_hello();
		welcome_sound();
		enter_menu();
}

