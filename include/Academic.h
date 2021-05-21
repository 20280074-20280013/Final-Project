#ifndef ACADEMIC_H
#define ACADEMIC_H
#include "../include/SchoolYear.h"
#include "../include/Student.h"
#include "../include/Semester.h"
#include "../include/Course.h"
struct Academic
{
    char* Subject;
    date birth;
    char* name;
    char* user;
    char* pass;
};
struct nodeA
{
    Academic data;
    nodeA* pnext;
};
struct list
{
    nodeA* pHead;
    nodeA* pTail;
};
void init(list& l);
nodeA* Register();
nodeA* Search(list&l,char* name);
void AddStudent(Class& l,node*& p);
Class createClass();
semester createSem(listS& l);
nodeS* createSchool(int year1, int year2);
nodeS* createSchool();
#endif
