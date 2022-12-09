#include <iostream>
#include "game.h"
using namespace std;

void SettingColor(){
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "15 - ";
    SetConsoleTextAttribute(h, (((dark_gray << 4) | white)));
    cout << " o ";
    SetConsoleTextAttribute(h, (((black << 4) | white)));
    cout << "  0 - ";
    SetConsoleTextAttribute(h, (((dark_gray << 4) | black)));
    cout << " o ";
    SetConsoleTextAttribute(h, (((black << 4) | white)));
    cout << endl;
}
Color InputColor(){
    int num_color;
    cin >> num_color;
    cout << num_color<<endl;
    return static_cast<Color>(num_color);
}
void ColorErr(){
    cout << "Вы ввели неверный цвет, введите ";
    SettingColor();
}
Player &PlayerSetting(){
    cout << "Input name Player: ";
    string Playername;
    Color Playercolor;
    cin >> Playername;
    cout << Playername <<" ,choose the color of the checkers " << endl;
    SettingColor();
    bool CheckColor=true;
    while (CheckColor) {
        Playercolor=InputColor();
        if (Playercolor == 0 || Playercolor == 15){ CheckColor = false;}
        else ColorErr();
    }
    auto *player=new Player(Playername,Playercolor);
    return *player;
}

int main(){
    Player &player1 = PlayerSetting();
    Player &player2 = PlayerSetting();
    Board board;
    Game play;
    play.game(player1,player2,board);
    return 0;
}