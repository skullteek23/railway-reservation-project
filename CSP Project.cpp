//************************************************************************
//                                             HEADER FILES USED IN THE PROGRAM
//*************************************************************************
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<iomanip.h>
#include<fstream.h>

//*************************************************************************
//                                                      GLOBAL DECLARATIONS
//*************************************************************************
char f[10]="f";
char s[10]="s";
int addr,ad,flag,f1,d,m,i,amt;
float tamt;

//*************************************************************************
//                                                   CLASS USED IN PROGAM
//*************************************************************************
class login { public:                                                  // TO GET ID AND PASSWORD FROM USER
 char id[100];
 char pass[100];
 char password[100];

 void getid() {
 cout<<"Enter your id:";gets(id);
 puts("Enter the password:");gets(password);
 strcpy(pass,password);
 }
 void displayid() {
 cout<<"Id:";puts(id);
 cout<<"Password:";puts(pass);
 }
};

class detail{public:
 int tno;
 char tname[100];

 char bp[100];
 char dest[100];
 int c1,c1fare;
 int c2,c2fare;
 int d,m,y;

 void getdetail() {
 cout<<"Enter the details as follows\n";
 cout<<"Train no:";cin>>tno;
 cout<<"Train name:";gets(tname);
 cout<<"Boarding point:";gets(bp);
 cout<<"Destination pt:";gets(dest);
 cout<<"No of seats in first class & fare per ticket:";
 cin>>c1>>c1fare;
 cout<<"No of seats in second class & fare per ticket:";
 cin>>c2>>c2fare;
 cout<<"Date of travel:";cin>>d>>m>>y;
 }

 void displaydetail() {
 cout<<tno<<"\t"<<tname<<"\t"<<bp<<"\t"<<dest<<"\t";
 cout<<c1<<"\t"<<c1fare<<"\t"<<c2<<"\t"<<c2fare<<"\t";
 cout<<d<<"-"<<m<<"-"<<y<<"\t"<<endl;
 }
};

class reser{public:
 int pnr;
 int tno;
 char tname[100];
 char bp[10];
 char dest[100];
 char pname[10][100];
 int age[20];
 char clas[10];
 int nosr;
 int i;
 int d,m,y;
 int con;
 float amc;

 void getresdet() {                                                                // TO INPUT RESERVATION DETAILS
 cout<<"Enter the details as follows\n";
 cout<<"Train no:";cin>>tno;
 cout<<"Train name:";gets(tname);
 cout<<"Boarding point:";gets(bp);
 cout<<"Destination pt:";gets(dest);
 cout<<"No of seats required:";cin>>nosr;
 for(i=0;i<nosr ;i++) {
 cout<<"Passenger name:";gets(pname[i]);
 cout<<"Passenger age:";cin>>age[i];
 }
 cout<<"Enter the class f-first class s-second class:";
 gets(clas);
 cout<<"Date of travel:";cin>>d>>m>>y;
 cout<<"Enter the concession category\n";
 cout<<"1.Military\n2.Senior citizen\n";
 cout<<"3.Children below 5 yrs\n4.None\n";
 cin>>con;
 cout<<"............END OF GETTING DETAILS............\n";
 }

 void displayresdet() {                                                            // TO DISPLAY RESERVATION DETAILS
 cout<<"...............................................\n";
 cout<<"...............................................\n";
 cout<<"Pnr no:"<<pnr;
 cout<<"\nTrain no:"<<tno;
 cout<<"\nTrain name:";puts(tname);
 cout<<"Boarding point:";puts(bp);
 cout<<"Destination pt:";puts(dest);
 cout<<"No of seats reserved:"<<nosr;
 for(i=0;i<nosr;i++) {
 cout<<"Passenger name:";puts(pname[i]);
 cout<<"Passenger age:"<<age[i];
 }

 cout<<"\nYour class:";puts(clas);
 cout<<"\nDate of reservation:"<<d<<"-"<<m<<"-"<<y;
 cout<<"\nYour concession category:"<<con;
 cout<<"\nYou must pay:"<<amc<<endl;
 cout<<"***********************************************\n";
 cout<<".........END OF RESERVATION.................\n";
 cout<<"***********************************************\n";
 }
};

void manage();
 void user();
void database();
 void res();
void reserve();
 void enquiry();


//*************************************************************************
//                                       THE MAIN FUNCTION OF THE PROGRAM
//*************************************************************************
void main() {
 clrscr();
 int ch;
 cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
 cout<<".......WELCOME TO RAILWAY RESERVATION SYSTEM..........\n";
 cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
 do {
 cout<<"^^^^^^^^^^^^^^^^^^^^^^MAIN MENU^^^^^^^^^^^^^^^^^^^^\n";
 cout<<"1.Admin mode\n2.User mode\n3.Exit\n";
 cout<<"Enter your choice:";
 cin>>ch;
 cout<<endl;
 switch(ch) {
 case 1:
 database();
 break;
 case 2:
 user();
 break;
 case 3:
 exit(0);
 }
 }while(ch<=3);
 getch();
 }


 //*************************************************************************
 //                                                 FOR ADMINISTRATORS ONLY
 //*************************************************************************
 void database() {
 char password[25];
 char *pass="admin";
 puts("Enter the administrator password:");gets(password);
 char c;
 detail a;
 fstream f;
 int ch;
 if(strcmp(pass,password)!=0) {
 cout<<"Enter the password correctly \n";
 cout<<"You are not permitted to logon this mode\n";
 goto h;
 }
 if(strcmp(pass,password)==0) {
 do {
 cout<<"...........ADMINISTRATOR MENU...........\n";
 cout<<"1.Create detail data base\n2.Add details\n";
 cout<<"3.Display details\n4.User management\n";
 cout<<"5.Return to main menu\n";
 cout<<"Enter your choice:";
 cin>>ch;
 cout<<endl;

 switch(ch) {
 case 1:
 f.open("t.txt",ios::out|ios::binary);
 do {
 a.getdetail();
 f.write((char *) & a,sizeof(a));
 cout<<"Do you want to add one more record?\n";
 cout<<"y-for Yes\nn-for No\n";
 cin>>c;
 }while(c=='y');
 f.close();
 break;
 case 2:
 f.open("t.txt",ios::out|ios::binary|ios::app);
 a.getdetail();
 f.write((char *) & a,sizeof(a));
 f.close();
 break;
 case 3:
 f.open("t.txt",ios::in|ios::binary|ios::app);
 f.seekg(0);
 while(f.read((char *) & a,sizeof(a))) {
  a.displaydetail();
 }
 f.close();
 break;
 case 4:
manage();
 break;
 }
 }while(ch<=4);

 f.close();
 }
 h:
}



//*************************************************************************
 //                                                 FUNCTION TO MAKE RESERVATIONS
 //*************************************************************************
 void reserve() {
 int ch;
 do {
 cout<<"1.Reserve\n2.Return to the main menu\n";
 cout<<"Enter your choice:";
 cin>>ch;
 cout<<endl;
 switch(ch) {
 case 1:
 res();
 break;
 }
 }while(ch==1);
 getch();
 }

 void res() {
 detail a;
 reser b;
 fstream f1,f2;
 f1.open("t.txt",ios::in|ios::out|ios::binary);
 f2.open("p.txt",ios::out|ios::binary|ios::app);
 int ch;
 b.getresdet();
 while(f1.read((char *) &a,sizeof(a))) {
 if(a.tno==b.tno) {
 if(strcmp(b.clas,f)==0) {
 if(a.c1>=b.nosr) {
 amt=a.c1fare;
 addr=f1.tellg();
 ad=sizeof(a.c1);
 f1.seekp(addr-(7*ad));
 a.c1=a.c1-b.nosr;
 f1.write((char *) & a.c1,sizeof(a.c1));
 if(b.con==1) {
 cout<<"Concession category:MILITARY PERSONNEL\n";

 b.amc=b.nosr*((amt*50)/100);
 }
 else if(b.con==2) {
 cout<<"Concession category:SENIOR CITIZEN\n";
 b.amc=b.nosr*((amt*60)/100);
 }
 else if(b.con==3) {
 cout<<"Concession category:CHILDERN BELOW FIVE\n";
 b.amc=0.0;
 }
 else if(b.con==4) {
 cout<<"You cannot get any concession\n";
 b.amc=b.nosr*amt;
 }
 f2.write((char *) & b,sizeof(b));
 b.displayresdet();
 cout<<"------------------------------------------------------\n";
 cout<<"--------------Your ticket is reserved-----------\n";
 cout<<"-----------------End of reservation menu-------\n";
 }
 else cout<<"**********Sorry req seats not available********\n";
 }
 else if(strcmp(b.clas,s)==0) {
 if(a.c2>=b.nosr) {
 amt=a.c2fare;
 addr=f1.tellg();
 ad=sizeof(a.c2);
 f1.seekp(addr-(5*ad));
 a.c2=a.c2-b.nosr;
 f1.write((char *) & a.c2,sizeof(a.c2));
 if(b.con==1) {
 cout<<"Concession category:MILITARY PRESONNEL\n";
 b.amc=b.nosr*((amt*50)/100);
 }
 else if(b.con==2) {
 cout<<"Concession category:SENIOR CITIZEN\n";
 b.amc=b.nosr*((amt*60)/100);
 }
 else if(b.con==3) {
 cout<<"Concession category:CHILDERN BELOW FIVE\n";
 b.amc=0.0;
 }
 else if(b.con==4) {
 cout<<"You cannot get any concession\n";
 b.amc=b.nosr*amt;
 }
 f2.write((char *) & b,sizeof(b));
 b.displayresdet();
 cout<<"---------------------------------------\n";
 cout<<"--------Your ticket is reserved--------\n";
 cout<<"------------End of reservation---------\n";
 }
 else cout<<"********Sorry req no of seats not available*******\n";
 }
 getch();

 goto h;
 }
 else flag=0;
 }
 if(flag==0) {
 cout<<"............Wrong train no......................\n";
 cout<<"......Enter the train no from the data base.....\n";
 }
 f1.close();
 f2.close();
 getch();
 h:
 }

 void enquiry() {                                                                               // TO MAKE AN EQUIRY

 fstream f;
 f.open("t.txt",ios::in|ios::binary);
detail a;
while(f.read((char *) & a,sizeof(a)))
{
a.displaydetail();
}
getch();
}

//*************************************************************************
//                                                          FOR GENERAL USERS
//*************************************************************************
 void user() {
 login a;
 int ch;
 cout<<"*****************************************************\n";
 cout<<"***********WELCOME TO THE USER MENU**\n";
 cout<<"****************************************************\n";
 char password[25];

 fstream f;
 f.open("id.txt",ios::in|ios::binary);
 char id[100];
 puts("Enter your id:");gets(id);
 puts("Enter your password:");gets(password);
 while(f.read((char *) & a,sizeof(a))) {
 if((strcmp(a.id,id)==0)&&(strcmp(a.pass,password)==0)) {
 do {
 cout<<"1.Reserve\n2.Enquiry\n3.Return to the main menu\n";
 cout<<"Enter your choice:";
 cin>>ch;
 cout<<endl;
 switch(ch) {
 case 1:
 reserve();
 break;
 case 2:
 enquiry();
 break;
 }
 }while(ch<=2);
 goto j;
 }
 else d=1;
 }
 if(d==1) cout<<"Enter your user id and password correctly\n";

 getch();
 j:
}

//*************************************************************************
//                                         FOR MANAGEMENT INTENDED PURPOSE ONLY
//*************************************************************************
void manage() {
 int ch,click;
 fstream f;
 login a;
 cout<<".........WELCOME TO THE USER MANAGEMENT MENU........\n";
 do {
  cout<<"1.Create id data base\n2.Add details\n";
  cout<<"3.Display details\n4.Return to the main menu\n";
  cout<<"Enter your choice:";
  cin>>ch;
  cout<<endl;
  switch(ch) {
   case 1:
    f.open("id.txt",ios::out|ios::binary);
    do {
     a.getid();
     f.write((char*)&a,sizeof(a));
     cout<<"Do you want to add one more record\n";
     cout<<"1-Yes\n2-No\n";cin>>click;
     if(click!=1&&click!=2) cout<<"\nInvalid input\n";
    }while(click==1);
    f.close();
    break;

   case 2:
    f.open("id.txt",ios::out|ios::binary|ios::app);
    a.getid();
    f.write((char*)&a,sizeof(a));
    f.close();
    break;

   case 3:
    f.open("id.txt",ios::in|ios::binary);
    f.seekg(0);
    while(f.read((char*)&a,sizeof(a))) {
     a.displayid();
    }
    f.close();
   break;
  }
 }while(ch<=3);
}
//*************************************************************************
//                                                                         THE END
//*************************************************************************
