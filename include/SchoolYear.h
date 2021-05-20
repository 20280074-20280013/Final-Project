#ifndef SCHOOLYEAR_H
#define SCHOOLYEAR_H
#include "../include/Student.h"
#include "../include/Academic.h"
#include "../include/Semester.h"
struct School
{
    int year1;
    int year2;
    semester Sem[3];
};
struct nodeS
{
    School data;
    nodeS* pnext;
};
struct listS
{
    nodeS* Head;
    nodeS* Tail;
};
void AddSchool(listS& l,nodeS* &a);
void initSchool(listS& l);
void WriteSchool(listS& l);
#endif