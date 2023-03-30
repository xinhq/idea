#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>

using namespace std;

const int width = 50;
const int height = 20;

int score = 0;

int x = 10, y = height - 2;
int obstacleX = width - 1, obstacleY;
int coinX = width - 1, coinY;

bool gameOver = false;

void setup()
{
    srand(time(NULL));
    obstacleY = rand() % height + 1;
    coinY = rand() % height + 1;
}

void draw()
{
    system("cls");
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                cout << "#";
            }
            else if (i == y && j == x)
            {
                cout << "^_@_^";
                j += 5;
            }
            else if (i == obstacleY && j == obstacleX)
            {
                cout << "|||";
            }
            else if (i == coinY && j == coinX)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << "Score: " << score << endl;
}

void input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'w':
            y--;
            break;
        case 's':
            y++;
            break;
        }
    }
}

void logic()
{
    if (obstacleX == 1)
    {
        obstacleX = width - 1;
        obstacleY = rand() % height + 1;
        score++;
    }
    if (coinX == 1)
    {
        coinX = width - 1;
        coinY = rand() % height + 1;
        score += 5;
    }
    if (x == obstacleX && y == obstacleY)
    {
        gameOver = true;
    }
    if (x == coinX && y == coinY)
    {
        score += 10;
        coinX = width - 1;
        coinY = rand() % height + 1;
    }
    obstacleX--;
    coinX--;
}

int main()
{
    setup();

    while (!gameOver)
    {
        draw();
        input();
        logic();
        Sleep(50);
    }

    system("cls");
    cout << "Game Over!" << endl;
    cout << "Your score is: " << score << endl;

    return 0;
}
