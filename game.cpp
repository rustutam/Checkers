#include "game.h"
#include <string>
#include <utility>
#include <iostream>
#include <vector>
using namespace std;
string ErrorMove1(){
    return "Choose your checker\n";
}
string YouCanChop(){
    return "You have to cut the checker\n";
}
void WhoIsFirst(Player &pl1,Player &pl2){
    if (pl1.GetColor() == white){
        pl1.SetMyChop(true);
    }
    else
        pl2.SetMyChop(true);
}
pair<int, int> move(){
    std::string posStart;
    std::cin >> posStart;
    std::pair<int,int> pos (7 - (posStart[1] - '1'),posStart[0] - 'a');
    return pos;
}
bool CanChop(int (& position)[8][8],const Player& player1,const Player& player2,Board board,vector<pair<int,int>>& PosStart,vector<pair<int,int>>& PosEnemy,vector<pair<int,int>>& PosFinish) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board.IsPlayerChecker(position[i][j], player1.GetColor())) {
                if (position[i][j]== 3 || position[i][j]== 4) {
                    int k = i + 1;
                    int m = j + 1;
                    while (k < 8 && m < 8) {
                        if (board.IsPlayerChecker(position[k][m], player2.GetColor())) {
                            if (position[k + 1][m + 1] == 0) {
                                PosStart.emplace_back(i, j);
                                PosEnemy.emplace_back(k, m);
                                PosFinish.emplace_back(k + 1, m + 1);
                                return true;
                            }
                        }
                        k++;
                        m++;
                    }
                    k = i - 1;
                    m = j - 1;
                    while (k > 0 && m > 0) {
                        if (board.IsPlayerChecker(position[k][m], player2.GetColor())) {
                            if (position[k - 1][m - 1] == 0) {
                                PosStart.emplace_back(i, j);
                                PosEnemy.emplace_back(k, m);
                                PosFinish.emplace_back(k - 1, m - 1);
                                return true;
                            }
                        }
                        k--;
                        m--;
                    }
                    k = i - 1;
                    m = j + 1;
                    while (k > 0 && m < 8) {
                        if (board.IsPlayerChecker(position[k][m], player2.GetColor())) {
                            if (position[k - 1][m + 1] == 0) {
                                PosStart.emplace_back(i, j);
                                PosEnemy.emplace_back(k, m);
                                PosFinish.emplace_back(k - 1, m + 1);
                                return true;
                            }
                        }
                        k--;
                        m++;
                    }
                    k = i + 1;
                    m = j - 1;
                    while (k > 0 && m > 0) {
                        if (board.IsPlayerChecker(position[k][m], player2.GetColor())) {
                            if (position[k + 1][m - 1] == 0) {
                                PosStart.emplace_back(i, j);
                                PosEnemy.emplace_back(k, m);
                                PosFinish.emplace_back(k + 1, m - 1);
                                return true;
                            }
                        }
                        k++;
                        m--;
                    }
                }
                else {
                    if (board.IsPlayerChecker(position[i - 1][j - 1], player2.GetColor())) {
                        if (position[i - 2][j - 2] == 0) {
                            PosStart.emplace_back(i, j);
                            PosEnemy.emplace_back(i - 1, j - 1);
                            PosFinish.emplace_back(i - 2, j - 2);
                            return true;
                        }
                    }
                    if (board.IsPlayerChecker(position[i - 1][j + 1], player2.GetColor())) {
                        if (position[i - 2][j + 2] == 0) {
                            PosStart.emplace_back(i, j);
                            PosEnemy.emplace_back(i - 1, j + 1);
                            PosFinish.emplace_back(i - 2, j + 2);
                            return true;
                        }
                    }
                    if (board.IsPlayerChecker(position[i + 1][j - 1], player2.GetColor())) {
                        if (position[i + 2][j - 2] == 0) {
                            PosStart.emplace_back(i, j);
                            PosEnemy.emplace_back(i + 1, j - 1);
                            PosFinish.emplace_back(i + 2, j - 2);
                            return true;
                        }
                    }
                    if (board.IsPlayerChecker(position[i + 1][j + 1], player2.GetColor())) {
                        if (position[i + 2][j + 2] == 0) {
                            PosStart.emplace_back(i, j);
                            PosEnemy.emplace_back(i + 1, j + 1);
                            PosFinish.emplace_back(i + 2, j + 2);
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool IsCheckerQueen(int (& position)[8][8],const Player& player,vector<pair<int,int>>& QueenField,Board board,vector<int>& QueenPos){
    for (auto & i : QueenField) {
        for (int k=0;k<8;k++) {
            for (int m=0;m<8;m++) {
                if (k == i.first && m == i.second){
                    if (board.IsPlayerChecker(position[k][m],player.GetColor())){
                        cout << k << " "<<m<<endl;
                        QueenPos.push_back(k);
                        QueenPos.push_back(m);
                        return true;
                    }
                }
            }
        }
    }
    return false;
};
void Game::game(Player player11,Player player22,Board board1) {
    cout << "Checkers" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (((black << 4) | white)));
    Player player1 = std::move(player11);
    Player player2 = std::move(player22);
    WhoIsFirst(player1, player2);
    Board board = board1;
    int position[8][8] = {{6, 2, 6, 2, 6, 2, 6, 2},
                          {2, 6, 2, 6, 2, 6, 2, 6},
                          {6, 2, 6, 2, 6, 2, 6, 2},
                          {0, 6, 0, 6, 0, 6, 0, 6},
                          {6, 0, 6, 0, 6, 0, 6, 0},
                          {1, 6, 1, 6, 1, 6, 1, 6},
                          {6, 1, 6, 1, 6, 1, 6, 1},
                          {1, 6, 1, 6, 1, 6, 1, 6}};
    vector<pair<int,int>> PosStart;
    vector<pair<int,int>> PosEnemy;
    vector<pair<int,int>> PosFinish;

    vector<pair<int,int>> QueenPosStart;
    vector<pair<int,int>> QueenPosEnemy;
    vector<pair<int,int>> QueenPosFinish;

    vector<pair<int,int>> WhiteQueenField={{0,1},{0,3},{0,5},{0,7}};
    vector<pair<int,int>> BlackQueenField={{7,0},{7,2},{7,4},{7,6}};
    vector<int> QueenPos;
    board.PrintBoard(position);

    while (player1.GetCountCheckers() != 0 || player2.GetCountCheckers() != 0) {
        if (player1.GetMyChop()) { // ход первого
            cout << "Move " << player1.GetName() << endl;
            if (CanChop(position, player1, player2, board, PosStart, PosEnemy, PosFinish)) {
                bool flag1 = true;
                while (flag1) {
                    std::pair pos = move();
                    int x1 = pos.first;
                    int y1 = pos.second;
                    std::pair pos1 = move();
                    int x2 = pos1.first;
                    int y2 = pos1.second;
                    cout << " CanChop "<< endl;
                    for (int i=0;i<PosStart.size();i++) {
                        if (PosStart[i].first == x1 && PosStart[i].second == y1 && PosFinish[i].first == x2 && PosFinish[i].second == y2) {
                            player1.SetMyChop(false);
                            board.Move(position, x1, y1, x2, y2);
                            player2.count_checkers--;
                            player2.SetMyChop(true);
                            position[PosEnemy[i].first][PosEnemy[i].second] = 0;
                            PosStart.erase(PosStart.begin() + i);
                            PosEnemy.erase(PosEnemy.begin() + i);
                            PosFinish.erase(PosFinish.begin() + i);
                            flag1 = false;
                        }
                    }
                }

            }
            else {

                bool flag = true;
                while (flag) {
                    std::pair pos = move();
                    int x1 = pos.first;
                    int y1 = pos.second;
                    std::pair pos1 = move();
                    int x2 = pos1.first;
                    int y2 = pos1.second;
                    if (board.IsPlayerChecker(position[x1][y1], player1.GetColor())) { //
                        player1.SetMyChop(false);
                        board.Move(position, x1, y1, x2, y2);
                        player2.SetMyChop(true);
                        flag = false;
                    } else {
                        cout << ErrorMove1() << endl;
                    }
                }
                //continue;
            }
            if (IsCheckerQueen(position,player1,WhiteQueenField,board,QueenPos)) {
                position[QueenPos[0]][QueenPos[1]]=3;
                QueenPos.clear();
            }
            board.PrintBoard(position);
        } else {
            cout << "Move " <<player2.GetName() << endl;
            if (CanChop(position,player2,player1,board,PosStart, PosEnemy, PosFinish)) {
                bool flag1 = true;
                while (flag1) {
                    std::pair pos = move();
                    int x1 = pos.first;
                    int y1 = pos.second;
                    std::pair pos1 = move();
                    int x2 = pos1.first;
                    int y2 = pos1.second;
                    for (int i=0;i<PosStart.size();i++) {
                        if (PosStart[i].first == x1 && PosStart[i].second == y1 && PosFinish[i].first == x2 && PosFinish[i].second == y2) {
                            player2.SetMyChop(false);
                            board.Move(position, x1, y1, x2, y2);
                            player1.SetMyChop(true);
                            position[PosEnemy[i].first][PosEnemy[i].second] = 0;
                            player1.count_checkers--;
                            PosStart.erase(PosStart.begin() + i);
                            PosEnemy.erase(PosEnemy.begin() + i);
                            PosFinish.erase(PosFinish.begin() + i);
                            flag1 = false;
                        }
                    }
                    YouCanChop();
                }
            }
            else {
                bool flag = true;
                while (flag) {
                    std::pair pos = move();
                    int x1 = pos.first;
                    int y1 = pos.second;
                    std::pair pos1 = move();
                    int x2 = pos1.first;
                    int y2 = pos1.second;
                    if (board.IsPlayerChecker(position[x1][y1], player2.GetColor())) {
                        player2.SetMyChop(false); // ход второго
                        board.Move(position, x1, y1, x2, y2);
                        player1.SetMyChop(true);
                        flag = false;
                    } else {
                        cout << ErrorMove1() << endl;
                    }
                }
            }
            if (IsCheckerQueen(position,player2,BlackQueenField,board,QueenPos)) {
                position[QueenPos[0]][QueenPos[1]]=4;
                QueenPos.clear();
            }
            board.PrintBoard(position);
        }
    }
}
