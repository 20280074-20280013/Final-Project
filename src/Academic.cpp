#include "../include/Academic.h"
void inputDate(Date &a)
{
    cout << "day/month/year of birth ";
    cin >> a.day >> a.month >> a.year;
}
node* Register()
{
    char temp[100];
    char temp2[100];
    char temp3[100];
    node* p = new node;
    if(p== NULL)
    {
        return;
    }
    cout << "Name ";
    cin.getline(temp,100);
    p->data.name = new char[strlen(temp)+1];
    strcpy(p->data.name,temp);
    cout << "Password ";
    cin>> p->data.Pass;
    cout << "Username ";
    cin.getline(temp2,100);
    p->data.user = new char[strlen(temp2)+1];
    strcpy(p->data.user,temp2);
    cout << "Subject interest ";
    cin.getline(temp3,100);
    p->data.Subject = new char[strlen(temp3)+1];
    strcpy(p->data.Subject,temp3);
    inputDate(p->data.birth);
    return p;
}
void ViewProfile(node* p)
{
    cout << "Name " <<endl;
    cout << p->data.name<<endl;
    cout << "Birth "<<endl;
    cout <<p->data.birth.day << "/" << p->data.birth.month << "/" << p->data.birth.year;
    cout << "Subject interest " << endl;
    cout << p->data.Subject << endl;
}
void init(list& l)
{
    l.pHead = NULL;
    l.pTail= NULL;
}
void AddAcademic(list& l)
{
    node* p = Register();
    if(p==NULL)
    {
        return;
    }
    if(l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail =p;
        l.pTail->pnext = NULL;
    }
    else
    {
        l.pTail->pnext = p;
        l.pTail = p;
        p->pnext = NULL;
    }
}
void DelAcademic(list& l,char* name)
{
    node* temp = l.pHead;
    if(temp == NULL)
    {
        return;
    }
    while(temp != NULL)
    {
        if(strcmp(temp->data.name,name)==0)
        {
            if(temp == l.pHead)
            {
                l.pHead = temp->pnext;
                delete temp;
                return;
            }
            else
            {
                node* pprev = l.pHead;
                while(pprev->pnext != temp)
                pprev = pprev->pnext;
                pprev->pnext = temp->pnext;
                if(temp == l.pTail)
                l.pTail=pprev;
                delete temp;
                return;
            }
        }
    }
}
node* Search(list&l,char* name)
{
    node* temp = l.pHead;
    if(temp == NULL)
    {
        cout << "Not any Academic member in the system";
        return;
    }
    else if (temp->pnext == NULL)
    {
        if(strcmp(temp->data.name,name)==0)
        ViewProfile(temp);
        else
        {
            cout << "Academic member is unavailable in the system";
            return;
        }
        return;
    }
    else
    {
        while(temp != NULL)
        {
            if(strcmp(temp->data.name,name)==0)
            {
            ViewProfile(temp);
            }
            temp = temp->pnext;
        }
    }
}
