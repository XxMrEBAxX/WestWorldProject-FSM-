#include <iostream>
#include <Windows.h>
#include "CMiner.h"

int main()
{
    CMiner miner(CEnterMineAndForNugget::getInstance(), "Bob");

    while (true)
    {
        miner.update();
        Sleep(1000);
    }
}
