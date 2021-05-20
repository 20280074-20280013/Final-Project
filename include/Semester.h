#ifndef SEMESTER_H
#define SEMESTER_H
#include "../include/Academic.h"
struct semester
{
    int idx;
    date start;
    date end;
    nodeC *Head;
    nodeC *Tail;
};
void init(semester& a);
#endif