#include<iostream>
#include<ctime>
using namespace std;
int main()
{
    srand((unsigned int)time(NULL));
    int num1=rand()%101;
    int num2;
    while(1)
    {
     cin>>num2;   
     if(num2>num1)
     {
        cout<<"big"<<endl;
     }
     else if(num2<num1)
     {
        cout<<"small"<<endl;
     }
     else
     {
        cout<<"right"<<endl;
        break;
     }
    }
    system("pause");
    return 0;
}