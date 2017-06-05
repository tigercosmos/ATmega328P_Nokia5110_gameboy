/*
 * Buttons' pins
 */
#define BTN PIND
#define BTN_RIGHT PIND5
#define BTN_DOWN PIND4
#define BTN_UP PIND3
#define BTN_LEFT PIND2
#define BTN_FIRE PIND6
#define BTN_CTRL PIND7

unsigned char isBtnUp();
unsigned char isBtnRight();
unsigned char isBtnLeft();
unsigned char isBtnDown();
unsigned char isBtnFire();
unsigned char isBtnCtrl();