//============================================================================
// Name        : miniproject.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<string.h>
#include<stack>
using namespace std;
stack<int>s;
#define max 10
using namespace std;

class node
{
	friend class list;

	node *next;
public:
	int tickno;
	node(int d,char s[20])
	{
		tickno=0;
		next=NULL;
	}
};
class list
{
	node *start,*ptr;
public:
	friend class book;

	list()
	{
		start=NULL;
	}
	//void display()
	void tick()
	{
		node *ptr;
		ptr=start;
  while(ptr!=NULL)
  {


	 ptr=ptr->next;

  }
  }
};


class dnode
{
	int seat;
	int Row;
	//char name[50];
	//int data;
	dnode *prev;
	dnode *next;
public :
	dnode(int row,int d)
{
		seat=d;
		Row=row;
		prev=NULL;
		next=NULL;
}
	dnode()
	{
		prev=NULL;
		next=NULL;
	}
	friend class bookings;
};
class bookings
{
	dnode *start;
public:
	bookings()
		{
			start=NULL;
		}
	void event();
	bookings comedy();
	void confernce();
	void exhibition();
	void plays();
	void display();
	void display1(int,char [],int,int, int,int,int);
	void display2(int,char [],int,int, int,int,int);

 };
void bookings::event()
{
	int choice,ch,ctr=0,num,i=0,op;
	char ch1;

	do{
	cout<<"\n\t\tSEARCH FOR AN EVENT";
	cout<<"\n\t1.COMEDY\t\t2.PLAYS AND CONCERTS";
	cin>>op;
	switch(op)
	{
	case 1:comedy();
			//display1();
			break;


	case 2:plays();
			break;
	default:
		cout<<"INVALID CHOICE";
	}
	cout<<"DO YOU WANT TO BOOK SEATS FOR ANNOTHER EVENT";
	cin>>ch1;
	}while(ch1=='y'||ch1=='Y');
}
bookings bookings::comedy()
{
	int ch,ctr=0,num,i=0,op;
	char choice='Y',ans;
	int d;
	int hall,tickno,time;
	char city[50];
		dnode *temp,*ptr;
		bookings p;
		//ptr=p.start;
		char name[40];
do{
	cout<<"SELECT YOUR CHOICE=>";
				cout<<"\n\t1.Kochin Komedians Featuring Utsav Chakraborty and Rupen Paul\n\t2.COMEDY NIGHTS WITH KAPIL LIVE SHOW\n\t3.The Improv - Bangalore's Most Loved Comedy Experience for the First Time in Pune";
				cin>>ch;
				do{
					if((choice=='n'||choice=='N'))
						p.start=NULL;
				if(ctr==50)
				{
					cout<<"SORRY THEATER FULL\n";
				}
				if(p.start==NULL)
				{
					cout<<endl<<"50 SEATS AVAILABLE";
				}
				else
				{
					//display();

					ptr=p.start;
				while(ptr!=NULL)
				{
					cout<<"\t\t\t\n";
				  cout<< ptr->Row<<"=>";
				 cout<<ptr->seat<<"\t";

				 ptr=ptr->next;

				}

									cout<<endl<<50-ctr<<" "<<"SEATS AVAILABLE\n";
				}
				int row;
				jump:
				cout<<"\nCHOOSE YOUR SEAT=>\"ROW\"";
				cin>>row;
				cout<<"seat number";
				cin>>d;
				cout<<"\n\nEnter City: ";
				cin>>city;

				cout<<"\n\nTimings:\n1.10AM\t2.11AM\t3.12.30PM\t4.3PM\n\nEnter Time : ";
				cin>>time;

				cout<<"\n\nNumber of tickets: ";
				cin>>tickno;
				display1(ch,city,hall,time,row,d,tickno);




				temp=new dnode(row,d);
				if(p.start==NULL)
				{
					p.start=temp;
					ctr++;
				}
				else
				{
					ptr=p.start;
					while(ptr!=NULL)
					{
							if(ptr->seat==d&&ptr->Row==row){
								cout<<"\nALREADY BOOKED";
								//delete ptr;
								goto jump;
							}
								ptr=ptr->next;
					}

					ptr=p.start;
					while(ptr->next!=NULL)
					{
						ptr=ptr->next;
				    }
					ptr->next=temp;
					temp->prev=ptr;
					ctr++;
				}
				cout<<"\n DO YOU WANT TO BOOK MORE SEATS FOR THIS SHOW\n";
						cin>>choice;

}while(choice=='y'||choice=='Y');
				cout<<"\n DO YOU WANT TO BOOK MORE SEATS FOR ANOTHER  SHOW .\n";
																cin>>ans;
							}while(ans=='y'||ans=='Y');


}

void bookings::plays()
{
	int ch,ctr=0,num,i=0,op;
		char choice,ans;
		int d;
		int hall,tickno,time;
			char city[50];
			dnode *temp,*ptr1;
			char name[40];
do{
		cout<<"SELECT YOUR CHOICE=>";
					cout<<"\n\t1.NATSAMRAT\n\t2.ROMIO AND JULIATE\n\t";
					cin>>ch;
					do{
									if(ctr==50)
									{
										cout<<"SORRY THEATER FULL\n";
									}
									if(start==NULL)
									{
										cout<<endl<<"50 SEATS AVAILABLE";
									}
									else
									{
										//display();
										ptr1=start;
									while(ptr1!=NULL)
									{
										cout<<"\t\t\t\n";
									  cout<< ptr1->Row<<"=>";
									 cout<<ptr1->seat<<"\t";

									 ptr1=ptr1->next;

									}

														cout<<endl<<50-ctr<<" "<<"SEATS AVAILABLE\n";
									}
									int row;
									jump:
									cout<<"\nCHOOSE YOUR SEAT  \"ROW\"";
									cin>>row;
									cout<<"seat number";
									cin>>d;
									cout<<"\n\nEnter City: ";
									cin>>city;
									cout<<"\nEnter theatre:\n1.Abhiruchi City pride\n2.City Pride Kothrud"
														"\n3.Phoenix\n4.INOX\nEnter your choice : ";
									cin>>hall;
									cout<<"\n\nTimings:\n1.10AM\t2.11AM\t3.12.30PM\t4.3PM\n\nEnter Time : ";
									cin>>time;

									cout<<"\n\nNumber of tickets: ";
									cin>>tickno;
									display1(ch,city,hall,time,row,d,tickno);




									temp=new dnode(row,d);
									if(start==NULL)
									{
										start=temp;
										ctr++;
									}
									else
									{
										ptr1=start;
										while(ptr1!=NULL)
										{
												if(ptr1->seat==d){
													cout<<"\nALREADY BOOKED";
													//delete ptr;
													goto jump;
												}
													ptr1=ptr1->next;
										}

										ptr1=start;
										while(ptr1->next!=NULL)
										{
											ptr1=ptr1->next;
									    }
										ptr1->next=temp;
										temp->prev=ptr1;
										ctr++;
									}
									cout<<"\n DO YOU WANT TO BOOK MORE SEATS FOR THIS SHOW\n";
											cin>>choice;

					}while(choice=='y'||choice=='Y');
									cout<<"\n DO YOU WANT TO BOOK MORE SEATS FOR ANOTHER  SHOW .\n";
																					cin>>ans;
												}while(ans=='y'||ans=='Y');


}
void bookings::display()
{
	dnode *ptr;

	ptr=start;
while(ptr!=NULL)
{
	cout<<"\t\t\t\n";
  cout<< ptr->Row<<"=>";
 cout<<ptr->seat<<"\t";

 ptr=ptr->next;

}
}
void bookings::display1(int a,char b[10],int h,int t,int c,int s,int z)
{
	cout<<"\n\n\t\tTICKET SUMMARY!\nMOVIE\t:\t";
	{
		cout<<"COMEDY";
	}
	cout<<"\nCITY\t:\t"<<b;

	cout<<"\nTIMINGS :\t";
	{
		if(t==1)
			cout<<"10 AM";
		else if(t==2)
			cout<<"11 AM";
		else if(t==3)
			cout<<"12.30 PM";
		else
			cout<<"3 PM";
	}

	cout<<"\nTICKETS :\t";
	{
		if(c==1)
		cout<<z<<" tickets in SILVER Row G. Screen 6.";
		else if(c==2)
			cout<<z<<" tickets in GOLD Row H Screen 4.";
		else
			cout<<z<<" tickets in PLATINUM Row E. Screen 5.";
	}

	cout<<"\nYour coupon code is CPAR0002414586. Show this code at the counter, pay your cash and collect your tickets!\n\t\tThank you!";

}
void bookings::display2(int a,char b[10],int h,int t,int c,int s,int z)
{
	cout<<"\n\n\t\tTICKET SUMMARY!\nMOVIE\t:\t";
	{
		cout<<"PLAYS AND CONCERTS";
	}
	cout<<"\nCITY\t:\t"<<b;

	cout<<"\nTIMINGS :\t";
	{
		if(t==1)
			cout<<"10 AM";
		else if(t==2)
			cout<<"11 AM";
		else if(t==3)
			cout<<"12.30 PM";
		else
			cout<<"3 PM";
	}

	cout<<"\nTICKETS :\t";
	{
		if(c==1)
		cout<<z<<" tickets in SILVER Row G. Screen 6.";
		else if(c==2)
			cout<<z<<" tickets in GOLD Row H Screen 4.";
		else
			cout<<z<<" tickets in PLATINUM Row E. Screen 5.";
	}

	cout<<"\nYour coupon code is CPAR0002414586. Show this code at the counter, pay your cash and collect your tickets!\n\t\tThank you!";

}





class admin
{
	int ty1,ty2,ty3,ty4;
	char t1[10],t2[10],t3[10],t4[10];
	char movie[20];
	char event[20];
public:
	void accept_m()
	{

	cout<<"\nENTER THE MOVIE NAME\n";
	cin>>movie;
	cout<<"\nENTER THE THEATRES\n";
	cin>>t1>>t2>>t3>>t4;
	cout<<"\nENTER THE TIMINGS\n";
	cin>>ty1>>ty2>>ty3>>ty4;
	}

	void accept_e()
		{

		cout<<"\nENTER THE EVENT NAME\n";
		cin>>movie;
		cout<<"\nENTER THE TIMINGS\n";
		cin>>ty1>>ty2>>ty3>>ty4;
		}
	void display_m()
	{
		cout<<"\n MOVIE NAME: "<<movie;
		cout<<"\nTIMINGS\n" <<"\n1)"<<ty1<<"\n"<<"\n2)"<<ty2<<"\n"<<"\n3)"<<ty3<<"\n"<<"\n4)"<<ty4<<"\n";


	}

	void display_e()
	{
		cout<<"\n EVENT NAME: "<<movie;
		cout<<"\nTIMINGS\n" <<"\n1)"<<ty1<<"\n"<<"\n2)"<<ty2<<"\n"<<"\n3)"<<ty3<<"\n"<<"\n4)"<<ty4<<"\n";


	}
	void update_m()
	{
		admin p;
		int tym1,tym2,tym3,tym4;
		int pos,i,ch,ans,offset,tym;
		fstream f;
		char mov[20];

		cout<<"\nENTER MOVIE NAME\n";
		cin>>mov;
		f.open("MOVIE.txt",ios::ate);
		f.seekg(0,ios::beg);
		pos=-1;
		i=0;
		while(f.read((char*)&p,sizeof(p)))
		{
			if(strcmp(mov,p.movie)==0)
			{

				pos=i;
				break;
			}
			i++;

		}
		offset=(pos)*sizeof(p);
		f.seekp(offset);
		do{
			cout<<"\nWHAT DO YOU WANT TO CHANGE 1)TIME\n";
			cin>>ch;
			switch(ch)
			{
			case 1:
				cout<<"\nENTER THE TIMINGS YOU WANT TO KEEP NOW\n";
				cin>>tym1>>tym2>>tym3>>tym4;
				f.write((char*)&p,sizeof(p));
	p.ty1=tym1;
	p.ty2=tym2;p.ty3=tym3;p.ty4=tym4;
				cout<<"\nYOUR TIME IS UPDATED\n";
				break;
			}
			cout<<"\nDO YOU WANT TO UPDATE MORE IN THIS MOVIE-1/0\n";
		cin>>ans;
		}while(ans==1);
		f.seekg(0);
		cout<<"\nINFO UPDATED!!\n";

		f.close();

		}


	void update_e()
	{
		admin p;
		int tym1,tym2,tym3,tym4;
			int pos,i,ch,ans,offset,tym;
			fstream f;
			char eve[20];

			cout<<"\nENTER EVENT NAME\n";
			cin>>eve;
			f.open("EVENTS.txt",ios::ate|ios::in|ios::out|ios::binary);
			f.seekg(0,ios::beg);
			pos=-1;
			i=0;
			while(f.read((char*)&p,sizeof(p)))
			{
				if(strcmp(eve,p.event)==0)
				{

					pos=i;
					break;
				}
				i++;

			}
			offset=(pos)*sizeof(p);
			f.seekp(offset);
			do{

				cout<<"\nWHAT DO YOU WANT TO CHANGE 1)TIME\n";
							cin>>ch;
							switch(ch)
							{
							case 1:
cout<<"\nCURRENTS TMINGS ARE\n"<<p.ty1<<p.ty2<<p.ty3<<p.ty4;;
								cout<<"\nENTER THE TIMINGS YOU WANT TO KEEP NOW\n";
								cin>>tym1>>tym2>>tym3>>tym4;
								p.ty1=tym1;
													p.ty2=tym2;
													p.ty3=tym3;
													p.ty4=tym4;
								f.write((char*)&p,sizeof(p));

								cout<<"\nYOUR TIME IS UPDATED\n";
								break;
				}
				cout<<"\nDO YOU WANT TO UPDATE MORE IN THIS EVENT-1/0\n";
			cin>>ans;
			}while(ans==1);
			f.seekg(0);
			while(f.read((char*)&p,sizeof(p)))
			{

				display_e();
			}
			f.close();

	}
};


class user {
	int num;
	string name;
	string password;
	int i;
	friend class book;
	public :
	user () {
		i=0, num=0;
		name="Default";
		password="Default";
	}
	void accept() {
        string verify= " ";
		cout<<"Enter your data!";
		cout<<"Name";
		cin>>name;

		while(verify!=password) {
			cout<<"Password\n";
		    cin>>password;
		    cout<<"Verify password";
		    cin>>verify;

		}
        cout<<"Password recorded\n";

        num=i++;
	}

};
class book
{
 user accounts[max];
 int i ;

public:
int check;
book () {
	i=0;
	check=0;
}
void count();
void display(int,char [],int,int, int,int);
void signup();
void login() ;
};
void book :: login() {
	    int flag=0;
	    string name, password;
        cout<<"Please enter your data \n";
    	cout<<"name";
    	cin>> name;
    	cout<<"password";
    	cin>> password;
    	for(int j=0;j<max;j++) {
    		if(name==accounts[j].name && password==accounts[j].password) {
    			flag=1;
    			break;
    		}
    	}
    	if(flag ==1) {
          cout<<"Welcome back" << accounts[i].name;
          cout<<"You may proceed to your order now";
          flag=0;
          check=0;
    	}
    	else {
    		cout<<"Sorry, you are not a registered user, please signup";
            check=1;
        }
}
void book :: signup() {

   accounts[i].accept();
   i++;

}
void book::display(int a,char b[10],int h,int t,int c,int z)
{
	cout<<"\n\n\t\tTICKET SUMMARY!\nMOVIE\t:\t";
	{
		if(a==1)
			cout<<"BAAR BAAR DEKHO [Drama][Romance](U/A)";
		else if(a==2)
			cout<<"Akira [Action][Thriller](U/A)";
		else if(a==3)
		    cout<<"A Flying Jatt [Action][Comedy][Thriller](U/A)";
		else
			cout<<"Island city [Comedy][Drama](U)";
	}
	cout<<"\nCITY\t:\t"<<b;
	cout<<"\nTHEATRE :\t";
	{
		if(h==1)
			cout<<"Abhiruchi City Pride";
		else if(h==2)
			cout<<"City Pride Kothrud";
		else if(h==3)
			cout<<"Phoenix";
		else if(h==4)
			cout<<"INOX";
	}
	cout<<"\nTIMINGS :\t";
	{
		if(t==1)
			cout<<"10 AM";
		else if(t==2)
			cout<<"11 AM";
		else if(t==3)
			cout<<"12.30 PM";
		else
			cout<<"3 PM";
	}

	cout<<"\nTICKETS :\t";
	{
		if(c==1)
		cout<<z<<" tickets in SILVER Row G. Screen 6.";
		else if(c==2)
			cout<<z<<" tickets in GOLD Row H Screen 4.";
		else
			cout<<z<<" tickets in PLATINUM Row E. Screen 5.";
	}

	cout<<"\nYour coupon code is CPAR0002414586. Show this code at the counter, pay your cash and collect your tickets!\n\t\tThank you!";

}

int main()
{
	bookings k;
	book b;
	int ch,mov,mov1,tickno,time_,tic,hall;
	char city[10];
	int ans;
	cout<<"\t\t\tWELCOME TO BOOK_MY_SHOW!!\nBook tickets for movies, events and much more at a click.";
	do
	{
	cout<<"\nHOW DO YOU WANT TO LOGIN?\n1)CUSTOMER\n2)ADMIN\n";
	cin>>ch;
	switch(ch)
	{
	case 1:

	do{
	cout<<"\nChoose an activity and get started:-\n1.Sign Up for new account.\t2.Login\nYour Answer: ";
	cin>>ch;
	switch(ch)
	{
	case 1: b.signup();
	        cout<<"Please login to ur account to avail our services";
	        break;
	case 2: b.login();
	        if(b.check==0)
	        {
			cout<<"\n\nBook for 1.Movies\t2.Events Near You\nYou desire? ";
			cin>>mov;
			switch(mov)
			{
			case 1:
			cout<<"\n\n1.Baar Baar Dekho [Drama][Romance](U/A)\n2.Akira [Action][Thriller](U/A)\n3.A Flying Jatt [Action][Comedy][Thriller](U/A)"
					"\n4.Island City[Comedy][Drama](U)\n\tBOOK NOW: ";
			cin>>mov1;
			cout<<"\n\nEnter City: ";
			cin>>city;
			cout<<"\nEnter theatre:\n1.Abhiruchi City pride\n2.City Pride Kothrud"
					"\n3.Phoenix\n4.INOX\nEnter your choice : ";
			cin>>hall;
			cout<<"\n\nTimings:\n1.10AM\t2.11AM\t3.12.30PM\t4.3PM\n\nEnter Time : ";
			cin>>time_;
			cout<<"\n\nTicket rates:\n\tSILVER - 100/-\n\tGOLD - 120/-\n\tPLATINUM- 140/-\nEnter choice :  ";
			cin>>tic;
			cout<<"\n\nNumber of tickets: ";
			cin>>tickno;

			b.display(mov1,city,hall,time_,tic,tickno);
break;

			case 2:
					k.event();
			}
		    }
			break;

	}
	cout<<"\n\nAre you sure you want to leave this page or do you want to book more tickets?(1/0)";
	cin>>ans;
	} while(ans==1);
break;

	case 2:
		int pass;
		int flag;
		fstream f;
		int count;
		admin p,u;
					int password=12345;
					cout<<"\n IF YOU ARE THE ADMIN, PLEASE ENTER THE PASSWORD TO LOGIN\n";
					cin>>pass;
					if(pass==password)

						flag=1;

					else
						flag=0;

					if(flag==0)
					{
						cout<<"\nPASSWORD IS WRONG\n";
						break;
					}

					if(flag==1)
					{

						do
						{
							cout<<"\nWHAT OPERATION YOU WANT TO CARRY OUT??1)UPDATE EXISTING DATA\n2)ADD NEW DATA\n";
							cin>>ch;
							switch(ch)
							{
							case 1:
								do{
							cout<<"\nWHAT DO YOU WANT TO MODIFY\n1)MOVIES\n2)EVENTS";
							cin>>ch;
							switch(ch)
							{
							case 1:
								u.update_m();
		break;

							case 2:
								u.update_e();
								break;

							}cout<<"\n DO YOU WANT TO CONTINUE WITH THE UPDATION PROCES?-1/0\n";
							cin>>ans;
							}while(ans==1);
								break;

							case 2:

								do
								{
								cout<<"\nWHAT DO YOU WANT TO ADD 1)MOVIE 2)EVENTS\n";
								cin>>ch;
								switch(ch)
								{
								case 1:
									f.open("MOVIE.TXT",ios::out);
									do
									{
										u.accept_m();
										f.seekp(count*sizeof(p),ios::beg);
										f.write((char*)&p,sizeof(p));
										count++;
										cout<<"\n DO YOU WANT TO ADD MORE MOVIES?-1/0\n";
										cin>>ans;
									}while(ans==1);
										f.close();
										break;


								case 2:
									f.open("EVENTS.TXT",ios::out);
																do
																{
													u.accept_e();
																	f.seekp(count*sizeof(p),ios::beg);
																	f.write((char*)&p,sizeof(p));
																	count++;
																	cout<<"\n DO YOU WANT TO ADD MORE EVENTS?-1/0\n";
																	cin>>ans;
																}while(ans==1);
																	f.close();
																	break;
								}cout<<"\nDO YOU WANT TO ADD MORE MOVIES OR EVENTS ?? 1/0\n";
		cin>>ans;
								}while(ans==1);
								}cout<<"\nADMIN DO YOU WANT TO CARRY OUT ANY OTHER OPERATION?-1/0\n";
								cin>>ans;
								}while(ans==1);
						}break;

					}cout<<"\nDO YOU WANT TO LOGIN AGAIN AS ADMIN OR CUSTOMER?-1/0\n";
					cin>>ans;

				}while(ans==1);
			return 0;

}
/*

			WELCOME TO BOOK_MY_SHOW!!
Book tickets for movies, events and much more at a click.
HOW DO YOU WANT TO LOGIN?
1)CUSTOMER
2)ADMIN
1

Choose an activity and get started:-
1.Sign Up for new account.	2.Login
Your Answer: 1
Enter your data!Nametina
Password
123
Verify password123
Password recorded
Please login to ur account to avail our services

Are you sure you want to leave this page or do you want to book more tickets?(1/0)1

Choose an activity and get started:-
1.Sign Up for new account.	2.Login
Your Answer: 2
Please enter your data 
nametina
password123
Welcome backDefaultYou may proceed to your order now

Book for 1.Movies	2.Events Near You
You desire? 1


1.Baar Baar Dekho [Drama][Romance](U/A)
2.Akira [Action][Thriller](U/A)
3.A Flying Jatt [Action][Comedy][Thriller](U/A)
4.Island City[Comedy][Drama](U)
	BOOK NOW: 1


Enter City: pune

Enter theatre:
1.Abhiruchi City pride
2.City Pride Kothrud
3.Phoenix
4.INOX
Enter your choice : 2


Timings:
1.10AM	2.11AM	3.12.30PM	4.3PM

Enter Time : 2


Ticket rates:
	SILVER - 100/-
	GOLD - 120/-
	PLATINUM- 140/-
Enter choice :  2


Number of tickets: 3


		TICKET SUMMARY!
MOVIE	:	BAAR BAAR DEKHO [Drama][Romance](U/A)
CITY	:	pune
THEATRE :	City Pride Kothrud
TIMINGS :	11 AM
TICKETS :	3 tickets in GOLD Row H Screen 4.
Your coupon code is CPAR0002414586. Show this code at the counter, pay your cash and collect your tickets!
		Thank you!

Are you sure you want to leave this page or do you want to book more tickets?(1/0)0

DO YOU WANT TO LOGIN AGAIN AS ADMIN OR CUSTOMER?-1/0
1
			WELCOME TO BOOK_MY_SHOW!!
Book tickets for movies, events and much more at a click.
HOW DO YOU WANT TO LOGIN?
1)CUSTOMER
2)ADMIN
2

 IF YOU ARE THE ADMIN, PLEASE ENTER THE PASSWORD TO LOGIN
12345

WHAT OPERATION YOU WANT TO CARRY OUT??1)UPDATE EXISTING DATA
2)ADD NEW DATA
2

WHAT DO YOU WANT TO ADD 1)MOVIE 2)EVENTS
1

ENTER THE MOVIE NAME
Dont Breather

ENTER THE THEATRES
inoc
citypride
esquare

ENTER THE TIMINGS
11
12
3
4

 DO YOU WANT TO ADD MORE MOVIES?-1/0
0

DO YOU WANT TO ADD MORE MOVIES OR EVENTS ?? 1/0
0

ADMIN DO YOU WANT TO CARRY OUT ANY OTHER OPERATION?-1/0
0

DO YOU WANT TO LOGIN AGAIN AS ADMIN OR CUSTOMER?-1/0
1

HOW DO YOU WANT TO LOGIN?
1)CUSTOMER
2)ADMIN
1

Choose an activity and get started:-
1.Sign Up for new account.	2.Login
Your Answer: 1
Enter your data!Namemenal
Password
11234
Verify password2343
Password
11234
Verify password11234
Password recorded
Please login to ur account to avail our services

Are you sure you want to leave this page or do you want to book more tickets?(1/0)1

Choose an activity and get started:-
1.Sign Up for new account.	2.Login
Your Answer: 2
Please enter your data 
namemeenal
password11234
Sorry, you are not a registered user, please signup

Are you sure you want to leave this page or do you want to book more tickets?(1/0)1

Choose an activity and get started:-
1.Sign Up for new account.	2.Login
Your Answer: 2   
Please enter your data 
namemeenal
password11234
Sorry, you are not a registered user, please signup

Are you sure you want to leave this page or do you want to book more tickets?(1/0)0

DO YOU WANT TO LOGIN AGAIN AS ADMIN OR CUSTOMER?-1/0
1
			WELCOME TO BOOK_MY_SHOW!!
Book tickets for movies, events and much more at a click.
HOW DO YOU WANT TO LOGIN?
1)CUSTOMER
2)ADMIN
1

Choose an activity and get started:-
1.Sign Up for new account.	2.Login
Your Answer: 1
Enter your data!Namelisa
Password
1234
Verify password1234
Password recorded
Please login to ur account to avail our services

Are you sure you want to leave this page or do you want to book more tickets?(1/0)1

Choose an activity and get started:-
1.Sign Up for new account.	2.Login
Your Answer: 2
Please enter your data 
namelisa
password1234
Welcome backDefaultYou may proceed to your order now

Book for 1.Movies	2.Events Near You
You desire? 2

		SEARCH FOR AN EVENT
	1.COMEDY		2.PLAYS AND CONCERTS1
SELECT YOUR CHOICE=>
	1.Kochin Komedians Featuring Utsav Chakraborty and Rupen Paul
	2.COMEDY NIGHTS WITH KAPIL LIVE SHOW
	3.The Improv - Bangalore's Most Loved Comedy Experience for the First Time in Pune2

50 SEATS AVAILABLE
CHOOSE YOUR SEAT=>"ROW"1
seat number1


Enter City: pune


Timings:
1.10AM	2.11AM	3.12.30PM	4.3PM

Enter Time : 1


Number of tickets: 2


		TICKET SUMMARY!
MOVIE	:	COMEDY
CITY	:	pune
TIMINGS :	10 AM
TICKETS :	2 tickets in SILVER Row G. Screen 6.
Your coupon code is CPAR0002414586. Show this code at the counter, pay your cash and collect your tickets!
		Thank you!
 DO YOU WANT TO BOOK MORE SEATS FOR THIS SHOW
y
			
1=>1	
49 SEATS AVAILABLE

CHOOSE YOUR SEAT=>"ROW"1
seat number1


Enter City: pune


Timings:
1.10AM	2.11AM	3.12.30PM	4.3PM

Enter Time : 1


Number of tickets: 1


		TICKET SUMMARY!
MOVIE	:	COMEDY
CITY	:	pune
TIMINGS :	10 AM
TICKETS :	1 tickets in SILVER Row G. Screen 6.
Your coupon code is CPAR0002414586. Show this code at the counter, pay your cash and collect your tickets!
		Thank you!
ALREADY BOOKED
CHOOSE YOUR SEAT=>"ROW"2
seat number2


Enter City: pune


Timings:
1.10AM	2.11AM	3.12.30PM	4.3PM

Enter Time : 1


Number of tickets: 1


		TICKET SUMMARY!
MOVIE	:	COMEDY
CITY	:	pune
TIMINGS :	10 AM
TICKETS :	1 tickets in GOLD Row H Screen 4.
Your coupon code is CPAR0002414586. Show this code at the counter, pay your cash and collect your tickets!
		Thank you!
 DO YOU WANT TO BOOK MORE SEATS FOR THIS SHOW
n

 DO YOU WANT TO BOOK MORE SEATS FOR ANOTHER  SHOW .
n
DO YOU WANT TO BOOK SEATS FOR ANNOTHER EVENTn


Are you sure you want to leave this page or do you want to book more tickets?(1/0)0

DO YOU WANT TO LOGIN AGAIN AS ADMIN OR CUSTOMER?-1/0
n


*/