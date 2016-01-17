#ifndef __DICE__
#define __DICE__

class Dice {
    static Dice *die1;
    static Dice *die2;
    
    Dice();
    
public:
    int value;
    static Dice *getDie1();
    static Dice *getDie2();
    static void roll(int d1 = 0, int d2 = 0);
};

#endif
