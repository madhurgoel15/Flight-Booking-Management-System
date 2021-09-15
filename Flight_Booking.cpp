#include<iostream>
#include<string.h>
#include<ctime>
#include<cstdlib>
using namespace std;
char places[][12]={{"New
Delhi"},{"Chennai"},{"Kolkata"},{"Bangalore"},{"Mumbai"},{"Hyderabad"},{"Sydney"},{"New
York"},{"Berlin"},{"Paris"},{"Tokyo"},{"Beijing"}};
char airl[][10]={{"Vistara"},{"Indigo"},{"Air India"},{"Air
Asia"},{"Virgin"},{"Emirates"},{"Lufthansa"},{"Eva"},{"Qatar"},{"Qantas"}};
class booking
{
 long int pnr;
 char name[20];
 long long int number;
 long int dob;
 char email[20];
 int source;
 int destination;
 int airln;
 long int doj;
public:
 booking *next;
 void get_source()
 {cin>>source;}
 void get_dest()
 {cin>>destination;}
 void get_airl(int s)
 {airln=s;}
 void get_doj()
 {cin>>doj;}
 void get_detail();
 void view_detail();
 void get_pnr()
 {pnr=(rand()%1000000)+99999;}
 int give_source()
 {return(source);}
 int give_dest()
 {return(destination);}
 int give_airl()
 {return(airln);}
 long int give_pnr()
 {return(pnr);}
}*frnt,*rear;
void new_booking();
void del_booking();
void view_booking();
int payment();
int fare(int x,int y);
bool isempty();
booking* insertt();
int view_booking(long int qq);
int del_booking(long int qq);
int main()
{
 while(1)
 {
 cout<<"\n\n--------------------------------------------------------------";
 cout<<"\n\t\tWelcome to BookMyFlight";
 cout<<"\n--------------------------------------------------------------";
 cout<<"\n\nMenu\n";
 cout<<"\n1. Book a New Flight";
 cout<<"\n2. Cancel Existing Booking";
 cout<<"\n3. View Booked Ticket";
 cout<<"\n4. Exit\n";
 int ch;
 cin>>ch;
 switch(ch)
 {
 case 1:
 new_booking();
 break;
 case 2:
 long int qw;
 cout<<"\nEnter PNR to Cancel Booking : ";
 cin>>qw;
 if(del_booking(qw))
 cout<<"\nBooking Cancelled with PNR : "<<qw<<endl<<"\nRefund will be credited
back to original mode of payment within 3 working days";
 else
 cout<<"\nNo Booking Found with the Given PNR!!!!";
 break;
 case 3:
 long int qwq;
 cout<<"\nEnter PNR to View Booking : ";
 cin>>qwq;
 if(!(view_booking(qwq)))
 cout<<"\nNo Booking Found with the Given PNR!!!!";
 break;
 case 4:
 exit(1);
 default:
 cout<<"Wrong Choice!!!!";
 }
 }
}
void new_booking()
{
 booking *neww;
 neww=insertt();
 cout<<"\nChoose Source & Destination ";
 cout<<"\n1. New Delhi"<<"\n2. Chennai"<<"\n3. Kolkata"<<"\n4. Bangalore"<<"\n5.
Mumbai"<<"\n6. Hyderabad"<<"\n7. Sydney"<<"\n8. New York"<<"\n9. Berlin"<<"\n10.
Paris"<<"\n11. Tokyo"<<"\n12. Beijing\n";
 neww->get_source();
 neww->get_dest();
 if(neww->give_dest()==neww->give_source())
 {
 cout<<"\nSource and Destination Cannot be Same!!!!";
 exit(-1);
 }
 cout<<"\nEnter Date of Journey (DDMMYY)";
 neww->get_doj();
 cout<<"\nSelect Airline : ";
 int xl;
 if(neww->give_source()<7 && neww->give_dest()<7 )
 {
 for(int i=0;i<4;i++)
 cout<<i+1<<". "<<airl[i]<<" ";
 cout<<endl;
 cin>>xl;
 neww->get_airl(xl);
 }
 else
 {
 for(int i=4;i<10;i++)
 cout<<i-3<<"."<<airl[i]<<" ";
 cout<<endl;
 cin>>xl;
 xl+=4;
 neww->get_airl(xl);
 }
 cout<<"\nFare is : Rs."<<fare((neww->give_source()-1),(neww->give_dest()-1));
 cout<<"\nConfirm Booking (1. YES or 2.NO)\n";
 int cnf=0;
 cin>>cnf;
 if(cnf==1)
 {
 neww->get_detail();
 if(payment())
 {
 neww->get_pnr();
 neww->view_detail();
 }
 }
 else
 {
 cout<<"\nBooking Process Cancelled!!!!";
 exit(-1);
 }
}
void booking::get_detail()
{
 cout<<"\nEnter Name : ";
 cin>>name;
 cout<<"\nEnter Contact Number : ";
 cin>>number;
 cout<<"\nEnter Email ID : ";
 cin>>email;
 cout<<"\nEnter DOB (DDMMYYYY) : ";
 cin>>dob;
}
void booking :: view_detail()
{
 cout<<"\nName : "<<name;
 cout<<"\nContact Number : "<<number;
 cout<<"\nEmail ID : "<<email;
 cout<<"\nDOB (DDMMYYYY) : "<<dob;
 cout<<"\nSource : "<<places[source-1];
 cout<<"\nDestination : "<<places[destination-1];
 cout<<"\nAirline : "<<airl[airln-1];
 cout<<"\nDOJ (DDMMYYYY) : "<<doj;
 cout<<"\nPNR : "<<pnr;
}
int payment()
{
 int pay;
 cout<<"\nSelect Payment Method 1. Credit/Debit Card 2. Net Banking \n";
 cin>>pay;
 if(pay==1)
 {
 unsigned long long int card;
 int exp,cvv;
 cout<<"\nEnter Card Number : ";
 cin>>card;
 cout<<"\nExpiry (MMYY) : ";
 cin>>exp;
 cout<<"\nCVV : ";
 cin>>cvv;
 }
 else if(pay==2)
 {
 char id[20],pass[20];
 cout<<"\nWELCOME to NET BANKING PORTAL\n ";
 cout<<"\nEnter Login ID : ";
 cin>>id;
 cout<<"\nPassword : ";
 cin>>pass;
 }
 else
 {
 cout<<"Wrong Payment Method!!!! ";
 exit(-1);
 }
 cout<<"\nBooking Confirmed!!!!";
 return(1);
}
int fare(int x,int y)
{
 srand(time(0));
 int fares[12][12];
 for(int i=0;i<12;i++)
 for(int j=0;j<12;j++)
 {
 if(i==j)
 fares[i][i]=0;
 else if(i<6 && j<6)
 fares[i][j]=(rand() % 5001) + 3000;
 else
 fares[i][j]=(rand() % 300001) + 100000;
 }
 return (fares[x][y]);
}
booking* insertt()
{
 booking* p=new booking;
 p->next=NULL;
 if(frnt==NULL && rear==NULL)
 frnt=p;
 else
 rear->next=p;
 rear=p;
 return p;
}
int del_booking(long int qq)
{
 int s=0;
 if(isempty())
 {
 cout<<"Error No Booking Found!!!!";
 exit(-1);
 }
 else
 {
 booking *a;
 a=frnt;
 if(frnt==rear && a->give_pnr()==qq)
 {
 frnt=NULL;
 rear=NULL;
 delete a;
 s=1;
 }
 else
 {
 booking *b;
 b=frnt->next;
 while(b!=NULL)
 {
 if(b->give_pnr()==qq)
 {
 a->next=b->next;
 delete b;
 s=1;
 }
 a=a->next;
 b=b->next;
 }
 }
 }
 return s;
}
bool isempty()
{
 if(frnt==NULL && rear==NULL)
 return true;
 else
 return false;
}
int view_booking(long int qq)
{
 int s=0;
 if(isempty())
 {
 cout<<"Error No Booking Found!!!!";
 exit(-1);
 }
 else
 {
 booking *k;
 k=frnt;
 while(k!=NULL)
 {
 if(k->give_pnr()==qq)
 {
 k->view_detail();
 break;
 s=1;
 }
 k=k->next;
 }
 }
 return s;
}