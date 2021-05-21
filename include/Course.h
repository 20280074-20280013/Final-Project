#ifndef COURSE_H
#define COURSE_H
#include "../include/Student.h"
#include "../include/Date.h"
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
    Student arr[50];
    session taught[2];
};
struct nodeC
{
    course data;
    nodeC* pnext;
};
struct sem
{
    int idx;
    date start;
    date end;
    nodeC* Head;
    nodeC* Tail;
};
nodeC* createCouse();
void addCourse(sem& s,nodeC* &p);
void init(sem& a);
void ViewCouse(sem s);
#endif