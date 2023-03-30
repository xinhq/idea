#include<iostream>
#include<string>
using namespace std;

struct People
{
    string name;
    int age;
    string genda;
};

void bubbleSort(struct People peo[],int len)
{
    for (int i = 0; i < len; i ++)
    {
        for (int j = 0; j < len - i - 1; j ++)
        {
            if (peo[j].age > peo[j+1].age)
            {
                struct People temp = peo[j];
                peo[j] = peo[j+1];
                peo[j+1] = temp;
            }
        }
    }
}

void printPeople(struct People peo[], int len)
{
    for (int i = 0; i < len; i ++)
    {
        cout << "name  " << peo[i].name << "  age  " << peo[i].age << "  sex  " << peo[i].genda << endl;
    }
}

int main()
{
    struct People peo[5] =
    {
        {"Tom", 27 , "man"},
        {"Jerry", 24, "man"},
        {"Tony", 29, "man"},
        {"Jack", 21, "man"},
        {"Jeny", 19, "woman"},
    };

    int len = sizeof(peo) / sizeof(peo[0]);

    bubbleSort(peo,len);
    printPeople(peo,len);

    //for(int i=0;i<len;i++)
    //{
    //    cout<<"name  "<<heroArray[i].name<<"  age  "<<heroArray[i].age<<"  sex  "<<heroArray[i].sex<<endl;
    //}

    system("pause");
    
    return 0;
}