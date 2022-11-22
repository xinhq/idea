#include<iostream>
using namespace std;
#include<string>
struct Hero
{
    string name;
    int age;
    string sex;
};
void bubbleSort(struct Hero heroArray[],int len)
{
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len-i-1;j++)
        {
            if(heroArray[j].age>heroArray[j+1].age)
            {
                struct Hero temp=heroArray[j];
                heroArray[j]=heroArray[j+1];
                heroArray[j+1]=temp;
            }
        }
    }
}
void printHero(struct Hero heroArray[],int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<"name  "<<heroArray[i].name<<"  age  "<<heroArray[i].age<<"  sex  "<<heroArray[i].sex<<endl;
    }
}
int main()
{
    struct Hero heroArray[5]=
    {
        {"Tom",27,"man"},
        {"Jerry",24,"man"},
        {"Tony",29,"man"},
        {"Jack",21,"man"},
        {"Jeny",19,"woman"},
    };
    int len=sizeof(heroArray)/sizeof(heroArray[0]);
    bubbleSort(heroArray,len);
    printHero(heroArray,len);
    //for(int i=0;i<len;i++)
    //{
    //    cout<<"name  "<<heroArray[i].name<<"  age  "<<heroArray[i].age<<"  sex  "<<heroArray[i].sex<<endl;
    //}
    system("pause");
    return 0;
}