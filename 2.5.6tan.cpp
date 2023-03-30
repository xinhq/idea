//求数列 
//S=1+x-x^2/2!+x^3/3!-x^4/4!+……+(-1)^(n+1)x^n/n!
//输入正整数n和任意数x，计算该序列的前n项和。
//样例输入：5 0.5
//样例输出：1.39349

#include<iostream>
using namespace std;

int main()
{
    int n;
    double x,s=1,s1=1,s2=1,s3=1;//s3方便-1操作

    cin>>n>>x;

    for(int i=1;i<=n;i++)
    {
        s1*=i;//s1累积存储i的值
        s2*=x;//s2累积存储x的值
        s+=s3*s2/s1;
        s3*=-1;
    }

    cout<<s<<endl;

    system("pause");
    
    return 0;
}