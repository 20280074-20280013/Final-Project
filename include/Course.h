#ifndef COURSE_H
#define COURSE_H
#include "../include/SchoolYear.h"
#include "../include/Semester.h"
struct session
{
    char* sess[2];
    char* day[3];
};
struct course
{
    int ID;
    char* name;
    char* teacher;
    int credits;
    int StudentNum;
    Student* arr;
    session* taught;
};
struct nodeC
{
    course data;
    nodeC* pnext;
};
nodeC* createCouse();
void addCourse(semester& s);
#endif