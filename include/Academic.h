#ifndef ACADEMIC_H
#define ACADEMIC_H
#include "../include/SchoolYear.h"
#include "../include/Student.h"
#include "../include/Date.h"
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
#endif
