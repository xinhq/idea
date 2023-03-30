#include <iostream>
using namespace std;
const int ROW = 3;
const int COL = 3;
// 初始化棋盘
void InitBoard(char board[][COL], int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            board[i][j] = ' ';
        }
    }
}
// 打印棋盘
void DisplayBoard(char board[][COL], int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            cout << board[i][j] << "|";
        }
        cout << endl;
        for (int j = 0; j < col; ++j)
        {
            cout << "-|";
        }
        cout << endl;
    }
}
// 判断是否下满棋盘
bool IsFull(char board[][COL], int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}
// 判断是否有玩家获胜
char IsWin(char board[][COL], int row, int col)
{
    // 判断行
    for (int i = 0; i < row; ++i)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            return board[i][0];
        }
    }
    // 判断列
    for (int j = 0; j < col; ++j)
    {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
        {
            return board[0][j];
        }
    }
    // 判断对角线
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
    {
        return board[0][2];
    }
    // 没有获胜者
    return ' ';
}
int main()
{
    char board[ROW][COL];
    char player1 = 'X';
    char player2 = 'O';
    char currentPlayer = player1;
    InitBoard(board, ROW, COL);
    DisplayBoard(board, ROW, COL);
    // 游戏主循环
    while (1)
    {
        // 玩家下棋
        int x, y;
        cout << "Player " << currentPlayer << "'s turn. Please enter the coordinate(x,y): ";
        cin >> x >> y;
        if (x < 0 || x >= ROW || y < 0 || y >= COL || board[x][y] != ' ')
        {
            cout << "Invalid input! Please enter again." << endl;
            continue;
        }
        board[x][y] = currentPlayer;
        DisplayBoard(board, ROW, COL);
        // 判断是否有获胜者或下满棋盘
        char result = IsWin(board, ROW, COL);
        if (result != ' ')
        {
            cout << "Player " << result << " wins!" << endl;
            break;
        }
        if (IsFull(board, ROW, COL))
        {
            cout << "The board is full! It's a tie!" << endl;
            break;
        }
        // 切换下棋玩家
        if (currentPlayer == player1)
        {
            currentPlayer = player2;
        }
        else
        {
            currentPlayer = player1;
        }
    }
    return 0;
}