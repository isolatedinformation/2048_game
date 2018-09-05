#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
#include<iomanip.h>
#include<dos.h>
#include<time.h>
#define loop(i,j) for(i=0;i<j;i++)
int add[3]={2,4,2};
class score
{
	public:
	int score;
	char pname[30];

	void disp(){cout<<"Name: "<<pname<<setw(11)<<"\tScore: "<<score<<endl;}
};

class g2048
{
 int a[4][4];
 score S;
 int temp,i,j,k,q,r,g,f1,f2;
 char p[20];


 public:
 g2048();
 void up();
 void down();
 void left();
 void right();
 void scoresave();
 void ARN();  //ARN-addition of random no. to the game
 void output();
 int check();
 void in();

};
void g2048::in()
{f1=0;
  do
  {
  cin.getline(p,20,'\n');
 if(p[0]=='w')
 up();
 if(p[0]=='s')
 down();
 if(p[0]=='d')
 right();
 if(p[0]=='a')
 left();
 else
 {f1=1;
   cout<<"\nWrong input"; }
}while(f1);

}
g2048::g2048()
{ loop(i,4)
   loop(j,4)
    a[i][j]=0;
cout<<"press w to move the tiles up \ns to move them down \na to move them left \nd to move them right\n";
cout<<"Enter your name"<<endl;
cin>>S.pname;
getch();
S.score=0;
f2=0;
output();
}

void g2048::ARN()
{

 int k=0;
loop(i,4)
  loop(j,4)
   if(a[i][j]==0)
       k=1;
if(k==1)
{  q=random(4);
   r=random(4);
 while(a[q][r]!=0)
 {
   q=random(4);
   r=random(4);

  }

	g=random(3);
	a[q][r]=add[g];
}
else
{cout<<"\nIllegal move.Try some other move";
 in();
}
}
void g2048::left()//completed!!!
{
 loop(i,4)
 {loop(k,3)
  {j=2-k;
   if(a[i][j]==0)
     while((j+1)<=3)
     {
      a[i][j]=a[i][j+1];
      a[i][j+1]=0;
      j++;
     }}
   loop(k,3)
   {j=k;
    if(a[i][j]==a[i][j+1])
    {a[i][j]+=a[i][j+1];
     S.score+=a[i][j];
     a[i][j+1]=0;
     j++;
     while((j+1)<=3)
     {
      a[i][j]=a[i][j+1];
      a[i][j+1]=0;
      j++;
     }}}}
check();
}
void g2048::right()//completed!!
{
 loop(i,4)
 {loop(j,3)
  {
   k=j+1;
   if(a[i][k]==0)
     while((k-1)>=0)
      {
      a[i][k]=a[i][k-1];
      a[i][k-1]=0;
      k--;
      }}
   loop(j,3)
   {k=3-j;
   if((a[i][k]==a[i][k-1])&&(a[i][k]!=0))
    {
     a[i][k]+=a[i][k-1];
     S.score+=a[i][k];
     a[i][k-1]=0;
     k--;
    while((k-1)>=0)
      {
      a[i][k]=a[i][k-1];
      a[i][k-1]=0;
      k--;
      }}}}
check();
}

void g2048::up()//completed!!!
{
 loop(i,4)
 {loop(k,3)
  {j=2-k;
   if(a[j][i]==0)
     while((j+1)<=3)
     {
      a[j][i]=a[j+1][i];
      a[j+1][i]=0;
      j++;
     }}
   loop(k,3)
   {j=k;
    if(a[j][i]==a[j+1][i])
    {a[j][i]+=a[j+1][i];
     S.score+=a[j][i];
     a[j+1][i]=0;
     j++;
     while((j+1)<=3)
     {
      a[j][i]=a[j+1][i];
      a[j+1][i]=0;
      j++;
     }}}}
check();
}
void g2048::down()//completed!!
{
 loop(i,4)
 {loop(j,3)
  {
   k=j+1;
   if(a[k][i]==0)
     while((k-1)>=0)
      {
      a[k][i]=a[k-1][i];
      a[k-1][i]=0;
      k--;
      }}
   loop(j,3)
   {k=3-j;
   if((a[k][i]==a[k-1][i])&&(a[k][i]!=0))
    {
     a[k][i]+=a[k-1][i];
     S.score+=a[k][i];
     a[k-1][i]=0;
     k--;
    while((k-1)>=0)
      {
      a[k][i]=a[k-1][i];
      a[k-1][i]=0;
      k--;
      }}}}
check();
}



int g2048::check()
{char c[10];
 loop(i,4)
 loop(j,4)
 if (a[i][j]==2048)
 {if(f2==0)
 {delay(3000);
  f2=1;
  clrscr();
  cout<<"\nYou have finished the game!! Congratulations"<<endl;
  getch();
  cout<<"\nEnter 1 to end game, any other key to continue playing";
  cin>>c;
  if(c[0]=='1')
  {
   scoresave();
  }
  output();
  }}
 f1=0;//f2=0;
 loop(i,3)
 loop(j,3)
 if((a[i][j]==a[i+1][j])||(a[i][j]==a[i][j+1]))
   f1=1;
 loop(i,4)
 loop(j,4)
  if(a[i][j]==0)
   f1=1;
 if(f1)
 {output();
 }
 return(0);
}
void g2048::output()
{
 clrscr();
 loop(i,4)
 { loop(j,4)
	{
		cout<<"|";
	     if(a[i][j]!=0)
	       {cout<<setw(4)<<a[i][j];}
	     else if(a[i][j]==0)
	      {cout<<"    ";}
	}
	cout<<"|"<<endl;
}
delay(300);
ARN();
clrscr();
loop(i,4)
 { loop(j,4)
	{	cout<<"|";
	     if(a[i][j]!=0)
	       {cout<<setw(4)<<a[i][j];}
	     else if(a[i][j]==0)
	      {cout<<"    ";}
	}
	cout<<"|"<<endl;
}
gotoxy(10,7);
cout<<"Score: "<<S.score<<endl;
in();
}
void g2048::scoresave()
{
	ofstream fout("data.dat",ios::app|ios::binary);
	ofstream fout2("hof.dat",ios::app|ios::binary);
	fout.write((char*)&S,sizeof(S));
	if(f2==1)
	fout2.write((char*)&S,sizeof(S));
	fout.close();
	fout2.close();
}
void opensave()
{       int ptr=0,max,i;
	ifstream fin("data.dat",ios::binary);
	score ob[20];
	clrscr();
	cout<<"Scoreboards\n";
	while((fin.read((char*)&ob[ptr],sizeof(ob[ptr])))&&(ptr<=20))
	{ ob[ptr].disp();
	  ptr++;
	}
	fin.close();

}
void openhof()
{       int ptr=0,max,i;
	ifstream fin("hof.dat",ios::binary);
	score ob[20];
	clrscr();
	cout<<"Hall of Fame\n";
	while((fin.read((char*)&ob[ptr],sizeof(ob[ptr])))&&(ptr<=20))
	{ ob[ptr].disp();
	  ptr++;
	}
	fin.close();
    if(ptr==0)
    cout<<"\nNo Player has finished the game\n";
    else
    cout<<"Note:Players listed above have finished the game (got 2048)\n     and hence have entered the Hall of Fame\n";
}

void instructions()
{       clrscr();
	int x;
	cout<<"\t\t\tINSTRUCTIONS\n";
	cout<<"The primary objective of this game is to achieve the highest number possible by adding same numbers."<<endl;
	cout<<"The numbers that you will be adding are the exponents of the number 2";
	cout<<".\nPress 1 to go back";
	cin>>x;
	if(x==1)
	clrscr();
}
void menu()
{
   int i;
   do
   {
	cout<<"\t\t\tMENU:\n";
	cout<<"\t\t\t1.Play Game\n";
	cout<<"\t\t\t2.Scoreboards\n";
	cout<<"\t\t\t3.Hall of Fame\n";
	cout<<"\t\t\t4.Instructions\n";
	cout<<"\t\t\t5.Exit\n";
	cin>>i;
	switch(i)
	{
		case 1: clrscr();
			g2048 newgame;
			cout<<"Game Over !!!"<<endl;
			newgame.scoresave();
			break;
		case 2: opensave();
			break;
		case 3: openhof();
			break;
		case 4:instructions();
			break;
		case 5: exit(0);
	 }
   getch();
   }while (i!=5);
}
void spacing()
{
	clrscr();
	int i,x,y,j;
	//this for 2
	for(i=1;i<=3;i++)
	{  gotoxy(18,i*6);
	   loop(j,9)
	  {delay(40); cout<<"=";}
	}
	for(i=7;i<=11;i++)
	{
		gotoxy(26,i);
		delay(40);
		cout<<"||";
	}
	for(i=13;i<18;i++)
	{
		gotoxy(17,i);
		delay(40);
		cout<<"||";
	}
       //this for 0
	for(i=1;i<=3;i+=2)
	{  gotoxy(29,i*6);
	  loop(j,9)
	  {delay(40); cout<<"=";}
	}
	for(i=7;i<18;i++)
	{
		gotoxy(37,i);
		delay(40);
		cout<<"||";
	}
	for(i=7;i<18;i++)
	{
		gotoxy(28,i);
		delay(40);
		cout<<"||";
	}
	//this is for 4
	for(i=7;i<=15;i++)
	{
		gotoxy(40,i);
		delay(40);
		cout<<"||";
	}
	gotoxy(41,16);
	loop(j,9)
	{delay(40);cout<<"=";}
	for(i=13;i<=18;i++)
	{
		gotoxy(46,i);
		delay(40);
		cout<<"||";
	}
	//this for 8
	for(i=1;i<=3;i++)
	{  gotoxy(54,i*6);
	  loop(j,9)
	{delay(40);cout<<"=";}
	}
	for(i=7;i<18;i++)
	{
		gotoxy(62,i);
		delay(40);
		cout<<"||";
	}
	for(i=7;i<18;i++)
	{
		gotoxy(53,i);
		delay(40);
		cout<<"||";
	}
	gotoxy(62,21);
	cout<<"1 to enter game";
	gotoxy(62,22);
	cout<<"0 to exit";
	cin>>x;
	if(x==1)
       {clrscr();
	menu();  }
	else
	exit(0);
	getch();

}

void main()
{
	clrscr();
	spacing();
	getch();
}



