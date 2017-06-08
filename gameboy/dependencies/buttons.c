unsigned BTN_CLICKS = 0;

unsigned char isBtnUp()
{
    BTN_CLICKS += 1;
    return BTN & (1 << BTN_UP);
}

unsigned char isBtnRight()
{
    BTN_CLICKS += 1;
    return BTN & (1 << BTN_RIGHT);
}

unsigned char isBtnLeft()
{
    BTN_CLICKS += 1;
    return BTN & (1 << BTN_LEFT);
}

unsigned char isBtnDown()
{
    BTN_CLICKS += 1;
    return BTN & (1 << BTN_DOWN);
}

unsigned char isBtnFire()
{
    BTN_CLICKS += 1;
    return BTN & (1 << BTN_FIRE);
}

unsigned char isBtnCtrl()
{
    BTN_CLICKS += 1;
    return BTN & (1 << BTN_CTRL);
}