//============================================================================
// Name        : searching.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define max 10
using namespace std;
class search{
	int a[max],size;
public:
 void sequential();
 void binary();
 void accept();
 void sorted();
 int fib(int);
 int fibsearch(int);
  void sentinel();
  int binary_recursive(int a[],int size,int low,int high,int mid,int key);
 void recursive();
  int calc(int l,int h)
  {
  	int ans;
  	ans=(l+h)/2;
  	return ans;
  }
};
int search:: fib(int n) {
	if(n==0||n==1)
		return 1;
	else {
		return(fib(n-2)+fib(n-1));
	}
}
int search::fibsearch(int key) {
	int f1,f2,mid,j,f,t;
	j=1;
	while(fib(j)<=size) {
		j++;
	}
	f=fib(j);
	f1=fib(j-2);
	f2=fib(j-3);
	mid=size-f1+1;

	while (key!=a[mid]) {
	 if(mid <0||key>a[mid]) {
			if(f1==1)
			   return -1;
		    mid=mid +f2;
			f1=f1-f2;
			f2=f2-f1;



	 }
     else {
            if(f2==0)
			   return -1;
			 mid=mid-f2;
			 t=f1-f2;
			 f1=f2;
			 f2=t;
     }

   }
	 return mid;

}
void search::sentinel()
{
	int i=0;
	int size,key;
	cout<<"\nEnter total students who attended program.";
	cin>>size;
	if(size<max) {
	cout<<"\nEnter roll numbers of the students";
			for(i=0;i<size;i++)
			{
				cin>>a[i];

			}
	cout<<" Enter the roll no of student to be searched";
			cin>>key;
			a[size]=key;
			i=0;
			while(key!=a[i])
			{
				i++;
			}
		if(i<size)
			cout<<"\n The student attended the program\n";
		else cout<<"\n The student did not attend the program\n";
	}
}
int search::binary_recursive(int a[],int size,int low,int high,int mid,int key)
{

int flag=0;
while(low<=high){
			if(key==a[mid]){

				flag=1;
				break;

			}
			else if(key>a[mid])
			{
				low=mid+1;
				mid=calc(low,high);
				binary_recursive( a,size,low,high,mid,key);

			}
			else if(key<a[mid])
					{
						high=mid-1;
						mid=calc(low,high);
						binary_recursive( a, size,low,high,mid,key);
					}

}
		return flag;
}
void search::recursive()
		{
	int mid,high,low=0,flag,key,i;

	cout<<"\nThe number of students attending program ?";
			cin>>size;
		cout<<"\nEnter roll number of students attending the program\n";
			for( i=0;i<size;i++)
			{
				cin>>a[i];
			}
			cout<<"Which number you want to search?";
			cin>>key;
			high=size-1;
			mid=calc(low,high);
			flag=binary_recursive( a,size,low,high,mid,key);
			if(flag==1)
					{
						cout<<"\nStudent attended the program\n";
					}
					else
					{
						cout<<"\nStudent did not attend the program\n";
					}


		}
void search::sorted() {
	    int i,data;
		cout<<"enter size of array\n";
		cin>> size;
		cout<<"Enter array:\n";
		while(i<size) {
			cin>>data;
			if(a[i-1]<data) {
				a[i]=data;
				i++;
			}
			else {
				cout<<"Re-enter data, not in ascending order!!";
			}
		}
}
void search::accept() {
	int i;
	cout<<"enter size of array\n";
	cin>> size;
	cout<<"Enter array:\n";
	for(i=0;i<size;i++) {
		cin>>a[i];
	}
}
void search::sequential() {
	int i,j=0,desired;
	cout<<"Enter the element to search";
	cin>>desired;
	for(i=0;i<size;i++) {
		if(a[i]==desired) {
			j=1;
			break;
		}
	}
	if(j==1) {
		cout<<desired<<" element is found at "<<i<<endl;
	}
	else {
		cout<<"Element not found\n";
	}
}
void search::binary() {
	int high=(size-1),low=0,mid,desired,flag;
	cout<<"Enter the element to search\n";
	cin>>desired;
	while(low<=high) {
		mid=(high+low)/2;
		if(a[mid]==desired) {
			flag=1;
			break;
		}
		else if(a[mid]<desired) {
			low=mid+1;
		    mid=(high+low)/2;
		}
		else {
			high=mid-1;
			mid=(high+low)/2;
		}

	}
	if(flag==1) {
			cout<<desired<<" element is found at position "<<mid<<" of array\n";
		}
		else {
			cout<<"Element not found\n";
		}

}

int main() {
	int choice,key,x;
	char ch;
	search s1;
	do{
	cout<<"MENU\n1.accept array\n2.sequential search\n3.binary search";
	cout<<"n4.fibonacci search\n5.Sentinel Search\n6.Binary_recursive";
    cin>>choice;
    switch(choice) {
	case 1:s1.accept();
	       break;
	case 2:s1.sequential();
	       break;
	case 3:cout<<"Enter data in ascending order\n";
	       s1.sorted();
	       s1.binary();
	       break;
	case 4:s1.sorted();
		   cout<<"Enter student to search!";
	       cin>> key;
	       x=s1.fibsearch(key);
	       if(x==(-1)) {
		      cout<<"\nThe student did not attend";
	       }
	       else {
	    	   cout<<"\nThe student found at array position  "<<x<<"attended the program";
	       }
	       break;
	case 5:s1.sentinel();
	       break;
	case 6:s1.recursive();
	       break;
	default:cout<<"Error in choice\n";
	        break;
	}
	cout<<"do u want to continue?\n";
	cin>>ch;
	}while(ch=='y');
	cout << "!!!THANK YOU!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
/*
MENU
1.accept array
2.sequential seach
3.binary search
1
enter size of array
9
Enter array:
12
23
53
11
41
1
5
8
18
do u want to continue?
y
MENU
1.accept array
2.sequential seach
3.binary search
2
Enter the element to search23
23 element is found at 1
do u want to continue?
y
MENU
1.accept array
2.sequential seach
3.binary search
3
Enter data in ascending order
enter size of array
9
Enter array:
12
13
14
5
Re-enter data, not in ascending order!!15
16
17
18
22
33
Enter the element to search
16
16 element is found at position 4 of array
do u want to continue?
n
!!!THANK YOU!!!
*/
