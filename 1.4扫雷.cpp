#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;
// 定义常量
const int BOARD_SIZE = 10; // 棋盘大小
const int MINE_NUM = 10; // 地雷数量
// 定义棋盘格子的状态
enum CellStatus {
    COVERED, // 未翻开
    UNCOVERED, // 已翻开
    FLAGGED, // 已标记
};
// 定义棋盘格子的结构体
struct Cell {
    bool hasMine; // 是否有地雷
    int adjacentMines; // 相邻地雷数量
    CellStatus status; // 状态
};
// 初始化棋盘
void initBoard(vector<vector<Cell>>& board) {
    // 随机生成地雷
    srand(time(NULL));
    int count = 0;
    while (count < MINE_NUM) {
        int x = rand() % BOARD_SIZE;
        int y = rand() % BOARD_SIZE;
        if (!board[x][y].hasMine) {
            board[x][y].hasMine = true;
            count++;
        }
    }
    // 计算每个格子相邻地雷数量
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!board[i][j].hasMine) {
                int count = 0;
                for (int ii = max(0, i - 1); ii <= min(i + 1, BOARD_SIZE - 1); ii++) {
                    for (int jj = max(0, j - 1); jj <= min(j + 1, BOARD_SIZE - 1); jj++) {
                        if (board[ii][jj].hasMine) {
                            count++;
                        }
                    }
                }
                board[i][j].adjacentMines = count;
            }
        }
    }
}
// 显示棋盘
void showBoard(vector<vector<Cell>>& board) {
    cout << "  ";
    for (int j = 0; j < BOARD_SIZE; j++) {
        cout << j << " ";
    }
    cout << endl;
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << i << " ";
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].status == COVERED) {
                cout << "* ";
            } else if (board[i][j].status == FLAGGED) {
                cout << "F ";
            } else if (board[i][j].hasMine) {
                cout << "X ";
            } else if (board[i][j].adjacentMines == 0) {
                cout << ". ";
            } else {
                cout << board[i][j].adjacentMines << " ";
            }
        }
        cout << endl;
    }
}
// 翻开一个格子
void uncoverCell(vector<vector<Cell>>& board, int x, int y) {
    if (board[x][y].status == UNCOVERED) {
        return;
    }
    board[x][y].status = UNCOVERED;
    if (board[x][y].hasMine) {
        cout << "You lose!" << endl;
        exit(0);
    }
    if (board[x][y].adjacentMines == 0) {
        for (int i = max(0, x - 1); i <= min(x + 1, BOARD_SIZE - 1); i++) {
            for (int j = max(0, y - 1); j <= min(y + 1, BOARD_SIZE - 1); j++) {
                if (i != x || j != y) {
                    uncoverCell(board, i, j);
                }
            }
        }
    }
}
// 标记一个格子
void flagCell(vector<vector<Cell>>& board, int x, int y) {
    if (board[x][y].status == COVERED) {
        board[x][y].status = FLAGGED;
    } else if (board[x][y].status == FLAGGED) {
        board[x][y].status = COVERED;
    }
}
int main() {
    vector<vector<Cell>> board(BOARD_SIZE, vector<Cell>(BOARD_SIZE));
    initBoard(board);
    while (true) {
        showBoard(board);
        int x, y;
        cout << "Enter the row and column (e.g. 0 1) or q to quit: ";
        string input;
        getline(cin, input);
        if (input == "q") {
            break;
        }
        sscanf(input.c_str(), "%d %d", &x, &y);
        if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
            cout << "Invalid input!" << endl;
            continue;
        }
        string action;
        cout << "Enter u to uncover, f to flag or u+f to uncover and flag: ";
        getline(cin, action);
        if (action == "u") {
            uncoverCell(board, x, y);
        } else if (action == "f") {
            flagCell(board, x, y);
        } else if (action == "u+f") {
            flagCell(board, x, y);
            uncoverCell(board, x, y);
        } else {
            cout << "Invalid input!" << endl;
            continue;
        }
        bool win = true;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j].status == COVERED && !board[i][j].hasMine) {
                    win = false;
                    break;
                }
            }
            if (!win) {
                break;
            }
        }
        if (win) {
            cout << "You win!" << endl;
            break;
        }
    }
    return 0;
}