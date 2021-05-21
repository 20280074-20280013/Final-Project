#include "../include/Login.h"
bool Login(Class l)
{
	int cnt = 0;
	char tempID[20];
	char* inputID;
	cout << "Input your Student ID: ";
	while (cnt<3)
	{
		cin.ignore();
		cin.getline(tempID, 20 + 1);
		inputID = new char[strlen(tempID) + 1];
		strcpy(inputID, tempID);
		node* temp = l.pHead;
		while(temp != NULL)
		{
			if (strcmp(inputID, temp->data.ID) == 0)
			{
				int cnt1 = 0;
				char* InputPass = NULL;
				char tempPass[10];
				cout << "Input your Password: ";
				while (cnt1 < 3)
				{
					cin.ignore();
					cin.getline(tempPass, 10 + 1);
					InputPass = new char[strlen(tempPass + 1)];
					strcpy(InputPass, tempPass);
					if (strcmp(InputPass, temp->data.pass) == 0)
					{
						cout << "Successed!";
						delete[] inputID;
						delete[]InputPass;
						return true;
					}
					else
					{
						cnt1++;
						if(cnt1<=2)
						cout << "Wrong! Input again: " << endl;
					}
				}
				cout << "Please try again later!" << endl;
				delete[] InputPass;
				return false;
			}
			temp = temp->pNext;
		}
		cnt++;
		if(cnt<=2)
		cout << "Can't find your acount, input your ID again: " ;
	}
	cout << "Please try again later!";
	delete[] inputID;
	return false;
}

void ViewProfile(nodeA* p)
{
    cout << "Name " <<endl;
    cout << p->data.name<<endl;
    cout << "Birth "<<endl;
    cout <<p->data.birth.day << "/" << p->data.birth.month << "/" << p->data.birth.year;
    cout << "Subject interest " << endl;
    cout << p->data.Subject << endl;
}
void ViewProfile(node* p)
{
	cout << "No |  ID  | First Name | Last Name | Gender | Date of Birth | Social ID |" << endl;
	cout << p->data.No << " | " << p->data.ID << " | "<< p->data.FirstName << " | "<< p->data.LastName
	<< " | "<<p->data.Gender << " | "<< p->data.DateofBirth.day << "/"<<p->data.DateofBirth.month << "/"<<p->data.DateofBirth.year << " | "
	<< p->data.SocialID << " |"<<endl;
}
bool ChangePassword(node* &s)
{
	int count =0;
	char pass[30],pass1[30];
	char pass2[30];
	bool flag = false;
	while(count <=3 && flag == false)
	{
	cout << "Input current password"<<endl;
	cin.ignore();
	cin.getline(pass,30);
	if(strcmp(pass,s->data.pass)==0)
	flag = true;
	cout << "Input new pass word"<<endl;
	cin.getline(pass1,30);
	cout << "Input new passwrod again"<<endl;
	cin.getline(pass2,30);
	if(strcmp(pass1,pass2)!=0)
	flag = false;
	if(flag == true)
	{
		if(s->data.pass != NULL)
		delete s->data.pass;
		s->data.pass = new char[strlen(pass1)+1];
		strcpy(s->data.pass,pass1);
		return flag;
	}
	count++;
	}
	cout << "Please try again later !";
	return flag;
}
bool ChangePassword(nodeA* &a)
{
	int count =0;
	char pass[30],pass1[30];
	char pass2[30];
	bool flag = false;
	while(count <=3 && flag == false)
	{
	cout << "Input current password"<<endl;
	cin.ignore();
	cin.getline(pass,30);
	if(strcmp(pass,a->data.pass)==0)
	flag = true;
	cout << "Input new pass word"<<endl;
	cin.getline(pass1,30);
	cout << "Input new passwrod again"<<endl;
	cin.getline(pass2,30);
	if(strcmp(pass1,pass2)!=0)
	flag = false;
	if(flag == true)
	{
		if(a->data.pass != NULL)
		delete a->data.pass;
		a->data.pass = new char[strlen(pass1)+1];
		strcpy(a->data.pass,pass1);
		return flag;
	}
	count++;
	}
	cout << "Please try again later !";
	return flag;
}
