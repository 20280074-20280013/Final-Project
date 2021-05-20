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
