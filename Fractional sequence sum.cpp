//有一分数序列， 
//2/1,3/2,5/3,8/5,13/8,21/13……
//计算该序列的前n项和，n由键盘输入。
//样例输入：20 
//样例输出：32.6603
#include<iostream>
using namespace std;
int main()
{
    int n;
    double j=2,sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        sum+=j;
        j=1+1/j;
    }
    cout<<sum<<endl;
    system("pause");
    return 0;
}