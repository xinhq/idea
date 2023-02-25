#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
using namespace std;

const int width = 40;
const int height = 20;
int playerPos = height - 1;
int score = 0;

void showScore() {
    cout << "Score: " << score << endl;
}

void showGameBoard(string gameBoard[]) {
    system("cls");
    showScore();
    for (int i = 0; i < height; i++) {
        cout << gameBoard[i] << endl;
    }
}

int main() {
    string gameBoard[height];
    srand(time(NULL));
    for (int i = 0; i < height; i++) {
        gameBoard[i] = "";
        for (int j = 0; j < width; j++) {
            if (i == playerPos && j == 0) {
                gameBoard[i] += "^^__@__^^";
            }
            else if (rand() % 5 == 0 && j > 5 && j < width - 5) {
                gameBoard[i] += "$";
            }
            else if (rand() % 5 == 0 && j > 5 && j < width - 5) {
                gameBoard[i] += "#";
            }
            else {
                gameBoard[i] += " ";
            }
        }
    }
    showGameBoard(gameBoard);

    while (true) {
        if (_kbhit()) {
            char c = _getch();
            if (c == 'w' && playerPos > 0) {
                playerPos--;
            }
            else if (c == 's' && playerPos < height - 1) {
                playerPos++;
            }
        }

        for (int i = 0; i < height; i++) {
            if (gameBoard[i][1] == '$' && i == playerPos) {
                score++;
                gameBoard[i][1] = ' ';
            }
            else if (gameBoard[i][1] == '#' && i == playerPos) {
                cout << "Game Over!" << endl;
                return 0;
            }

            for (int j = 0; j < width - 1; j++) {
                gameBoard[i][j] = gameBoard[i][j + 1];
            }
        }

        if (rand() % 5 == 0) {
            int row = rand() % height;
            gameBoard[row][width - 1] = '#';
        }

        if (rand() % 5 == 0) {
            int row = rand() % height;
            gameBoard[row][width - 1] = '$';
        }

        showGameBoard(gameBoard);
        Sleep(100);
    }

    return 0;
}
