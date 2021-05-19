#ifndef ACADEMIC_H
#define ACADEMIC_H
#include <string.h>
#include <iostream>
using namespace std;
struct Date
{
    int day;
    int month;
    int year;
};
struct Academic
{
    char* Subject;
    Date birth;
    char* name;
    char* user;
    int Pass;
};
struct node
{
    Academic data;
    node* pnext;
};
struct list
{
    node* pHead;
    node* pTail;
};
void init(list& l);
node* Register();
void inputDate(Date &a);
void ViewProfile(node* p);
void AddAcademic(list& l);
void DelAcademic(list& l,char* name);
node* Search(list&l,char* name);
#endif
