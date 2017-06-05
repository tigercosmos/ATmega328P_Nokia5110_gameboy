unsigned char isBtnUp()
{
    return BTN & (1 << BTN_UP);
}

unsigned char isBtnRight()
{
    return BTN & (1 << BTN_RIGHT);
}

unsigned char isBtnLeft()
{
    return BTN & (1 << BTN_LEFT);
}

unsigned char isBtnDown()
{
    return BTN & (1 << BTN_DOWN);
}

unsigned char isBtnFire()
{
    return BTN & (1 << BTN_FIRE);
}

unsigned char isBtnCtrl()
{
    return BTN & (1 << BTN_CTRL);
}