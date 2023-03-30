#include <iostream>
#include <string>
#include <ctime>
using namespace std;
// 角色类
class Character {
public:
    int hp;         // 血量
    int attack;     // 攻击力
    int defense;    // 防御力
    string name;    // 角色名称
    // 构造函数
    Character(string n, int h = 100, int a = 10, int d = 5) {
        name = n;
        hp = h;
        attack = a;
        defense = d;
    }
    // 攻击方法
    int attackTarget(Character& target) {
        int damage = attack - target.defense;
        if (damage < 0) {
            damage = 0;
        }
        target.hp -= damage;
        cout << name << "攻击" << target.name << "，造成了" << damage << "点伤害。" << endl;
        return damage;
    }
    // 技能方法
    int useSkill(Character& target) {
        int damage = attack * 2 - target.defense;
        if (damage < 0) {
            damage = 0;
        }
        target.hp -= damage;
        cout << name << "使用技能攻击" << target.name << "，造成了" << damage << "点伤害。" << endl;
        return damage;
    }
    // 防御方法
    void defend() {
        defense *= 2;
        cout << name << "进入防御状态，防御力提高了。" << endl;
    }
    // 判断是否死亡
    bool isDead() {
        return hp <= 0;
    }
};
// 游戏类
class Game {
public:
    Character player1;  // 玩家1
    Character player2;  // 玩家2
    int round;          // 当前回合数
    // 构造函数
    Game(string n1, string n2) : player1(n1), player2(n2) {
        round = 1;
    }
    // 初始化角色
    void initCharacters() {
        player1.hp = 100;
        player1.attack = 10;
        player1.defense = 5;
        player2.hp = 100;
        player2.attack = 10;
        player2.defense = 5;
    }
    // 判断是否结束游戏
    bool isGameOver() {
        if (player1.isDead() || player2.isDead() || round > 10) {
            return true;
        }
        return false;
    }
    // 判断胜负
    void checkResult() {
        if (player1.isDead()) {
            cout << player2.name << "获胜！" << endl;
        }
        else if (player2.isDead()) {
            cout << player1.name << "获胜！" << endl;
        }
        else {
            cout << "双方平局！" << endl;
        }
    }
    // 游戏流程
    void play() {
        while (!isGameOver()) {
            // 输出当前回合数
            cout << "第" << round << "回合：" << endl;
            // 玩家1操作
            cout << player1.name << "请出招（1-攻击，2-技能，3-防御）：";
            int choice;
            cin >> choice;
            srand(time(NULL));  // 生成随机数种子
            switch (choice) {
            case 1:
                player1.attackTarget(player2);
                break;
            case 2:
                if (rand() % 2 == 0) {  // 50%概率使用技能
                    player1.useSkill(player2);
                }
                else {
                    cout << player1.name << "使用技能失败！" << endl;
                }
                break;
            case 3:
                player1.defend();
                break;
            default:
                cout << "无效操作！" << endl;
                break;
            }
            // 判断玩家2是否死亡
            if (player2.isDead()) {
                break;
            }
            // 玩家2操作
            cout << player2.name << "请出招（1-攻击，2-技能，3-防御）：";
            cin >> choice;
            switch (choice) {
            case 1:
                player2.attackTarget(player1);
                break;
            case 2:
                if (rand() % 2 == 0) {  // 50%概率使用技能
                    player2.useSkill(player1);
                }
                else {
                    cout << player2.name << "使用技能失败！" << endl;
                }
                break;
            case 3:
                player2.defend();
                break;
            default:
                cout << "无效操作！" << endl;
                break;
            }
            // 判断玩家1是否死亡
            if (player1.isDead()) {
                break;
            }
            // 回合结束，回合数+1
            round++;
        }
        // 输出胜负结果
        checkResult();
    }
};
int main() {
    string name1, name2;
    cout << "请输入玩家1名称：";
    cin >> name1;
    cout << "请输入玩家2名称：";
    cin >> name2;
    Game game(name1, name2);
    game.initCharacters();
    game.play();
    return 0;
}