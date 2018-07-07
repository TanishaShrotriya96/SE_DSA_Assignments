#include<iostream>
#include<string.h>

using namespace std;

class node {
    friend class list;
    int prn;
    char name[10];
    node * next;

public:
node(int d,char s[10]) {
    prn=d;
    strcpy(name, s);
    next =NULL;
}

};

class list {
node *start;
public:
list() {
    start=NULL;
}

void create_member();
void insert_president();
void insert_secretary();
void insert_member();
void display();
void count();
void delete_member();
void recReverse();
void concat(list);
void reverse(node *);

};
void list::delete_member() {
  char name[20];
  node *ptr,*temp,*prev;
  cout<<"Enter the name of member to delete";
  cin>>name;
  ptr=start;
  while(ptr->next!=NULL) {
    prev=ptr;
    ptr=ptr->next;
    if(name==ptr->name) {
      prev->next=ptr->next;
      ptr->next=NULL;
      delete ptr;

    }
  }
}
void list::reverse(node *ptr) {

if(ptr==NULL) {
 cout<<"Nothing to reverse";
}
else {
    reverse(ptr->next);
    cout<<"Prn of member is: ";
    cout<<ptr->prn;
    cout<<"Name of member is: ";
    cout<<ptr->name;
}
} 

void list::recReverse() {
     reverse(start);
}
void list::concat(list l2) {
  node *ptr,ptr1;
  ptr1=l2.start;
  ptr=start;
  while(ptr!=NULL) {
    ptr=ptr->next;
  }
  ptr->next=ptr1;
  display();
}
void list::insert_member() {
    node *ptr,*temp;
    int prn;
    char name[10],ch;
    do{
    cout<<"Enter the prn number of member";
    cin>>prn;
    cout<<"Enter the name of member:";
    cin>>name;
    temp=new node(prn,name);
    if(start!=NULL) {
    ptr=start;
    ptr=ptr->next;
    start->next=temp;
    temp->next=ptr;
    }
    else{ 
        cout<<"Enter the president first";
    }
    /*if(start==NULL){
        start=temp;//to add fisrt member
    }
    else{
        ptr=start;
        while(ptr->next!=NULL){
            ptr=ptr->next;//to add last member
        }
        ptr->next=temp;
    }*/
    cout<<"Do u want to continue adding members?\n";
    cin>>ch;
    }while(ch=='y');
}
void list::insert_president() {
	 node *temp,*ptr;
	    int prn;
        char ch;
	    char name[10];

	    cout<<"Enter the prn number of member";
	    cin>>prn;
	    cout<<"Enter the name of member:";
	    cin>>name;
	    temp=new node(prn,name);
	    if(start==NULL){
	        start=temp;//to add fisrt member
	    }
        else{
            cout<<"Do u want to change the president?";
            cin>>ch;
            if(ch=='y') {
                ptr=start;
                start=ptr->next;
                delete ptr;
                temp->next=start;
                start=temp;
    
            }
        }


}
void list::insert_secretary() {
	 node *ptr,*temp;
		    int prn;
		    char name[10];

		    cout<<"Enter the prn number of member";
		    cin>>prn;
		    cout<<"Enter the name of member:";
		    cin>>name;
		    temp=new node(prn,name);
            if(start!=NULL){
	        ptr=start;
		    while(ptr->next!=NULL){
		                ptr=ptr->next;
		            }
		    ptr->next=temp;
            }
            else {
                cout<<"Enter president first\n";
            }

}
void list::count() {
	
	int count=1;
	node *ptr;
	ptr=start;
	while(ptr->next!=NULL) {//not working,problem in loop
		count=count+1;
        ptr=ptr->next;
	}
	cout<<"\nTotal members are "<<count;
}
void list::display() {
node *ptr;
ptr=start;
cout<<"name of president "<<ptr->name<<"\n";
cout<<"prn of president "<<ptr->prn<<"\n";
ptr=ptr->next;
while(ptr->next!=NULL) { 
    cout<<"name of member "<<ptr->name<<"\n";
    cout<<"prn of member "<<ptr->prn<<"\n";
    ptr=ptr->next;
    
}
//here ptr has reached the last node.
cout<<"prn of secretary"<<ptr->prn;      
cout<<"\nname of secretary"<<ptr->name;
}

void list::create_member() {
int choice;
char ch;
do{
cout<<"Enter the member whose data should be entered.\n MENU \n1. President \n2.Member\n3.Secretary\n";
cin>>choice;
switch(choice) {
case 1:insert_president();
       break;
case 2:insert_member();
       break;
case 3:insert_secretary();
       break;
default:cout<<"invalid output";
        break;
}
cout<<"Do you want to see menu again?:y/n?";
cin>>ch;
}while(ch=='y');
}
int main() {
    list member,member2;
    char ch;
    int choice;
    do{
      cout<<"Please choose operation:\n1.Create a list\n2.Display list\n3.Count nodes";
      cout<<"\n4.Delete members\n5.Reverse List\n6.Concat two lists";
      cin>>choice;
      switch(choice){
      case 1:member.create_member();break;
      case 2:member.display();break;
      case 3:member.count();break;
      case 4:member.delete_member();break;
      case 5:member.recReverse();break;
      case 6:cout<<"Create list to concat:";
             member2.create_member();
             member.concat(member2);
    }
    cout<<"Would you like to continue?y/n";
    cin>>ch;
    }while(ch=='y');
}
/*
Please choose operation:
1.Create a list
2.Display list
3.Count nodes
4.Delete members
5.Reverse List
6.Concat two lists1
Enter the member whose data should be entered.
 MENU 
1. President 
2.Member
3.Secretary
1
Enter the prn number of member1
Enter the name of member:Neeta
Do you want to see menu again?:y/n?y
Enter the member whose data should be entered.
 MENU 
1. President 
2.Member
3.Secretary
2
Enter the prn number of member2
Enter the name of member:Anjali
Do u want to continue adding members?
y
Enter the prn number of member3
Enter the name of member:Ron
Do u want to continue adding members?
n
Do you want to see menu again?:y/n?y
Enter the member whose data should be entered.
 MENU 
1. President 
2.Member
3.Secretary
3
Enter the prn number of member5
Enter the name of member:Simran
Do you want to see menu again?:y/n?n
Would you like to continue?y/ny
Please choose operation:
1.Create a list
2.Display list
3.Count nodes
4.Delete members
5.Reverse List
6.Concat two lists3

Total members are 4Would you like to continue?y/ny
Please choose operation:
1.Create a list
2.Display list
3.Count nodes
4.Delete members
5.Reverse List
6.Concat two lists

*/
