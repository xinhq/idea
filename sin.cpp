//sin
#include<iostream>
#include<cmath>
using namespace std;
const double TINY_VALUE=1e-10;
double tsin(double x)
{
    double g=0;
    double t=x;
    int n=1;
    do
    {
        g+=t;
        n++;
        t=-t*x*x/(2*n-1)/(2*n-2);
    }
    while(fabs(t)>=TINY_VALUE);
    return g;
}
int main()
{
    double x = 0;
    cin >> x;
    cout << tsin(x) << endl;
    system("pause");
    return 0;
}