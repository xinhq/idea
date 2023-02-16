#include<iostream>
using namespace std;
int main()
{ char s[100]={0};
int i,t1=0,t2=0,t3=0;
cin>>s;
int n=0;
while(s[n]!=0)
n++;
for(i=0;i<n;i++)
{ 
    if(s[i]>='A'&&s[i]<='Z'||s[i]>='a'&&s[i]<='z')
    t1++;
    else if(s[i]>='0'&&s[i]<='9')
    t2++;
    else t3++;
}
cout<<t1<<" "<<t2<<" "<<t3<<endl;
//system("pause");
return 0;
}
