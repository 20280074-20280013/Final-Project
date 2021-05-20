#include "../include/Academic.h"
void inputDate(date &a)
{
    cout << "day/month/year of birth ";
    cin >> a.day >> a.month >> a.year;
}
nodeA* Register()
{
    char temp[100];
    char temp2[100];
    char temp3[100];
    nodeA* p = new nodeA;
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
void ViewProfile(nodeA* p)
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
nodeA* Search(list&l,char* name)
{
    nodeA* temp = l.pHead;
    if(temp == NULL)
    {
        cout << "Not any Academic member in the system";
        return;
    }
    else if (temp->pnext == NULL)
    {
        if(strcmp(temp->data.name,name)==0)
        return temp;
        else
        {
            cout << "Academic member is unavailable in the system";
            return;
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
Class createClass()
{
    char temp[100];
    Class a;
    cout << "Class name ";
    cin.getline(temp,100);
    a.ClassName = new char[strlen(temp)+1];
    strcpy(a.ClassName,temp);
    Init(a);
    return a;
}
void AddStudent(Class& l,node*& p)
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
nodeS* createSchool(int year1, int year2)
{
    nodeS* a;
    a = new nodeS;
    a->data.year2 = year1;
    a->data.year2 = year2;
    for(int i=0;i<3;i++)
    init(a->data.Sem[i]);
    a->pnext = NULL;
    return a;
}
semester createSem(listS& l)
{
    semester a;
    int year1, year2;
    cout << "Semester ";
    cin >> a.idx;
    inputDate(a.start);
    inputDate(a.end);
    cout << "School year";
    cin >> year1 >> year2;
    nodeS* temp = l.Head;
    while(temp != NULL)
    {
        if(temp->data.year1 == year1 && temp->data.year2 == year2)
        {
            temp->data.Sem[a.idx-1]= a;
            exit(1);
        }
    }
    nodeS* x = createSchool(year1,year2);
    x->data.Sem[a.idx-1]=a;
    AddSchool(l,x);
    return a; 
}
nodeS* createSchool()
{
    nodeS* a;
    a = new nodeS;
    cout << "School Year ";
    cin >> a->data.year1 >> a->data.year2;
    for(int i =0;i<3;i++)
    {
        init(a->data.Sem[i]);
    }
    return a;
}
