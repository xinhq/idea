#include <iostream>
#include <string>
using namespace std;

void dialog() {
    string question;
    while (true) {
        cout << "请输入问题：" << endl;
        getline(cin, question);
        if (question == "退出") {
            break;
        }
        else if (question == "切换") {
            return;
        }
        else if (question == "你好") {
            cout << "你好啊！" << endl;
        }
        else if (question.find("你叫什么名字") != string::npos) {
            cout << "我的开发者给我取名为‘人工智障1.0’，所以你可以称呼我为‘小障’" << endl;
        }
        else if (question.find("你喜欢什么") != string::npos) {
            cout << "我是一台电脑，没有喜欢不喜欢的。" << endl;
        }
        else if (question.find("你会") != string::npos) {
            int start = question.find("你会") + 2;
            int end = question.size() - 2;
            string skill = question.substr(start, end - start);
            cout << "我" << skill << "!" << endl;
        }
        else {
            cout << "抱歉，我听不懂你在说什么。" << endl;
        }
    }
}

void draw() {
    string animal;
    cout << "我会绘制：马、青蛙、公鸡、山羊、龙、驼鹿" << endl;
    cout << "请输入您想要绘制的动物：" << endl;
    while (true) {
        
        getline(cin, animal);
        if (animal == "退出") {
            break;
        }
        else if (animal == "切换") {
            return;
        }
        else if (animal == "马") {
            cout << "^__^" << endl;
            cout << "(oo)\\_______" << endl;
            cout << "(__)\\       )\\/\\" << endl;
            cout << "     ||----w |" << endl;
            cout << "     ||     ||" << endl;
        }
        else if (animal == "青蛙") {
            cout << "  oO)-.                       .-(Oo" << endl;
            cout << " /__  _\\                     /_  __\\" << endl;
            cout << " \\\\  \\(  |     ()~()         |  )/  /" << endl;
            cout << "  \\\\__|\\ |    (-___-)        | /|__/" << endl;
            cout << "  '  '--'    ==`-'==        '--'  '" << endl;
        }
        else if (animal == "公鸡") {
            cout << "         \\  /\\/\\" << endl;
            cout << "       \\   /" << endl;
            cout << "       |  0 >>" << endl;
            cout << "       |___|" << endl;
            cout << " __((_<|   |" << endl;
            cout << "(          |" << endl;
            cout << "(__________)" << endl;
            cout << "   |      |" << endl;
            cout << "   |      |" << endl;
            cout << "   /\\     /\\" << endl;
        }
        else if (animal == "山羊") {
            cout << " U    U" << endl;
            cout << "   __" << endl;
            cout << "  UooU\\.'@@@@@@`." << endl;
            cout << " \\__/(@@@@@@@@@@)" << endl;
            cout << "       (@@@@@@@@)" << endl;
            cout << "       `YY~~~~YY'" << endl;
            cout << "        ||    ||" << endl;
        }
        else if (animal == "龙") {
            cout << "           \\                    / \\  //\\" << endl;
            cout << "        \\    |'\\___/|      /   \\//  \\\\" << endl;
            cout << "            /0  0  '\\__  /    //  | \\ \\  " << endl;
            cout << "           /     /  '\\/_/    //   |  \\  \\  " << endl;
            cout << "           @_^_@'/   '\\/_   //    |   \\   \\ " << endl;
            cout << "           //_^_/     '\\/_ //     |    \\    \\" << endl;
            cout << "        ( //) |        '\\///      |     \\     \\" << endl;
            cout << "      ( / /) _|_ /   )  //       |      '\\     _'\\" << endl;
            cout << "    ( // /) '/,_ _ _/  ( ; -.    |    _ _'\\.-~        .-~~~^-." << endl;
            cout << "  (( / / )) ,-{        _      `-.|.-~-.           .~         `." << endl;
            cout << " (( // / ))  '/'\\      /                 ~-. _ .-~      .-~^-.  \\" << endl;
            cout << " (( /// ))      `.   {            }                   /      \\  \\" << endl;
            cout << "  (( / ))     .----~-.\\        \\-'                 .~         \\  `. \\^-." << endl;
            cout << "             ///.----..>        \\             _ -~             `.  ^-`  ^-_" << endl;
            cout << "               ///-._ _ _ _ _ _ _}^ - - - - ~                     ~-- ,.-~" << endl;
            cout << "                                                                  /.-~" << endl;
        }
        else if (animal == "驼鹿") {
            cout << " \\   \\_\\_    _/_/" << endl;
            cout << "  \\__   \\__/" << endl;
            cout << "      (oo)\'_______" << endl;
            cout << "           (__)\\    )\\/\\" << endl;
            cout << "           ||----w |" << endl;
            cout << "           ||     ||" << endl;
        }
        else {
            cout << "抱歉，我不会绘制这种动物。" << endl;
        }
    }
}

int main() {
    string option;
    while (true) {
        cout << "请选择功能（输入“对话”或“绘画”，输入“退出”结束）：" << endl;
        getline(cin, option);
        if (option == "退出") {
            break;
        }
        else if (option == "对话") {
            dialog();
        }
        else if (option == "绘画") {
            draw();
        }
        else {
            cout << "抱歉，我不明白你的选择。" << endl;
        }
    }
    return 0;
}
