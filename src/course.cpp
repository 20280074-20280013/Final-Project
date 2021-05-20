#include "../include/Course.h"
nodeC* createCourse()
{
    char temp[100];
    char temp2[100];
    nodeC* p = new nodeC;
    if(p== NULL)
    exit(1);
    cout << "Course ID ";
    cin >> p->data.ID;
    cout << "Course name ";
    cin.getline(temp,100);
    p->data.name = new char[strlen(temp)+1];
    strcpy(p->data.name,temp);
    cout << "Teacher name ";
    cin.getline(temp2,100);
    p->data.teacher = new char[strlen(temp)+1];
    strcpy(p->data.teacher,temp2);
    cout << "Number of credits ";
    cin >> p->data.credits;
    cout << "Number of Student in course ";
    cin >>p->data.StudentNum;
    p->data.taught = NULL;
    p->data.arr = NULL;
    return p;
}
void addCourse(semester& s,nodeC* &p)
{
    if(s.Head == NULL)
    {
        s.Head = p;
        s.Tail = p;
        s.Tail->pnext= NULL;
    }
    else
    {
        s.Tail->pnext = p;
        s.Tail = p;
        s.Tail->pnext = NULL;
    }
}
