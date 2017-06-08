const float melody[] = {261.63, 293.66, 329.63, 349.23, 392, 440};

void sound_init();
void wave(float frequency);
void tone(unsigned char key);
void lose_sound();
void welcome_sound();
void win_sound();