#include<iostream>
#include <unistd.h>
#include<graphics.h>
#include<windows.h>
#include<mmsystem.h>
#include<stdlib.h>
#include<string>
#include<ctype.h>
#include<conio.h>
#include<fstream>
#define clear system("cls");
using namespace std;
void welcome()
{
	const char a='\xCD';
	const char b='\xBA';
	const char c='\xC9';
	const char d='\xBB';
	const char e='\xC8';
	const char f='\xBC';
	string str="Welcome To ";
	string margin=" ";
	string line(str.length()+2*margin.length(),a);
	cout<<endl<<endl;
	cout<<"\t\t\t\t\t\t"<<c<<line<<d<<endl;
	cout<<"\t\t\t\t\t\t"<<b<<margin<<str<<margin<<b<<endl;
	cout<<"\t\t\t\t\t\t"<<e<<line<<f<<endl;
	sleep(2);
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
	cout<<"Welcome To CHAT"<<endl<<endl;
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
	filename="d://My Files//SEM II//C++ PACKAGE//Login System//Users//"+ name + ".txt" ;
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
	filename="d://My Files//SEM II//C++ PACKAGE//Login System//Users//"+name+".txt";
	ofstream file;
	file.open(filename.c_str());
	file << name << endl << password << endl <<mobileno;
	file.close();
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
					}
            		break;
			}
		}while(n!=0);
}
class piano
{
	int w,h;
	public:
	piano();
	void pianobackground();
	void background();
	int pianomain();
};
piano::piano()
{
	w=1300;
	h=600;
}
void piano::pianobackground()
{
 	setfillstyle(1,8);
	bar(50,100,560,430);
	setfillstyle(4,7);
	bar(60,110,200,170);
	setcolor(4);
	line(50,200,560,200);
	setcolor(5);
	line(50,250,560,250);
	
	setfillstyle(1,15);
	bar(60,320,100,390);
	setfillstyle(1,15);
	bar(110,320,150,390);
	setfillstyle(1,15);
	bar(160,320,200,390);
	setfillstyle(1,15);
	bar(210,320,250,390);
	setfillstyle(1,15);
	bar(260,320,300,390);
	setfillstyle(1,15);
	bar(310,320,350,390);
	setfillstyle(1,15);
	bar(360,320,400,390);
	setfillstyle(1,15);
	bar(410,320,450,390);
	setfillstyle(1,15);
	bar(460,320,500,390);
	setfillstyle(1,15);
	bar(510,320,550,390);
	
	setfillstyle(1,0);
	bar(90,260,120,320);
	setfillstyle(1,0);
	bar(140,260,170,320);
	setfillstyle(1,0);
	bar(240,260,270,320);
	setfillstyle(1,0);
	bar(290,260,320,320);
	setfillstyle(1,0);
	bar(340,260,370,320);
	setfillstyle(1,0);
	bar(440,260,470,320);
	setfillstyle(1,0);
	bar(490,260,520,320);
	
	setbkcolor(8);
	setcolor(15);
	settextstyle(3,0,1);
	char z[2]="z";
	outtextxy(70,390,z);
	char a[2]="a";
	outtextxy(100,390,a);
	char x[2]="x";
	outtextxy(125,390,x);
	char s[2]="s";
	outtextxy(150,390,s);
	char c[2]="c";
	outtextxy(175,390,c);
	char v[2]="v";
	outtextxy(225,390,v);
	char f[2]="f";
	outtextxy(250,390,f);
	char b[2]="b";
	outtextxy(275,390,b);
	char d[2]="d";
	outtextxy(300,390,d);
	char n[2]="n";
	outtextxy(325,390,n);
	char h[2]="[";
	outtextxy(350,390,h);
	char m[2]="m";
	outtextxy(375,390,m);
	char lz[2]=",";
	outtextxy(425,390,lz);
	char f1[2]="h";
	outtextxy(450,390,f1);
	char dz[2]=".";
	outtextxy(475,390,dz);
	char g[2]="g";
	outtextxy(500,390,g);
	char dq[2]="/";
	outtextxy(525,390,dq);

	setbkcolor(12);
	char e1[2]="8";
	outtextxy(870,160,e1);
	char e2[2]="9";
	outtextxy(1020,160,e2);
	char e3[2]="0";
	outtextxy(1170,160,e3);
	char i[2]="i";
	outtextxy(870,310,i);
	char o[2]="o";
	outtextxy(1020,310,o);
	char p[2]="p";
	outtextxy(1170,310,p);
	char k[2]="k";
	outtextxy(870,450,k);
	char l[2]="l";
	outtextxy(1020,450,l);
	char se[2]=";";
	outtextxy(1170,450,se);
}

void piano::background()
{
	setfillstyle(1,9);
	bar(0,0,w,h);
	setfillstyle(1,14);
	bar(800,100,1250,550);
	for(int b=0;b<=10;b++)
	{
		setcolor(4);
		rectangle(800-b,100-b,1250+b,550+b);
	}
	
	setfillstyle(1,12);
	bar(810,110,940,240);
	bar(960,110,1090,240);
	bar(1110,110,1240,240);
	bar(810,260,940,390);
	bar(960,260,1090,390);
	bar(1110,260,1240,390);
	bar(810,410,940,540);
	bar(960,410,1090,540);
	bar(1110,410,1240,540);
	
	setbkcolor(9);
	setcolor(999);
	settextstyle(4,0,2);
}

int piano::pianomain()
{
	int s=100;
	initwindow(w,h,"beatbox");
	background();
	pianobackground();
	char g1[2]="8";
	char g2[2]="9";
	char g3[2]="0";
	char g4[2]="i";
	char g5[2]="o";
	char g6[2]="p";
	char g7[2]="k";
	char g8[2]="l";
	char g9[2]=";";
	for(;;)
	{
			setbkcolor(12);
			outtextxy(870,160,g1);
			outtextxy(1020,160,g2);
			outtextxy(1170,160,g3);
			outtextxy(870,310,g4);
			outtextxy(1020,310,g5);
			outtextxy(1170,310,g6);
			outtextxy(870,450,g7);
			outtextxy(1020,450,g8);
			outtextxy(1170,450,g9);
		char a=getch();
		if(a=='8')
		{
			PlaySound("C_Drum.wav",NULL,SND_FILENAME|SND_ASYNC);
			setfillstyle(1,1);
			bar(810,110,940,240);
			sleep(1);
			setfillstyle(1,12);
			bar(810,110,940,240);
		}
		if(a=='9')
		{
			PlaySound("A_Drum.wav",NULL,SND_FILENAME|SND_ASYNC);
			setfillstyle(1,1);
				bar(960,110,1090,240);
			sleep(1);
			setfillstyle(1,12);
			bar(960,110,1090,240);
		}
		if (a=='0')
		{
			PlaySound("A#_Drum.wav",NULL,SND_FILENAME|SND_ASYNC);
			setfillstyle(1,2);
			bar(1110,110,1240,240);
			sleep(1);
			setfillstyle(1,12);
			bar(1110,110,1240,240);
		}
		if(a=='i')
		{
				PlaySound("B_Drum.wav",NULL,SND_FILENAME|SND_ASYNC);
			setfillstyle(1,2);
			bar(810,260,940,390);
			sleep(1);
			setfillstyle(1,12);
			bar(810,260,940,390);
		}
		if(a=='o')
		{
				PlaySound("C1_Drum.wav",NULL,SND_FILENAME|SND_ASYNC);
			setfillstyle(1,4);
			bar(960,260,1090,390);
			sleep(1);
			setfillstyle(1,12);
			bar(960,260,1090,390);
		}
		if(a=='p')
		{
			PlaySound("Cq_Drum.wav",NULL,SND_FILENAME|SND_ASYNC);
			setfillstyle(1,5);
			bar(1110,260,1240,390);
			sleep(1);
			setfillstyle(1,12);
			bar(1110,260,1240,390);
		}
		if(a=='k')
		{
			PlaySound("Cq1_Drum.wav",NULL,SND_FILENAME|SND_ASYNC);
			setfillstyle(1,6);
			bar(810,410,940,540);
			sleep(1);
			setfillstyle(1,12);
			bar(810,410,940,540);
		}
		if(a=='l')
		{
				PlaySound("D_Drum.wav",NULL,SND_FILENAME|SND_ASYNC);
			setfillstyle(1,7);
			bar(960,410,1090,540);
			sleep(1);
			setfillstyle(1,12);
			bar(960,410,1090,540);
		}
		if(a==';')
		{
				PlaySound("D1_Drum.wav",NULL,SND_FILENAME|SND_ASYNC);
			setfillstyle(1,8);
			bar(1110,410,1240,540);
			sleep(1);
			setfillstyle(1,12);
			bar(1110,410,1240,540);
		}										
		if(a=='a')
		{
				PlaySound(TEXT("C#1.wav"),NULL,SND_FILENAME|SND_ASYNC);
			setfillstyle(1,7);
			bar(90,260,120,320);
			sleep(1);
			setfillstyle(1,0);
			bar(90,260,120,320);
		}
		if(a=='s')
		{
				PlaySound(TEXT("A#.wav"),NULL,SND_FILENAME|SND_ASYNC);
			setfillstyle(1,7);
			bar(140,260,170,320);
			sleep(1);
			setfillstyle(1,0);
			bar(140,260,170,320);
		}
		if(a=='f')
		{
				PlaySound(TEXT("C#.wav"),NULL,SND_FILENAME|SND_ASYNC);
			setfillstyle(1,7);
			bar(240,260,270,320);
			sleep(1);
			setfillstyle(1,0);
			bar(240,260,270,320);
		}
		if(a=='d')
		{
					PlaySound(TEXT("C1.wav"),NULL,SND_FILENAME|SND_ASYNC);
			setfillstyle(1,7);
			bar(290,260,320,320);
			sleep(1);
			setfillstyle(1,0);
			bar(290,260,320,320);
		}
		if(a=='[')
		{
				PlaySound(TEXT("D#.wav"),NULL,SND_FILENAME|SND_ASYNC);
			setfillstyle(1,7);
			bar(340,260,370,320);
			sleep(1);
			setfillstyle(1,0);
			bar(340,260,370,320);
		}
		if(a=='h')
		{
				PlaySound("D#1.wav",NULL,SND_FILENAME|SND_ASYNC);
			setfillstyle(1,7);
			bar(440,260,470,320);
			sleep(1);
			setfillstyle(1,0);
			bar(440,260,470,320);
		}
		if(a=='j')
		{
				PlaySound(TEXT("C#.wav"),NULL,SND_FILENAME|SND_ASYNC);
			setfillstyle(1,7);
			bar(490,260,520,320);
			sleep(1);
			setfillstyle(1,15);
			bar(490,260,520,320);
		}
			if(a=='z')
		{
				PlaySound(TEXT("D.wav"),NULL,SND_FILENAME|SND_ASYNC);
			setfillstyle(1,4);
			bar(60,320,100,390);
			sleep(1);
			setfillstyle(1,15);
			bar(60,320,100,390);
		}
		if(a=='x')
		{
			PlaySound(TEXT("D1.wav"),NULL,SND_FILENAME|SND_ASYNC);
			setfillstyle(1,4);
			bar(110,320,150,390);
			sleep(1);
			setfillstyle(1,15);
			bar(110,320,150,390);
		}
			if(a=='c')
		{
				PlaySound(TEXT("A.wav"),NULL,SND_FILENAME|SND_ASYNC);
			setfillstyle(1,4);
			bar(160,320,200,390);
			sleep(1);
			setfillstyle(1,15);
			bar(160,320,200,390);
		}
		if(a=='v')
		{
				PlaySound(TEXT("E.wav"),NULL,SND_FILENAME|SND_ASYNC);
			setfillstyle(1,4);
			bar(210,320,250,390);
			sleep(1);
			setfillstyle(1,15);
			bar(210,320,250,390);	
		} 
		if(a=='b')
		{
				PlaySound(TEXT("C.wav"),NULL,SND_FILENAME|SND_ASYNC);
			setfillstyle(1,4);
			bar(260,320,300,390);
			sleep(1);
			setfillstyle(1,15);
			bar(260,320,300,390);	
		} 
		if(a=='n')
		{
				PlaySound(TEXT("E1.wav"),NULL,SND_FILENAME|SND_ASYNC);
			setfillstyle(1,4);
			bar(310,320,350,390);
			sleep(1);
			setfillstyle(1,15);
			bar(310,320,350,390);	
		}
		if(a=='m')
		{
				PlaySound("F1.wav",NULL,SND_FILENAME|SND_ASYNC);
			setfillstyle(1,4);
			bar(360,320,400,390);
			sleep(1);
			setfillstyle(1,15);
			bar(360,320,400,390);	
		}
			if(a==',')
		{
				PlaySound("G#.wav",NULL,SND_FILENAME|SND_ASYNC);
			setfillstyle(1,4);
			bar(410,320,450,390);
			sleep(1);
			setfillstyle(1,15);
			bar(410,320,450,390);	
		}
			if(a=='.')
		{
				PlaySound("G#.wav",NULL,SND_FILENAME|SND_ASYNC);
			setfillstyle(1,4);
			bar(460,320,500,390);
			sleep(1);
			setfillstyle(1,15);
			bar(460,320,500,390);	
		}	 	 
				if(a=='/')
		{
				PlaySound("G.wav",NULL,SND_FILENAME|SND_ASYNC);
			setfillstyle(1,4);
			bar(510,320,550,390);
			sleep(1);
			setfillstyle(1,15);
			bar(510,320,550,390);	
		}
					if(a=='g')
		{
				PlaySound("Dq1_Drum.wav",NULL,SND_FILENAME|SND_ASYNC);
			setfillstyle(1,7);
			bar(490,260,520,320);
			sleep(1);
			setfillstyle(1,0);
			bar(490,260,520,320);	
		}
			if(a=='@')
			{
				return 0;
			}
	}
}
int main()
{
	welcome();
	Routing r;
	r.Input();
	int a;
	cout<<"Enter 1 to start piano";
	cin>>a;
	if(a==1)
	{
	piano obj1;
	obj1.pianomain();
	}
}

 
