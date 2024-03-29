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
    int n, arr[100][100]={1};//首先定义n和一个数组arr〔100〕〔100〕

    cin >> n;

    /*观察结构，发现所要输出的方阵根据主对角线(左上到右下)对称，
    因此只需找到输出主对角线以上(含主对角线)的部分即可。

    首先解决主对角线(第一组数)，主对角线数字顺序为1，2，……，n－1，n , n－1, ……，2，1也是对称的，且根据 n 对称。

       为了方便起见，令for语句中 i 的初始值为1，则此时每个 i 对应的都是arr[i－1][i－1]。
       为了方便描述，不妨将数组中的元素命名为m，当 i ＜＝n时，m＝i；当i > n时，m＝2* n－i。

       此时主对角线 (第一行第一列，第二行第二列，……，第2* n－1行第2* n－1列)  解决完毕，
       下面来看第二组 (第一行第二列，第二行第三节，……，第2* n－2行第2* n－1列) 。

       此时第二组数的总数为2* n－2，此时最中间的数为n－1(此时最中间的数有两个，但无妨)，
       此时每个 i 对应的数组元素是arr[i－1][i－1＋]〕(即arr[i－1][ i ])，同样用m代替。
       和第一组类似，当 i＜＝n时，m＝i；当 i > n时，由于第二组总数个数为偶数，因此第一组公式不合适，因此需要找一个同时适用于奇数个数和偶数个数的公式。
       此时考虑第三组数(第一行第三列，第二行第四列，……，第n－3行第n－1列) 最中间的数字也是n－1，进一步证明了上面那个公式不合适。接下来有两种方法解决这个问题 :

    ## 方法一  

      只讨论奇数组(1、3、5、……、2* n－1组) 

      这时第一组数中那个公式就可以用了，即第 j 组数的个数为2* n－j，最中间的数为(2* n－j＋1)/2 (不妨记为n1)，当 i＜＝n1时，m＝i；当i >n1时，m＝2*n1－i 
      将所有奇数组放到一个for循环中

      这时可以发现，所有空缺的偶数组的数都是前面的数和后面的数的平均数


      ## 方法二  

      从出现的问题出发，找到一个新的公式

      为了方便起见，不妨拿n＝3举例，此时第一组数为1，2，3，2，1；第二组数为1，2，2，1；
      如果按照上面那个公式第一组数在 i >3时，依次为2*3－4，2*3－5 第二组数在 i >2时，依次为2*2－3，2*2－4 
      显然第二组数与我们想要得到的不同，结果差了1，因此考虑如何才能得到我们想要的结果，也许(2*2＋1)-3，(2*2＋1)-4可以得到，这里可以用if条件语句，	
      但是有些繁琐，我们需要得到一个适用于所有情况的公式，第 j 组中间的数为n－j(记作a)，第 j 组数的个数为2* n－1-j(记作b)，
      由2*a－1＝b可得，a＝( b＋1)/2 (此时不论b为奇数还是偶数，由int整型得到的a为一个整数)，于是 i > n1时公式可以改为m＝2*a－i，此时将所有数放到for循环中。    
*/
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

    
    

    /*得到主对角线及主对角线以上部分的数后，主对角线下的数就很容易得到了，由矩阵对称可令a[i-1-j][i-1]＝a[i－1][i-1-j]  于是，所要求得的矩阵就完全求出了

    运算部分需要有嵌套循环，内层为 i 的循环，i 表示第几行，外层为m的循环，i + m表示第几列

    最后就是结果的输出了，同样是利用for循环*/
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