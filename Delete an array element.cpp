#include<iostream>
using namespace std;
struct Node
{
    int num;
    Node*next;
};
int main()
{
    Node arr[50], *head, *p, *p1 = NULL;
    int i, j = 0, k;

    cin >> arr[1].num;
    arr[0].next = &arr[1];
    head = &arr[0];
    p = head;

    for (i = 1; arr[i].num != -1; i ++){
        cin >> arr[i + 1].num;
        j = i + 1;
    }

    for (int a = j - 1; a > 0; a --){
        arr[a].next = &arr[a - 1];
    }
    arr[1].next = NULL;
    p = &arr[j - 1];

    cin >> k;

    while (p -> next != NULL){
        p1 = p;
        p = p -> next;
        if (p -> num == k){
            break;
        }
    }
    p1 -> next = p -> next;
    if (arr[j - 1].num != k){
        p = &arr[j - 1];
    }
    else{
        p = &arr[j - 2];
    }
    arr[1].next = NULL;

     do{
         cout << p -> num <<" ";
         p = p ->next;
     }
     while (p != NULL);
     
    //system("pause");

    return 0;

}