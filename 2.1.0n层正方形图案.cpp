//【问题描述】编写程序，输出n层正方形图案。正方形图案最外层是第一层，每层用的数字和层数相同。
//【输入形式】正方形图案的层数n
//【输出形式】2n-1行2n-1列数据，一行上的数据用一个空格分隔
//【样例输入】
//3
//【样例输出】
//1 1 1 1 1
//1 2 2 2 1
//1 2 3 2 1
//1 2 2 2 1
//1 1 1 1 1
//【样例说明】3层图案，最外层都是1，里面一层都是2，最里面一层只有一个数3，所以是5×5的矩形。

#include<iostream>
using namespace std;
int main()
{
    int n, arr[100][100]={1};
    cin >> n;
    for (int m = 0; m < 2*n-1 ;m ++)
    {
        for (int i = 1; i <= 2*n-1-m; i ++)
        {
            if (i <= (2*n-m)/2)
            {
                arr[i-1][i+m-1] = i;
                arr[i+m-1][i-1] = i;
            }
            else
            {
                arr[i-1][i+m-1] = 2*n-m-i;
                arr[i+m-1][i-1] = 2*n-m-i;
            }
        }
    }

    for (int i = 0; i < 2*n-1; i ++)
    {
        for(int j=0;j<2*n-1;j++)
        {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }

    system("pause");

    return 0;
}