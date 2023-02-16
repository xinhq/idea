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