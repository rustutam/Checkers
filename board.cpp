#include "board.h"
void ErrorMove(){
    std::cout << "Wrong move, you can't go there" << std::endl;
}
void Board::PrintBoard(int (& position)[8][8]) {
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    int cnt=height;
    for (int i = 0; i < height; i++) {
        SetConsoleTextAttribute(h, (((black << 4) | white)));
        std::cout << cnt <<" ";
        cnt--;
        for (int j = 0; j < width; j++) {
            switch (position[i][j]) {
                case 0:
                    SetConsoleTextAttribute(h, (((dark_gray << 4) | 1)));
                    std::cout << "   ";
                    break;
                case 1:
                    SetConsoleTextAttribute(h, (((dark_gray << 4) | white)));
                    std::cout << " o ";
                    break;
                case 2:
                    SetConsoleTextAttribute(h, (((dark_gray << 4) | black)));
                    std::cout << " o ";
                    break;
                case 3:
                    SetConsoleTextAttribute(h, (((dark_gray << 4) | white)));
                    std::cout << " O ";
                    break;
                case 4:
                    SetConsoleTextAttribute(h, (((dark_gray << 4) | black)));
                    std::cout << " O ";
                    break;
                case 6:
                    SetConsoleTextAttribute(h, (((light_gray << 4) | 1)));
                    std::cout << "   ";
                    break;
            }
        }
        SetConsoleTextAttribute(h, (((black << 4) | black)));
        std::cout << std::endl;
    }
    SetConsoleTextAttribute(h, (((black << 4) | white)));
    std::cout << "   a  b  c  d  e  f  g  h" << std::endl;
    SetConsoleTextAttribute(h, (((black << 4) | white)));
    std::cout << std::endl;
}

void Board::Move(int (& position)[8][8],int x1,int y1,int x2, int y2) {//ход

    if (position[x2][y2] == 0) { //проверка не наступил ли на другую шашку или можно ли туда вообще сходить
        int temp = position[x2][y2];
        position[x2][y2] = position[x1][y1];
        position[x1][y1] = temp;
    } else {
        ErrorMove();
        Move(position, x1, y1, x2, y2);
    }

}

bool Board::IsPlayerChecker(int pos, Color color) {
    if ((pos == 1 || pos == 3) && color == white){
        return true;
    }
    if ((pos == 2 || pos == 4) && color == black){
        return true;
    }
    return false;
}