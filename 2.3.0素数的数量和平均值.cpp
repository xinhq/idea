//编写程序求m到n之间（包括m和n，m<=n）素数的个数及其平均值，
//如果没有素数则输出NO，m和n由键盘输入。
//样例输入：1 10 
//样例输出：4 4.25 
//样例输入：8 10 
//样例输出：NO 

#include<iostream>
using namespace std;

int main()
{
    int m, n, a = 0, b = 0, c = 0;

    cin >> m >> n;

    for (int i = m; i <= n; i ++)
    {
        for (int j = 2; j < i; j ++)
        {
            if (i % j != 0)
            {
                a ++;
            }
        }

        if (a != 0)
        {
            b ++;
            c += i;
        }
    }

    if (b == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << b << " " << c / b << endl;
    }

    system("pause");
    
    return 0;
}