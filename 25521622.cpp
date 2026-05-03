// Nguyen Tan Tai
// Chuc nang: Chinh sua giao dien (UI)
//
// - Dieu chinh cach hien thi board trong console
// - Su dung moi o 2 ky tu de dam bao block hien thi vuong (khong con HCN)
// - Cai tien vien bang ky tu "[]" de ro rang hon
//
// LUU Y:
// - File nay chi dung de test giao dien
// - Khi merge vao file FINAL, chi can copy ham draw() de thay the draw cu
// - Khong can su dung cac phan khac trong file nay
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

#define H 20
#define W 15

char board[H][W];

// Block mau (test UI)
char blocks[1][4][4] = {
    {
        {' ','O','O',' '},
        {' ','O','O',' '},
        {' ',' ',' ',' '},
        {' ',' ',' ',' '}
    }
};

int x = 5, y = 5;

void gotoxy(int x, int y) {
    COORD c = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void initBoard(){
    for (int i = 0 ; i < H ; i++)
        for (int j = 0 ; j < W ; j++)
            if (i == H-1 || j == 0 || j == W-1)
                board[i][j] = '#';
            else
                board[i][j] = ' ';
}

void draw(){
    gotoxy(0,0);
    for (int i = 0 ; i < H ; i++){
        for (int j = 0 ; j < W ; j++){
            if (board[i][j] == '#'){
                cout << "[]";   // viền
            }
            else if (board[i][j] == ' '){
                cout << "  ";   // ô trống
            }
            else{
                cout << "██";   // block vuông
            }
        }
        cout << endl;
    }
}

void block2Board(){
    for (int i = 0 ; i < 4 ; i++)
        for (int j = 0 ; j < 4 ; j++)
            if (blocks[0][i][j] != ' ')
                board[y+i][x+j] = blocks[0][i][j];
}

int main(){
    system("cls");
    initBoard();

    while (1){
        block2Board();
        draw();
        Sleep(200);
    }
}
