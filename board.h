#pragma once
#include "players.h"
#include <string>
#include <Windows.h>

class Board{
private:
    int const height = 8;
    int const width = 8;
public:
    void PrintBoard(int (& position)[8][8]);
    void Move(int (& position)[8][8],int,int,int,int);
    bool IsPlayerChecker(int,Color);//передаем цвет игрока
};
