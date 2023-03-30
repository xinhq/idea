#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>

using namespace std;

const int width = 30;
const int height = 20;

const char player[] = "^^_@_^^";
const char ground = '_';

class Game {
public:
    void Draw() {
        system("cls");
        for (int i = 0; i < width + 2; i++)
            cout << "#";
        cout << endl;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (j == 0)
                    cout << "|";
                if (i == y && j == x)
                    cout << player;
                else if (i == height - 1)
                    cout << ground;
                else
                    cout << " ";
                if (j == width - 1)
                    cout << "|";
            }
            cout << endl;
        }

        for (int i = 0; i < width + 2; i++)
            cout << "#";
        cout << endl;
    }

    void Input() {
        if (_kbhit()) {
            switch (_getch()) {
            case 'a':
                dx = -1;
                break;
            case 'd':
                dx = 1;
                break;
            case 'w':
                dy = -1;
                break;
            case 's':
                dy = 1;
                break;
            case 'x':
                gameOver = true;
                break;
            }
        }
    }

    void Logic() {
        x += dx;
        y += dy;

        if (x > width - 1)
            x = 0;
        else if (x < 0)
            x = width - 1;

        if (y > height - 1)
            y = height - 1;
        else if (y < 0)
            y = 0;

        if (y == height - 1)
            gameOver = true;
    }

    void Run() {
        while (!gameOver) {
            Draw();
            Input();
            Logic();
            Sleep(50);
        }
    }

private:
    bool gameOver = false;
    int x = width / 2;
    int y = height / 2;
    int dx = 0;
    int dy = 0;
};

int main() {
    Game game;
    game.Run();
    return 0;
}
