#include "../include/Semester.h"
void init(semester& a)
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