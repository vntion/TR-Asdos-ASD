#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>

using namespace std;

WORD original = 0;

// Line and bar characters
const int lineh = 205, linev = 186;
const int corner1 = 201, corner2 = 187, corner3 = 200, corner4 = 188;
const int bar1 = 177, bar2 = 219;

// Function to set console text color
void SetConsoleColour(WORD* original, DWORD Colour) {
    CONSOLE_SCREEN_BUFFER_INFO Info;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdout, &Info);
    *original = Info.wAttributes;
    SetConsoleTextAttribute(hStdout, Colour);
}

// Function to reset console text color to original
void ResetConsoleColour(WORD original) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), original);
}


void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void loading() {
    system("cls");
    WORD original = 0;
    SetConsoleColour(&original, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
    SetConsoleCP(437);
    SetConsoleOutputCP(437);

    gotoxy(65, 15);
    cout << "Loading...";

    for (int i = 65; i <= 95; i++) {
        gotoxy(i, 16);
        cout << (char)bar1;
    }

    for (int i = 0; i <= 100; i++) {
        gotoxy(77, 18);
        cout << "[" << i << "%]";

        int progress = i * (95 - 65) / 100 + 65;

        for (int j = 65; j <= progress; j++) {
            gotoxy(j, 16);
            cout << (char)bar2;
        }

        Sleep(10);
    }
}


void success() {
    system("cls");
    WORD original = 0;
    SetConsoleColour(&original, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | FOREGROUND_BLUE);
    SetConsoleCP(437);
    SetConsoleOutputCP(437);

    for (int i = 65; i <= 95; i++) {
        gotoxy(i, 16);
        cout << (char)bar2;
    }
    gotoxy(71, 18);
    cout << "[ SUCCESS TO LOGIN ]";
    getch();
    ResetConsoleColour(original);
}

void failed() {
    system("cls");
    WORD original = 0;
    SetConsoleColour(&original, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | FOREGROUND_RED);
    SetConsoleCP(437);
    SetConsoleOutputCP(437);

    for (int i = 65; i <= 95; i++) {
        gotoxy(i, 16);
        cout << (char)bar2;
    }
    gotoxy(72, 18);
    cout << "[ FAIL TO LOGIN ]";
    getch();
    ResetConsoleColour(original);
}


void login() {
    WORD original = 0;
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    string uname, pw;
    const string correctuser = "aaa";
    const string correctpw = "aaa";
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleColour(&original, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);

    do {
        system("cls");
        SetConsoleTextAttribute(color, 8);
        
        SetConsoleColour(&original, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);

        for (int i = 0; i <= 161; i++) {
            gotoxy(i, 0);
            cout << (char)lineh;
        }
        for (int i = 0; i <= 161; i++) {
            gotoxy(i, 10);
            cout << (char)lineh;
        }
        for (int i = 0; i <= 161; i++) {
            gotoxy(i, 35);
            cout << (char)lineh;
        }

        // Drawing login box
        gotoxy(54, 13);
        cout << (char)corner1;
        gotoxy(96, 13);
        cout << (char)corner2;
        for (int i = 55; i <= 95; i++) {
            gotoxy(i, 13);
            cout << (char)lineh;
        }
        for (int i = 14; i <= 22; i++) {
            gotoxy(54, i);
            cout << (char)linev;
        }
        for (int i = 14; i <= 22; i++) {
            gotoxy(96, i);
            cout << (char)linev;
        }
        for (int i = 55; i <= 95; i++) {
            gotoxy(i, 23);
            cout << (char)lineh;
        }
        gotoxy(54, 23);
        cout << (char)corner3;
        gotoxy(96, 23);
        cout << (char)corner4;

        // Login prompt
        gotoxy(60, 17);
        cout << "Username: ";
        cin >> uname;
        gotoxy(60, 19);
        cout << "Password: ";
        char ch;
        pw = "";
        while (true) {
            ch = _getch();
            if (ch == 13)  
                break;
            else if (ch == 8) {  
                if (!pw.empty()) {
                    pw.pop_back();
                    cout << "\b \b";  
                }
            } else {
                pw += ch;
                cout << '*';
            }
        }

        if (uname == correctuser && pw == correctpw) {
            loading();
            success();
            getch();
        } else {
            loading();
            failed();
            getch();
        }

    } while (uname != correctuser || pw != correctpw);
}


int main() {
    login();
    return 0;
}
