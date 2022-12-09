#pragma once
#include <string>
#include <utility>
#include <iostream>
enum Color {
    black = 0,
    light_gray = 7,
    dark_gray = 8,
    white = 15
};
class Player {
private:
    std::string name;
    Color color;
    bool my_chop = false;
public:
    Player(std::string name, Color color) : name(std::move(name)), color(color) {};
    int count_checkers = 12;
    std::string GetName() const {return name;}
    Color GetColor() const {return color;}
    int GetCountCheckers() { return count_checkers;}
    bool GetMyChop() {return my_chop;}
    void SetMyChop(bool my_chop);
};

