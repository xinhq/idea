#include <iostream>
#include <string>
using namespace std;

void dialog() {
    string question;
    while (true) {
        cout << "���������⣺" << endl;
        getline(cin, question);
        if (question == "�˳�") {
            break;
        }
        else if (question == "�л�") {
            return;
        }
        else if (question == "���") {
            cout << "��ð���" << endl;
        }
        else if (question.find("���ʲô����") != string::npos) {
            cout << "�ҵĿ����߸���ȡ��Ϊ���˹�����1.0������������Գƺ���Ϊ��С�ϡ�" << endl;
        }
        else if (question.find("��ϲ��ʲô") != string::npos) {
            cout << "����һ̨���ԣ�û��ϲ����ϲ���ġ�" << endl;
        }
        else if (question.find("���") != string::npos) {
            int start = question.find("���") + 2;
            int end = question.size() - 2;
            string skill = question.substr(start, end - start);
            cout << "��" << skill << "!" << endl;
        }
        else {
            cout << "��Ǹ��������������˵ʲô��" << endl;
        }
    }
}

void draw() {
    string animal;
    cout << "�һ���ƣ������ܡ�������ɽ��������¹" << endl;
    cout << "����������Ҫ���ƵĶ��" << endl;
    while (true) {
        
        getline(cin, animal);
        if (animal == "�˳�") {
            break;
        }
        else if (animal == "�л�") {
            return;
        }
        else if (animal == "��") {
            cout << "^__^" << endl;
            cout << "(oo)\\_______" << endl;
            cout << "(__)\\       )\\/\\" << endl;
            cout << "     ||----w |" << endl;
            cout << "     ||     ||" << endl;
        }
        else if (animal == "����") {
            cout << "  oO)-.                       .-(Oo" << endl;
            cout << " /__  _\\                     /_  __\\" << endl;
            cout << " \\\\  \\(  |     ()~()         |  )/  /" << endl;
            cout << "  \\\\__|\\ |    (-___-)        | /|__/" << endl;
            cout << "  '  '--'    ==`-'==        '--'  '" << endl;
        }
        else if (animal == "����") {
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
        else if (animal == "ɽ��") {
            cout << " U    U" << endl;
            cout << "   __" << endl;
            cout << "  UooU\\.'@@@@@@`." << endl;
            cout << " \\__/(@@@@@@@@@@)" << endl;
            cout << "       (@@@@@@@@)" << endl;
            cout << "       `YY~~~~YY'" << endl;
            cout << "        ||    ||" << endl;
        }
        else if (animal == "��") {
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
        else if (animal == "��¹") {
            cout << " \\   \\_\\_    _/_/" << endl;
            cout << "  \\__   \\__/" << endl;
            cout << "      (oo)\'_______" << endl;
            cout << "           (__)\\    )\\/\\" << endl;
            cout << "           ||----w |" << endl;
            cout << "           ||     ||" << endl;
        }
        else {
            cout << "��Ǹ���Ҳ���������ֶ��" << endl;
        }
    }
}

int main() {
    string option;
    while (true) {
        cout << "��ѡ���ܣ����롰�Ի����򡰻滭�������롰�˳�����������" << endl;
        getline(cin, option);
        if (option == "�˳�") {
            break;
        }
        else if (option == "�Ի�") {
            dialog();
        }
        else if (option == "�滭") {
            draw();
        }
        else {
            cout << "��Ǹ���Ҳ��������ѡ��" << endl;
        }
    }
    return 0;
}
