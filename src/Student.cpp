#include "../include/Student.h"
void Init(Class& c)
{
    c.pHead = NULL;
    c.pTail = NULL;
}
void AddStudent(Class &l,node* &p)
{
    if(l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = p;
        p->pNext = NULL;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
        l.pTail->pNext= NULL;
    }
}
void quickinput(Class& a)
{
    char* temp = new char[100];
    fstream f;
    fstream g;
    node* p;
    f.open("QuickInput.csv",ios_base::in);
    g.open("Class.txt",ios_base::out);
    while(!f.eof())
    {
        p = new node;
        f>>p->data.No;
        f>>p->data.ID;
        f.getline(temp,100,',');
        p->data.FirstName = new char[strlen(temp)+1];
        strcpy(p->data.FirstName,temp);
        f.getline(temp,100,',');
        p->data.LastName = new char[strlen(temp)+1];
        strcpy(p->data.LastName,temp);
        f.getline(temp,100,',');
        p->data.Gender = new char[strlen(temp)+1];
        strcpy(p->data.Gender,temp);
        f>> p->data.DateofBirth.day >> p->data.DateofBirth.month >> p->data.DateofBirth.year;
        f>> p->data.SocialID;
        p->data.pass = p->data.SocialID;
        AddStudent(a,p);
        g << p->data.No << p->data.ID << p->data.FirstName << p->data.LastName << p->data.Gender
        <<p->data.DateofBirth.day << p->data.DateofBirth.month << p->data.DateofBirth.year << p->data.SocialID;
        delete p;
    }
    delete temp;
    f.close();
    g.close();
}
Class createClass()
{
    char temp[100];
    Class a;
    cout << "Class name ";
    cin.ignore();
    cin.getline(temp,100);
    a.ClassName = new char[strlen(temp)+1];
    strcpy(a.ClassName,temp);
    Init(a);
    return a;
}

