//有三根针A、B、C。A针上有N个盘子，大的在下，小的在上，
//要求把这N个盘子从A针移到C针，在移动过程中可以借助B针，每次只允许移动一个盘，
//且在移动过程中在三根针上都保持大盘在下，小盘在上。

// 将n 个盘子从A针移到C针可以分解为三个步骤：
// 将A 上n-1个盘子移到 B针上（借助C针）；
// 把A针上剩下的一个盘子移到C针上；
// 将n-1个盘子从B针移到C针上（借助A针）。

#include <iostream>
using namespace std;

//将src针的最上面一个盘子移动到dest针上
void move(char src, char dest) { 
    cout << src << " --> " << dest << endl;
}

//将n个盘子从src针移动到dest针，以medium针作为中转
void hanoi(int n, char src, char medium, char dest)
{
  if (n == 1)
    move(src, dest);
  else {
    hanoi(n - 1, src, dest, medium);
    move(src, dest);
    hanoi(n - 1, medium, src, dest);
  }
}
int main() {
  int m;
  cout << "Enter the number of diskes: "<<endl;
  cin >> m;
  cout << "the steps to moving " << m << " diskes:" << endl;
  hanoi(m,'A','B','C');
  system("pause");
  return 0;
}