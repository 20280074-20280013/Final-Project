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
    return p;
}
void addCourse(sem& s,nodeC* &p)
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
void init(sem& a)
{
    a.end.day = 0;
    a.end.month =0;
    a.end.year =0;
    a.start.day = 0;
    a.start.month =0;
    a.start.year =0;
    a.idx=0;
    a.Head = NULL;
    a.Tail = NULL;
}
void ViewCouse(sem s)
{
    nodeC* temp = s.Head;
    cout << " Course  |  ID  |  Students |  Teacher  | " <<endl; 
    while(temp != NULL)
    {
        cout << temp->data.name << " - "<< temp->data.ID << " - " << temp->data.StudentNum << " - "
        << temp->data.teacher << endl;
        temp = temp->pnext;
    }
}
