#ifndef Student_H
#define Student_H
#include<iostream>
#include<string.h>
#include <fstream>
#include "../include/Semester.h"
using namespace std;
struct date
{
	int day;
	int month;
	int year;
};
struct Student
{
	int No;
	char* ID;
	char* FirstName;
	char* LastName;
	char* Gender;
	date DateofBirth;
	char* SocialID;
	char* pass;
};
struct node
{
	Student data;
	node* pNext;
};
struct Class
{
	char* ClassName;
	node* pHead;
	node* pTail;
};
void Init(Class& c);
void ViewCouse(semester s);
#endif