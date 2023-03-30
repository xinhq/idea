#include<iostream>
#include<string>
#include<ctime>
using namespace std;

struct Student{
    string Name_1;
    int score;
};

struct Teacher{
    string Name_2;
    struct Student Array_1[5];
};

void allocateSpace(struct Teacher Array_2[],int len){
    string nameSeed="ABCDE";
    for(int i = 0; i < len; i ++)
    {
        Array_2[i].Name_2 = "Teacher_";
        Array_2[i].Name_2 += nameSeed[i];

        for(int j = 0; j < 5; j ++){

            Array_2[i].Array_1[j].Name_1 = "Student_";
            Array_2[i].Array_1[j].Name_1 += nameSeed[j];

            int random = rand()%61+40;

            Array_2[i].Array_1[j].score = random;
        }
    }
}

void printInfo(struct Teacher Array_2[],int len)
{
    for(int i = 0; i < len; i ++){

        cout << "Teacher'name " << Array_2[i].Name_2<<endl;

        for(int j = 0; j < 5; j ++){

            cout << "\tStudents'name " << Array_2[i].Array_1[j].Name_1 << "score " << Array_2[i].Array_1[j].score << endl;
        }
    }
}

int main(){

    srand((unsigned int)time(NULL));

    struct Teacher tArray[3];
    int len = sizeof(tArray) / sizeof(tArray[0]);

    allocateSpace(tArray,len);
    printInfo(tArray,len);

    system("pause");
    
    return 0;
}