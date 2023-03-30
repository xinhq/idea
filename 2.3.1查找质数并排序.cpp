//输入一组数字，程序会找出其中的质数，并将质数从小到大进行排列

#include<iostream>
using namespace std;
void fun_1(int n, int arr_1[], int arr_2[], int &b)
{
    int a = 0;
    for (int i = 0; i < n; i ++){
        for (int j = 2; j < arr_1[i]; j ++){
            if (arr_1[i] % j == 0){
                if (arr_1[i] != 2){
                    break;
                }
                else{
                    a = 1;
                }
            }
            else {
                a = 1;
            }
        }
        if (a == 1){
            arr_2[b] = arr_1[i];
            b += 1;
        }
    }
}
void fun_2(int arr_2[], int &b)
{
    int tem;
    for (int i = 0; i < b; i ++){
        for (int j = 0; j < b - 1; j ++){
            if (arr_2[j] < arr_2[j + 1]){
                tem = arr_2[j];
                arr_2[j] = arr_2[j + 1];
                arr_2[j + 1] = tem;
            }
        }
    }
}
int main()
{
    int n, arr_1[30], arr_2[30], b = 0;

    cin >> n;
    for (int i = 0; i < n; i ++){
        cin >> arr_1[i];
    }

    fun_1(n, arr_1, arr_2, b);
    fun_2(arr_2, b);

    for (int i = 0; arr_2[i] != 0; i ++){
        cout << arr_2[i] <<" ";
    }

    return 0;
}