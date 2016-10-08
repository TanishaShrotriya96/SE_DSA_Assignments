
































































































































//============================================================================
// Name        : QADT.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define max 3 //check underflow and overflow condition!!
using namespace std;
class queue {
	int a[max];
	int front,rear;
public:
	queue() {
		front=0;
		rear=-1;
	}
	int isEmpty();
	int isFull();
	int enQ(int);
	int deQ();
};
int queue:: enQ(int c) {
	if(isFull()==0) {

		a[++rear]=c;
		return 0;
	}
	else
		return 0;
}

int queue:: deQ() {
	char data;
	if(isEmpty()==0) {
		data=a[front++];

		return data;
	}
	else {
		return 0;
	}

}
int queue:: isEmpty() {
if(rear==-1)
  return 1;//qempty condition
else
return 0;
}
int queue:: isFull() {
if(rear==max-1)
	return 1;//qfull condition
else
    return 0;
}
int main() {
        int choice,size,data,flag=0,f2,x=0;
	    queue q1;
	    char ch;
	    do {
	    cout<<"Enter operation to do:\nMENU:\n1.Enter\n2.Display\n";
		cin>>choice;
		switch(choice) {
		    case 1:flag=q1.isFull();
		           if(flag==0){
		    	    cout<<"Enter size of array";
		            cin>>size;
		            cout<<"Enter array elements";
		            x=0;
		            while(x<size) {
		               cin>>data;
		    		   q1.enQ(data);
		    		   x++;
		    	    }
		           }
		           else {
		        	   cout<<"Queue is full";
		           }
		    	   break;
		    case 2:cout<<"The current elements of array are:\n";
		          x=0;
		         f2=q1.isEmpty();
		         if(f2==0) {
		         while(x<size){
		           cout<<q1.deQ()<<" ";
		           x++;
		    	  }
		         }
		         else if(f2==1) {
		        	 cout<<"Queue is empty";
		           }
		           break;
		    default:cout<<"Error";break;
		}
		cout<<"\nDo u want to continue?y/n";
		cin>>ch;
	    }while(ch=='y');
	return 0;
}
/*
 * OUTPUT
 *Enter operation to do:
MENU:
1.Enter
2.Display
2
The current elements of array are:
Queue is empty
Do u want to continue?y/ny
Enter operation to do:
MENU:
1.Enter
2.Display
1
Enter size of array3
Enter array elements1
2
3

Do u want to continue?y/ny
Enter operation to do:
MENU:
1.Enter
2.Display
2
The current elements of array are:
1 2 3
Do u want to continue?y/ny
Enter operation to do:
MENU:
1.Enter
2.Display
1
Queue is full
Do u want to continue?y/nn
 *
 */

