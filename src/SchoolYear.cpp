#include "../include/SchoolYear.h"
void initSchool(listS& l)
{
    l.Head = NULL;
    l.Tail =NULL;
}
void AddSchool(listS& l,nodeS* &a)
{
    if(l.Head == NULL)
    {
        l.Head = a;
        l.Tail =a;
        l.Tail->pnext = NULL;
    }
    else
    {
        l.Tail->pnext = a;
        l.Tail = a;
        l.Tail->pnext = NULL;
    }
}
void WriteSchool(listS& l)
{
    fstream f;
    f.open("SchoolYear.txt",ios_base::out);
    nodeS* temp = l.Head;
    if(temp == NULL)
    return;
    while(temp!= NULL)
    {
        f<<temp->data.year1 << temp->data.year2;
        f<<temp->data.Sem->idx << temp->data.Sem->start.day << temp->data.Sem->start.month << temp->data.Sem->start.year;
        temp = temp->pnext;
    }
    f.close();
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
sem creSem(listS& l)
{
    sem a;
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

