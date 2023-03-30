//输入一组学生信息，包学号、姓名、年龄
//程序将按照年龄进行排序，如果年龄相等，则按照姓名首字母依次进行排序（第一个首字母相同，则按照第二个排序……以此类推）

#include<iostream>
#include<iomanip>
using namespace std;

struct student
{
    int number;
    char name[6];
    int year;
};

int main()
{
    int n;
    student stu[50], stut;

    cin >> n;
    
    //输入学生信息
    for (int i = 0; i < n; i ++){
        cin >> stu[i].number;
        cin >> stu[i].name;
        cin >> stu[i].year;
    }

    //按姓名排序
    for (int i = 0; i < n-1; i ++){
        for (int j = 0; j < n - 1; j ++){
            //比较首字母
            if (int(stu[j].name[0]) > int(stu[j+1].name[0])){
                stut = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = stut;
            }
            //比较之后的字母
            if (int(stu[j].name[0]) == int(stu[j+1].name[0])){
                for (int k = 1; stu[j].name[k] != 0; k++){
                if (int(stu[j].name[0]) > int(stu[j+1].name[0])){
                    stut = stu[j];
                    stu[j] = stu[j + 1];
                    stu[j + 1] = stut;
                    break;
                }
            }
        }
    }
}  
            //按姓名输出
            for (int i = 0; i < n; i ++){
        cout << right << setw(3) << stu[i].number << right << setw(6) << stu[i].name << right << setw(3) << stu[i].year <<endl;
    }

    cout << endl;

    //按年龄排序
    for (int i = 0; i < n-1; i ++){
        for (int j = 0; j < n - 1; j ++){
            if (stu[j].year > stu[j + 1].year){
                stut = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = stut;
            }
            //如果年龄相等，按姓名排序
            if (stu[j].year == stu[j + 1].year)
            {for (int j = 0; j < n - 1; j ++){
            //比较首字母
            if (int(stu[j].name[0]) > int(stu[j+1].name[0])){
                stut = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = stut;
            }
            //比较之后的字母
            if (int(stu[j].name[0]) == int(stu[j+1].name[0])){
                for (int k = 1; stu[j].name[k] != 0; k++){
                if (int(stu[j].name[0]) > int(stu[j+1].name[0])){
                    stut = stu[j];
                    stu[j] = stu[j + 1];
                    stu[j + 1] = stut;
                    break;
                }
            }
        }
            }}
    }
    }
    //按年龄输出
    for (int i = 0; i < n; i ++){
        cout << right << setw(3) << stu[i].number << right << setw(6) << stu[i].name << right << setw(3) << stu[i].year <<endl;
    }

    //system("pause");

    return 0;
}