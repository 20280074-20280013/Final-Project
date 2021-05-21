#ifndef SEMESTER_H
#define SEMESTER_H
#include "../include/Academic.h"
#include "../include/Student.h"
#include "../include/Date.h"
struct semester
{
    int idx;
    date start;
    date end;
    nodeC *Head;
    nodeC *Tail;
};
void addCourse(semester& s,nodeC* &p);
void init(semester& a);
#endif