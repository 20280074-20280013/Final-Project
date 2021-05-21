#ifndef SCHOOLYEAR_H
#define SCHOOLYEAR_H
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
#include "../include/Course.h"
struct School
{
    int year1;
    int year2;
    sem Sem[3];
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
sem creSem(listS& l);
void WriteSchool(listS& l);
nodeS* createSchool(int year1, int year2);
nodeS* createSchool();
#endif