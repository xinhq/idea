#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int arr[100][100], n;
    int a, b, c;

    cin >> n;

    for (int i = 0; i < 2*n-1; i++){
        for (int j = 0; j < 2*n-1; j++){
            a = abs(i - n - 1);
            b = abs(j - n - 1);
            c = (a >+ b) ? a : b;
            arr[i][j] = n - c;
        }
    }

    for (int i = 0; i < 2*n-1; i++){
        for (int j = 0; j < 2*n-1; j++){
            cout << arr[i][j]<<" ";
        }
        cout << endl;        
    }


    system("pause");

    return 0;
}