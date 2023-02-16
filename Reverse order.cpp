#include<iostream>
using namespace std;
int main()
{
    int arr[5]={1,2,3,4,5};
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<endl;
    }
    int start=0;
    int end=sizeof(arr)/sizeof(arr[0])-1;   
    while(start<end)
    { 
    int temp=arr[start];  
    arr[start]=arr[end];
    arr[end]=temp;
    start++;
    end--;
    }
    for(int i=0;i<5;i++)
    {
    cout<<arr[i]<<endl;
    }
    system("pause");
    return 0;
}