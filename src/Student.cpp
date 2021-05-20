#include "../include/Student.h"
void Init(Class& c)
{
    c.pHead = NULL;
    c.pTail = NULL;
}
void ViewCouse(semester s)
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