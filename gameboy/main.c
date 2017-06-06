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
		enter_menu();
}

