#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#include<string>
#include<ctype.h>
#include<conio.h>
#include<fstream>
#include"game.h"
#define clear system("cls");
using namespace std;
void welcome()
{
cout<<endl<<endl<<endl<<endl;
cout<<"				  _________   _______   _      _   _______  _______       "<<endl;
cout<<"				 |           |       | | \\    / | |        |              "<<endl;
cout<<"				 |           |       | |  \\  /  | |        |              "<<endl;
cout<<"				 |    _____  |_______| |   \\/   | |_______ |_______       "<<endl;
cout<<"				 |         | |       | |        | |                |      "<<endl;
cout<<"				 |         | |       | |        | |                |      "<<endl;
cout<<"				 |_________| |       | |        | |_______  _______|      "<<endl;

	const char a='\xCD';
	const char b='\xBA';
	const char c='\xC9';
	const char d='\xBB';
	const char e='\xC8';
	const char f='\xBC';
	string str="Mini Games";
	string margin=" ";
	string line(str.length()+2*margin.length(),a);
	cout<<endl<<endl;
	cout<<"\t\t\t\t\t\t"<<c<<line<<d<<endl;
	cout<<"\t\t\t\t\t\t"<<b<<margin<<str<<margin<<b<<endl;
	cout<<"\t\t\t\t\t\t"<<e<<line<<f<<endl;
	sleep(5);
	clear;
}
class Account
{
	protected:
		string name;
		char pass[32];
		int id;
	public:
		Account();
		bool input();
};
Account::Account()
{
	id=0;
}
bool Account::input()
{
	cin.ignore();
	cout<<"*********************************************************************************************************"<<endl;
	cout<<"Welcome To Play Games"<<endl<<endl;
	cout<<"*********************************************************************************************************"<<endl;
	cout<<"Enter The Username :";
	getline(cin,name);
	cout<<"Enter The Password :";
	char a;
	int i;
	for(i=0; ; )
    {
        a=getch();
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
        {
            pass[i]=a;
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)//BACKSPACE KEY IS PRESSED
        {
            cout<<"\b \b";//ERASE CHARACTER
            --i;
        }
        if(a=='\r')//ENTER KEY IS PRESSED
        {
            pass[i]='\0';
            break;
        }
    }
	cout<<endl;
    string password = "";
    for (i = 0; pass[i]!='\0'; i++)
	{
        password = password + pass[i];
    }
	string un,pw,filename;
	filename= name + ".txt" ;
	ifstream read(filename.c_str());
	getline(read,un);
    getline(read,pw);
    if(un==name && pw==password)
    {
        return true;
    }
    else
    {
        return false;
    }
}
class Newaccount:private Account
{
	long long int mobileno;
	char cpassword[32];
	public:
		int generate();
		Newaccount();
		void ninput();
};
void Newaccount::ninput()
{
	int i;
	cin.ignore();
   	cout<<"Enter The Username :";
	getline(cin,name);
	cout<<"Enter The Password :";
	char a;
	for(i=0; ; )
    {
        a=getch();
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
        {
            pass[i]=a;
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)//BACKSPACE KEY IS PRESSED
        {
            cout<<"\b \b";//ERASE CHARACTER
            --i;
        }
        if(a=='\r')//ENTER KEY IS PRESSED
        {
            pass[i]='\0';
            break;
        }
    }
	cout<<endl;
   	cout << "Retype Password :";
	for(i=0; ; )
    {
        a=getch();
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
        {
            cpassword[i]=a;
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)//BACKSPACE KEY IS PRESSED
        {
            cout<<"\b \b";//ERASE CHARACTER
            --i;
        }
        if(a=='\r')//ENTER KEY IS PRESSED
        {
            cpassword[i]='\0';
            break;
        }
    }
    string password = "";
    for (i = 0; cpassword[i]!='\0'; i++)
	{
        password = password + cpassword[i];
    }
 	cout<<"\n\n< Press Any Key To Continue >"<<endl;
  	getch();
	cout<<"Enter Your Mobile Number :";
	cin>>mobileno;
	string filename;
	filename=name+".txt";
	ofstream file;
	file.open(filename.c_str());
	file << name << endl << password << endl <<mobileno;
	file.close();
    clear;
	cout<<"\t\t\t\tTHANK YOU FOR CREATING AN ACCOUNT";
	sleep(2);
	clear;
	Game s;
    s.choice_select();
    clear;
}
Newaccount::Newaccount():Account::Account()
{
	mobileno=0;
}
class Routing:private Account
{
	public:
		void Input();
};
void Routing::Input()
{
        int n;
		Newaccount a;
		Account b;
		do
		{
			clear;
			cout<<"\t\t\t\t\t\tACCOUNT SELECTION\n";
        	cout<<"\n\n\n\n\t\t\t\t\t\t1]NEW USER";
        	cout<<"\n\t\t\t\t\t\t2]LOGIN";
        	cout<<"\n\t\t\t\t\t\t0]EXIT\n";
        	cin>>n;
			switch(n)
			{
         		case 1:
					clear;
                	a.ninput();
                	break;
				case 2:
            		clear;
           			bool status=b.input();
					if(!status)
					{
						cout<<"\n<INVLAID USERNAME/PASSWORD!>\n";
						system("PAUSE");
						clear;
					}
					else
					{
						cout<<"\n<LOGIN SUCCESSFULL!>\n";
						sleep(2);
						clear;
						Game s;
                        s.choice_select();
                        clear;
					}
            		break;
			}
		}while(n!=0);
}
 int main()
{
	welcome();
	Routing r;
	r.Input();
}
