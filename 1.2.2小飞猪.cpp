#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
using namespace std;

const int width = 40;
const int height = 20;
const int obstacle_num = 10;
const int coin_num = 5;
int x, y;
int obstacle_pos[obstacle_num];
int coin_pos[coin_num];

void draw() {
    system("cls");
    for (int i = 0; i < width; i++)
        cout << "-";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1) {
                cout << "|";
            } else if (i == y && j == x) {
                cout << "^^__@__^^";
                j += 8;
            } else {
                bool print_coin = false;
                for (int k = 0; k < coin_num; k++) {
                    if (coin_pos[k] == j && i == height - 2) {
                        cout << "$";
                        print_coin = true;
                        break;
                    }
                }
                if (print_coin)
                    continue;

                bool print_obstacle = false;
                for (int k = 0; k < obstacle_num; k++) {
                    if (obstacle_pos[k] == j && i == height - 3) {
                        cout << "####";
                        print_obstacle = true;
                        break;
                    }
                }
                if (print_obstacle)
                    continue;

                cout << " ";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width; i++)
        cout << "-";
    cout << endl;
}

void input() {
    if (_kbhit()) {
        char current = _getch();
        if (current == 'a')
            x--;
        if (current == 'd')
            x++;
        if (current == 'w')
            y--;
        if (current == 's')
            y++;
    }
}

void logic() {
    for (int i = 0; i < obstacle_num; i++) {
        if (obstacle_pos[i] == x && height - 3 == y) {
            cout << "Game Over!" << endl;
            exit(0);
        }
    }

    for (int i = 0; i < coin_num; i++) {
        if (coin_pos[i] == x && height - 2 == y) {
            coin_pos[i] = -1;
        }
    }
}

int main() {
    srand(time(NULL));
    x = width / 2;
    y = height - 2;

    for (int i = 0; i < obstacle_num; i++)
        obstacle_pos[i] = rand() % (width - 2) + 1;

    for (int i = 0; i < coin_num; i++)
        coin_pos[i] = rand() % (width - 2) + 1;

    while (true) {
        draw();
        input();
        logic();
        Sleep(50);
    }

    return 0;
}
