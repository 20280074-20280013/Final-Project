#include "../include/Academic.h"
nodeA* Register()
{
    char temp[100];
    char temp2[100];
    char temp3[100];
    char temp1[100];
    nodeA* p = new nodeA;
    if(p== NULL)
    {
        exit(1);
    }
    cout << "Name ";
    cin.ignore();
    cin.getline(temp,100);
    p->data.name = new char[strlen(temp)+1];
    strcpy(p->data.name,temp);
    cout << "Password ";
    cin.getline(temp1,100);
    p->data.pass = new char[strlen(temp1)+1];
    strcpy(p->data.pass,temp1);
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
void init(list& l)
{
    l.pHead = NULL;
    l.pTail= NULL;
}
nodeA* Search(list&l,char* name)
{
    nodeA* temp = l.pHead;
    if(temp == NULL)
    {
        cout << "Not any Academic member in the system";
        exit(1);
    }
    else if (temp->pnext == NULL)
    {
        if(strcmp(temp->data.name,name)==0)
        return temp;
        else
        {
            cout << "Academic member is unavailable in the system";
            exit(1);
        }
    }
    else
    {
        while(temp != NULL)
        {
            if(strcmp(temp->data.name,name)==0)
            {
                return temp;
            }
            temp = temp->pnext;
        }
    }
}
