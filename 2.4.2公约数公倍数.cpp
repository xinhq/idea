//输入两个正整数m和n，编写程序求其最大公约数和最小公倍数。 
//样例输入：15 25
//样例输出：5 75 

#include<iostream>
using namespace std;
int main()
{
    int i, m, n, gys, gbs;
	cin >> m >> n;
	
	for (i = 1; i <= m; i ++)
	   if (m % i == 0 && n % i == 0)
		 gys = i;

	for (i = m * n; i >= m; i --)
	   if (i % m == 0 && i % n == 0)
		 gbs = i;

	cout << gys << " " << gbs;

    system("pause");
	
	return 0;
}