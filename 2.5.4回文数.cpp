//回文数：若一个数字反向排列得到的数字与原来相等，那么该数为回文数
//找出10到1000之间的回文数

#include<iostream>
using namespace std;

bool symm(unsigned n);

int main(){
    for (unsigned m = 11; m < 1000; m ++)

    if (symm(m) && symm(m * m) && symm(m * m * m))
    {
        cout << "m=" << m;
        cout << "  m*m=" << m * m;
        cout << "  m*m*m=" << m * m * m <<endl;
    }

    system("pause");

    return 0;
}

bool symm(unsigned n){
    unsigned i = n;
    unsigned m = 0;

    while (i > 0)
    {
        m = m * 10 + i % 10;
        i /= 10;
    }

    return m==n;
}