#include<iostream>
using namespace std;
#include<string>
#define MAX 1000
struct Person
{
    string m_Name;
    int m_Sex;
    int m_Age;
    string m_Phone;
    string m_Addr;
};
struct Addressbooks
{
    Person personArray[MAX];
    int m_Size;
};
void addPerson(Addressbooks*abs)
{
    if(abs->m_Size==MAX)
    {
        cout<<"It's already full!"<<endl;
        return;
    }
    else
    {
        string name;
        cout<<"Please input name."<<endl;
        cin>>name;
        abs->personArray[abs->m_Size].m_Name=name;

        cout<<"Please input sex."<<endl;
        cout<<"1---man"<<endl;
        cout<<"2---woman"<<endl;
        int sex=0;
        while(true)
        {
            cin>>sex;
            if(sex==1||sex==2)
           {
                abs->personArray[abs->m_Size].m_Sex=sex;
                break;
           }
           cout<<"It's wrong, please input away."<<endl;
        }

        cout<<"Please input age."<<endl;
        int age=0;
        cin>>age;
        abs->personArray[abs->m_Size].m_Age=age;

        cout<<"Please input phone number."<<endl;
        string phone;
        cin>>phone;
        abs->personArray[abs->m_Size].m_Phone=phone;

        cout<<"Please input address."<<endl;
        string address;
        cin>>address;
        abs->personArray[abs->m_Size].m_Addr=address;

        abs->m_Size++;

        cout<<"Finished!"<<endl;
        
        system("pause");
        system("cls");
    }
}
void showPerson(Addressbooks*abs)
{
    if(abs->m_Size==0)
    {
        cout<<"It's empty!   Please add information."<<endl;
    }
    else
    {
        for(int i=0;i<abs->m_Size;i++)
        {
            cout<<"Name    :  "<<abs->personArray[i].m_Name<<"\t";
            cout<<"Sex     :  "<<(abs->personArray[i].m_Sex==1?"man  ":"woman")<<"\t";
            cout<<"Age     :  "<<abs->personArray[i].m_Age<<"\t";
            cout<<"Number  :  "<<abs->personArray[i].m_Phone<<"\t";
            cout<<"Address :  "<<abs->personArray[i].m_Addr<<endl;
        }
    }
    system("pause");
    system("cls");
}
int isExist(Addressbooks*abs,string name)
{
    for(int i=0;i<abs->m_Size;i++)
    {
        if(abs->personArray[i].m_Name==name)
        {
            return i;
        }
    }
    return -1;
}
void deletePerson(Addressbooks*abs)
{
    cout<<"Please input the name your are going to delete."<<endl;
    string name;
    cin>>name;
    int ret=isExist(abs,name);
    if(ret!=-1)
    {
        for(int i=ret;i<abs->m_Size;i++)
        {
            abs->personArray[i]=abs->personArray[i+1];
        }
        abs->m_Size--;
        cout<<"Finished!"<<endl;
    }
    else
    {
        cout<<"The name your input doesn't exist."<<endl;;
    }
    system("pause");
    system("cls");
}
void findPerson(Addressbooks*abs)
{
    cout<<"Please input the name you want to search."<<endl;
    string name;
    cin>>name;
    int ret=isExist(abs,name);
    if(ret!=-1)
    {
        cout<<"Name    :  "<<abs->personArray[ret].m_Name<<"\t";
        cout<<"Sex     :  "<<abs->personArray[ret].m_Sex<<"\t";
        cout<<"Age     :  "<<abs->personArray[ret].m_Age<<"\t";
        cout<<"Number  :  "<<abs->personArray[ret].m_Phone<<"\t";
        cout<<"Address :  "<<abs->personArray[ret].m_Addr<<endl;
    }
    else
    {
        cout<<"The name you search doesn't exist."<<endl;
    }
    system("pause");
    system("cls");
}
void modifyPerson(Addressbooks*abs)
{
    cout<<"Please input the name you want to modify."<<endl;
    string name;
    cin>>name;
    int ret=isExist(abs,name);
    if(ret!=-1)
    {
        string name;
        cout<<"Please input the name."<<endl;
        cin>>name;
        abs->personArray[ret].m_Name=name;
        cout<<"Please input the sex."<<endl;
        cout<<"1---man"<<endl;
        cout<<"1---woman"<<endl;
        int sex=0;
        while(true)
        {
            cin>>sex;
            if(sex==1||sex==2)
            {
                abs->personArray[ret].m_Sex=sex;
                break;
            }
          cout<<"It's wrong,please inpyt again."<<endl;
        }
        cout<<"Please input the age."<<endl;
        int age=0;
        cin>>age;
        abs->personArray[ret].m_Age=age;
        cout<<"Please input the phone."<<endl;
        string phone;
        cin>>phone;
        abs->personArray[ret].m_Phone=phone;
        cout<<"Please input the address."<<endl;
        string address;
        abs->personArray[ret].m_Addr=address;    
    }
    else
    {
        cout<<"The name you modify doesm't exist."<<endl;
    }
    system("pause");
    system("cls");
}
void cleanPerson(Addressbooks*abs)
{
    abs->m_Size=0;
    cout<<"It's already empty."<<endl;
    system("pause");
    system("cls");
}
void showMenu()
{
    cout<<"*********************************"<<endl;
    cout<<"*****1.add      contact       ***"<<endl;
    cout<<"*****2.display  contact       ***"<<endl;
    cout<<"*****3.delete   contact       ***"<<endl;
    cout<<"*****4.seek     contact       ***"<<endl;
    cout<<"*****5.modify   contact       ***"<<endl;
    cout<<"*****6.clean    contact       ***"<<endl;
    cout<<"*****0.quit     addressbooks  ***"<<endl;
    cout<<"*********************************"<<endl;
}
int main()
{
    Addressbooks abs;
    abs.m_Size=0;
    int select=0;
    while(true)
    {
        showMenu();
        cin>>select;
        switch(select)
        {
            case 1: 
            addPerson(&abs);   
            break;
            case 2:
            showPerson(&abs);
            break;
            case 3:
            deletePerson(&abs);
            break;
            case 4:
            findPerson(&abs);
            break;
            case 5:
            modifyPerson(&abs);
            break;
            case 6:
            cleanPerson(&abs);
            break;
            case 0:
            cout<<"Welcome next time!"<<endl;
            system("pause");
            return 0;
            break;
            default:
            break;
        }
    }
    system("pause");
    return 0;
}