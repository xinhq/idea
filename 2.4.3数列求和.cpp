//编写程序求 a + aa + aaa + aaaa +…+ aaa…a（n个a）之和，其中a和n由键盘输入。
//样例输入：8 5 
//样例输出：98760

#include<iostream>
using namespace std;
int main()
{
    int a,n,sum=0,j=0;
    cin>>a>>n;
    j=a;
    for(int i=0;i<n;i++)
    {
        sum+=j;
        j=j*10+a;
    }
    cout<<sum;
    system("pause");
    return 0;
}