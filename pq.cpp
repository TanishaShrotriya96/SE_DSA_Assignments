//============================================================================
// Name        : pq.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//============================================================================
// Name        : priority_queue.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define MAX 5
class job {
	int id,priority;
	friend class pqueue;
public:
	job() {
		priority=0;
		id=0;
	}
	void getData() {
		cout<<"id";
	    cin>>id;
	    cout<<"priority?";
	    cin>>priority;
	}
	void display() {
		cout<<"id ";
		cout<<id;
		cout<<" priority ";
	    cout<<priority;
	}
};
class pqueue {
	int front,rear;
	job I[MAX];
public:
	pqueue() {
		front=0;
		rear=0;
	}
	void add();
	void display();
	int removeFront();
	int removeBack();
	int isFull();
	int isEmp();
};
void pqueue::add() {//sorts while adding new data

	int i=0,j=0,size;
	job temp;
	if(isFull()==0){
	cout<<"Enter size of data to be stored";
	cin>>size;
	cout<<"Enter the number\n";
	for(i=0;i<size;i++) {
	  I[j].getData();
      while(j>=front) {
	     if(j!=0 && I[j].priority<I[j-1].priority) {
		     temp=I[j];
		     I[j]=I[j-1];
		     I[j-1]=temp;
	     }
	     if(j==front) {
	   			j=rear; //resets j for addition of next data
	   		    break;
	     }
		 j--;
      }
      j++;
      rear++;
	}
	}
	else if(isFull()==1) {
		cout<<"Queue is full";
	}
}
void pqueue::display() {
int i;
if(isEmp()==0) {
for(i=front;i<rear;i++) {
	cout<<"ID is "<<I[i].id;
    cout<<" Priority is "<<I[i].priority<<"\n";
}
}
else {
	cout<<"Queue is empty";
}

}
int pqueue::removeFront() {
   if(front !=rear) {
	cout<<"Element at front, value = "<<I[front].id<<" will be removed";
    front++;
   }
   else {
	   cout<<"Queue is empty";

   }
	return 0;
}
/*int pqueue::removeBack() {
    cout<<"Element at back, value = "<<I[rear].id<<" will be removed";
    rear--;
	return 0;
}*/
int pqueue::isFull() {
	if(rear==MAX)
	  return 1;//is full condition
	else
     return 0;
}
int pqueue::isEmp() {
	if(rear==front)
		return 1;//is empty condition
	else
		return 0;
}
int main() {
	pqueue q;
	int choice;
	char ch;
	do{
    cout<<"Choose operation:\n1.Add\n2.Display\n3.Remove from front\n";
	cin>>choice;
	switch(choice){
	case 1:q.add();
	       break;
	case 2:q.display();
           break;
	case 3:q.removeFront();
	       break;
	default:cout<<"Error in choice\n";
	        break;
	}
	//q.removeBack();
    cout<<"\nDo u want to continue?";
    cin>>ch;
	}while(ch=='y');
	return 0;
}
/*
Choose operation:
1.Add
2.Display
3.Remove from front
2
Queue is empty
Do u want to continue?y
Choose operation:
1.Add
2.Display
3.Remove from front
1
Enter size of data to be stored5
Enter the number
id1
priority?2
id2
priority?3
id3
priority?4
id4
priority?5
id5
priority?1

Do u want to continue?y
Choose operation:
1.Add
2.Display
3.Remove from front
2
ID is 5 Priority is 1
ID is 1 Priority is 2
ID is 2 Priority is 3
ID is 3 Priority is 4
ID is 4 Priority is 5

Do u want to continue?y
Choose operation:
1.Add
2.Display
3.Remove from front
1
Queue is full
Do u want to continue?y
Choose operation:
1.Add
2.Display
3.Remove from front
3
Element at front, value = 5 will be removed
Do u want to continue?y
Choose operation:
1.Add
2.Display
3.Remove from front
3
Element at front, value = 1 will be removed
Do u want to continue?y
Choose operation:
1.Add
2.Display
3.Remove from front
3
Element at front, value = 2 will be removed
Do u want to continue?y
Choose operation:
1.Add
2.Display
3.Remove from front
3
Element at front, value = 3 will be removed
Do u want to continue?y
Choose operation:
1.Add
2.Display
3.Remove from front
3
Element at front, value = 4 will be removed
Do u want to continue?y
Choose operation:
1.Add
2.Display
3.Remove from front
3
Queue is empty
Do u want to continue?y
Choose operation:
1.Add
2.Display
3.Remove from front
3
Queue is empty
Do u want to continue?y
Choose operation:
1.Add
2.Display
3.Remove from front
2
Queue is empty
Do u want to continue?n
 */
