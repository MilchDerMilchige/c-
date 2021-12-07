#include <iostream>
#include <conio.h>
#include <dos.h>
#include <windows.h>
#include <time.h>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y){
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}

int main()
{
    int px = 24;
    int py = 24;

    int x = 11;
    int y = 11;

    int basex = 13;
    int basey = 13;
    cout << "Hello player!" << endl;
    char input;
    while (true) {
        input = getch();
        system("cls");
        if(input == 'a') {
            px--;
        }
        if(input == 'd') {
            px++;
        }
        if(input == 's') {
            py++;
        }
        if(input == 'w') {
            py--;
        }
        if(input == 'A') {
            px-=2;
        }
        if(input == 'D') {
            px+=2;
        }
        if(input == 'S') {
            py-=2;
        }
        if(input == 'W') {
            py+=2;
        }
        if(x<px){
            x++;
        }
        if(x>px){
            x--;
        }
        if(y<py){
            y++;
        }
        if(y>py){
            y--;
        }

        gotoxy(px,py);
        cout << "ß";
        gotoxy(px-1,py);
        cout << "ß";
        gotoxy(px+1,py);
        cout << "ß";
        gotoxy(px-1,py+1);
        cout << "ß";
        gotoxy(px+1,py+1);
        cout << "ß";
        gotoxy(px,py-1);
        cout << "ß";
        gotoxy(px,py);
        gotoxy(x,y);
        cout << "#";
        gotoxy(basex,basey);
        cout << "b";
        gotoxy(px,py);
        if(x==px){
            if(y==py){
                return 0;
            }
        }
        if(basex==px){
            if(basey==py){
                gotoxy(0,0);
                cout << "game over!\n you won!";
                system("pause");
                return 1;
            }
        }
    }
    return 0;
}
