#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include<iostream>
#include<unistd.h>

using namespace std;


// 定义蛇头和食物的坐标
int snakeX[500], snakeY[500], foodX, foodY;


// 定义蛇的初始长度和方向
int snakeLength = 5, direction = 1;


// 定义游戏是否结束
bool isOver = false;


// 初始化游戏
void init() {
    // 初始化随机数种子
    srand(time(0));
    // 随机生成食物位置
    foodX = rand() % 20 + 1;
    foodY = rand() % 20 + 1;
    // 初始化蛇的位置
    for (int i = 0; i < snakeLength; i++) {
        snakeX[i] = 10 - i;
        snakeY[i] = 10;
    }
}


// 绘制游戏界面
void draw() {
    system("cls"); // 清屏操作
    // 绘制上边界
    for (int i = 0; i < 22; i++)
        cout << "#";
    cout << endl;
    // 绘制游戏区域
    for (int i = 0; i < 20; i++) {
        cout << "#";
        for (int j = 0; j < 20; j++) {
            bool isBody = false;
            // 判断当前位置是否蛇的身体
            for (int k = 0; k < snakeLength; k++) {
                if (snakeX[k] == j && snakeY[k] == i) {
                    cout << "*";
                    isBody = true;
                    break;
                }
            }
            // 如果不是蛇的身体，则判断是否是食物
            if (!isBody && foodX == j && foodY == i)
                cout << "+";
            else if (!isBody)
                cout << " ";
        }
        cout << "#" << endl;
    }
    // 绘制下边界
    for (int i = 0; i < 22; i++)
        cout << "#";
    cout << endl;
}

// 处理用户输入
void input() {
    // 如果有按键输入，则改变方向
    if (_kbhit()) {
        switch (_getch()) {
        case 'w': direction = 1; break; // 上
        case 's': direction = 2; break; // 下
        case 'a': direction = 3; break; // 左
        case 'd': direction = 4; break; // 右
        case 'x': isOver = true; break; // 退出游戏
        }
    }
}


// 更新游戏状态
void update() {
    // 更新蛇的位置
    for (int i = snakeLength - 1; i > 0; i--) {
        snakeX[i] = snakeX[i - 1];
        snakeY[i] = snakeY[i - 1];
    }
    switch (direction) {
    case 1: snakeY[0]--; break; // 上
    case 2: snakeY[0]++; break; // 下
    case 3: snakeX[0]--; break; // 左
    case 4: snakeX[0]++; break; // 右
    }
    // 判断蛇是否撞到边界
    if (snakeX[0] < 0 || snakeX[0] >= 20 || snakeY[0] < 0 || snakeY[0] >= 20)
        isOver = true;
    // 判断蛇是否吃到食物
    if (snakeX[0] == foodX && snakeY[0] == foodY) {
        snakeLength++;
        // 随机生成新的食物位置
        foodX = rand() % 20 + 1;
        foodY = rand() % 20 + 1;
    }
    // 判断蛇是否撞到自己
    for (int i = 1; i < snakeLength; i++) {
        if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i])
            isOver = true;
    }
}


int main() {
    init(); // 初始化游戏
    while (!isOver) { // 游戏主循环
        draw(); // 绘制游戏界面
        input(); // 处理用户输入
        update(); // 更新游戏状态
        // 延时，控制游戏速度
        // 每次循环休眠100毫秒
        usleep(100000);
    }
    // 游戏结束，输出分数并退出
    cout << "Game over! Your score is " << snakeLength - 5 << endl;
    return 0;
}