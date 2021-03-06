void sound_init()
{
	CLKPR = (1 << CLKPCE);
	CLKPR = 0b00000011;
	DDRD = 0xFF;		// Buttons
	DDRC = (1 << DDC5); // PC5 output
}

void wave(float frequency)
{

	PORTC = 0; // initial output 0

	TCNT2 = 150;

	TCCR2A = 0;											// normal mode, int clk
	TCCR2B = ((1 << CS20) | (1 << CS21) | (1 << CS22)); // p=1024, start Timer2

	while ((TIFR2 & (1 << TOV2)) == 0)
	{
		// timer0
		float peroid = 1000000 * (1 / frequency) / 2; // ms
		unsigned char n = (unsigned char)(peroid / 64);
		TCNT0 = 256 - n;
		TCCR0A = 0;							  // normal mode, int clk
		TCCR0B = ((1 << CS00) | (1 << CS01)); // p=64, start Timer0
		while ((TIFR0 & (1 << TOV0)) == 0)
			;						   // wait for flag TOV0=1
		TCCR0B = 0;					   // stop Timer
		TIFR0 = (1 << TOV0);		   // clear TOV0
		PORTC = PORTC ^ (1 << PORTC5); // on and off

	} // wait for timer1 flag TOV1=1

	TCCR2B = 0;			 // stop Timer
	TIFR2 = (1 << TOV2); // clear TOV0

	PORTC = 0; // set output 0
}

void tone(unsigned char key)
{
	wave(melody[key]);
}

void lose_sound()
{
	tone(5);
	tone(4);
	tone(3);
}

void win_sound()
{
	tone(3);
	tone(4);
	tone(5);
	tone(4);
	tone(5);
}

void welcome_sound()
{
	tone(1);
	tone(4);
	tone(3);
	tone(5);
}
