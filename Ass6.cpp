//============================================================================
// Name        : assign6_merge.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class dnode {
	int data;
	dnode *prev;
	dnode *next;

public:
	dnode(int d) {
		data=d;
		next=NULL;
		prev=NULL;
    }
	friend class dlist;
};

class dlist {
	dnode *start;
public:
	dlist() {
		start=NULL;
	}
	void createlist();
	void display();
	void merge(dlist,dlist);
	

};

void dlist::createlist() {
	dnode *ptr,*prev,*temp;
	int d,count=1, ans,x;
	cout<<"\nHow many nodes are to be added?";
	cin>>ans;
	cout<<"\nEnter the numbers in ascending order only: \n";

	while(count<=ans){
	
	cin>>d;
	temp= new dnode (d);
	if(start==NULL)
	{
		start=temp;

	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
		temp->prev=ptr;
	}
	count=count+1;
	x=temp->data;

  }

}
void dlist::display() {
	dnode *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<endl;
		ptr=ptr->next;
	}

}

void dlist :: merge(dlist s1, dlist s2) {

dnode *ptr,*ptr1,*ptr2;
cout<<"hi";
 ptr1=s1.start;
 ptr2=s2.start;
 ptr=start;
 cout<<"Hi";
while(ptr1!=NULL && ptr2!=NULL)
 {
	 if(ptr1->data < ptr2->data) {
			if(start==NULL) {
				start=ptr1;
				ptr=ptr1;
			}
			else {  
			  
			    ptr->next=ptr1;
				ptr1->prev=ptr;
				ptr=ptr->next;
			}
			ptr1=ptr1->next;
		}
	 else {
					if(start==NULL) {
						start=ptr2;
						ptr=ptr2;
					}
					else {
						 
						ptr->next=ptr2;
						ptr2->prev=ptr;
						ptr=ptr->next;
					}
					ptr2=ptr2->next;
				} 
 }
 while(ptr1!=NULL)
			{
				ptr->next=ptr1;
				ptr1->prev=ptr;
				ptr=ptr->next;
				ptr1=ptr1->next;
			}
	while(ptr2!=NULL)
	{
		ptr->next=ptr2;
		ptr2->prev=ptr;
		ptr=ptr->next;
		ptr2=ptr2->next;
	}

 }

int main()
{
	dlist l1,l2,res;
	int a;
	char ans;
	do
	{
		cout<<"***MENU***\n1.Create list\n2.Display List\n3.Merge lists\nEnter choice: ";
		cin>>a;
	switch(a)
	{
		case 1: l1.createlist();
				cout<<"\nFor list 2:";
				l2.createlist();
				break;

		case 2:	cout<<"List one is\n";
		        l1.display(); 
                cout<<"List two is\n";
		        l2.display();
				break;

		case 3: res.merge(l1,l2);
		        cout<<"\nThe merged list is: \n";
				res.display();
				break;
	}cout<<"\nDo u want to continue?";
	cin>>ans;
	}while(ans=='y');
}
/*
OUTPUT:
***MENU***
1.Create list
2.Display List
3.Merge lists
Enter choice: 1

How many nodes are to be added?4

Enter the numbers in ascending order only: 
2
4
6
8

For list 2:
How many nodes are to be added?3

Enter the numbers in ascending order only: 
1
3
7

Do u want to continue?y
***MENU***
1.Create list
2.Display List
3.Merge lists
Enter choice: 3
hiHi
The merged list is: 
1
2
3
4
6
7
8

Do u want to continue?n

END PROGRAM
*/