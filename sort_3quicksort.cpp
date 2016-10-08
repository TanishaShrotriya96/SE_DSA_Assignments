#include<iostream>
using namespace std;
#define max 10

class sort {
public :

float array[max];
int size;

void display();
void accept();
void s();
void quick(int ,int);
int quick_part(int, int);
int quick_asc(int, int);
void quick_asc_(int, int);
void swap(int ,int);

};

int sort::quick_asc(int start,int end)
{     float a,temp;
      int down,up,x;
      a=array[start];
      down=start;
      up=end;
      while(down < up)
      {
	    while(array[down] <= a)
		 down++;
	    while(array[up] > a)
		 up--;
	    if(down < up)
		  swap(down,up);
      }
     array[start]=array[up];
     array[up]=a;
     cout<<"\nat down="<<down<<" and up= "<<up<<" pass is ";
     for(x=0;x<size;x++) {
	    cout<<array[x]<<" ";
      }
     cout<<endl;
     return up;
}
void sort::quick_asc_(int start,int end)
{
	int j;
	if(start < end)
	{
		j=quick_asc(start,end);
		quick_asc_(start,j-1);
		quick_asc_(j+1,end);
	}

}
int sort::quick_part(int start,int end)
{
	float a,temp;
	int down,up,x;
	a=array[start];
	down=start;
	up=end;
	while(down < up)
	{
		while(array[down] >= a)
			down++;
		while(array[up] < a)
			up--;
		if(down < up)
			swap(down,up);
	}
	array[start]=array[up];
	array[up]=a;
	cout<<"\nat down="<<down<<" and up= "<<up<<" pass is ";
	for(x=0;x<size;x++) {
		cout<<array[x]<<" ";
	}
	cout<<endl;
	return up;
}
void sort:: swap(int i,int j)
	{
	    float temp;
	    temp=array[i];
	    array[i]=array[j];
	    array[j]=temp;
	}
void sort::quick(int start,int end)
{
	int j;
	if(start < end)
	{
		j=quick_part(start,end);
		quick(start,j-1);
		quick(j+1,end);
	}
}

void sort:: accept() {
	int i;
	cout<<"enter size of array\n";
	cin>> size;
	cout<<"Enter array:\n";
	for(i=0;i<size;i++) {
		cin>>array[i];
	}
}

void sort::s() {
for(int i=size-1;i>-1;i--) {
	cout<<array[i]<<" ";
}
}
void sort:: display() {
        int i;
        cout<<"Sorted elements are:\n";
        for(i=0;i<size;i++) {

             cout<<array[i]<<" ";
	}
        cout<<"\nTop 5 % are\n";
        for(i=0;i<5;i++) {

             cout<<array[i]<<"  ";
	}
}
int main() {
sort num;
char ch;
int choice;
do{
cout<<"Decide your operation\n";
cout<<"\n1.Accept\n2.Display\n3.Quick Sort in ascending order\n4.Display top 5 after applying quick_sort ";
cin>>choice;
switch(choice) {
case 1:num.accept();
       break;
case 2:num.display();
       break;
case 3:num.quick_asc_(0,(num.size-1));
       cout<<endl;
	   break;
case 4:num.quick(0,num.size);
       break;
default:cout<<"Error in choice!";break;
}
cout<<"Do u want to continue?";
cin>>ch;
}while(ch=='y');

return 0;
}
/*OUTPUT
 * Decide your operation

1.Accept
2.Display
3.Quick Sort in ascending order
4.Display top 5 after applying quick_sort
1
enter size of array
7
Enter array:
70.88
30.1
20.46
50.6
60.9
10.99
40.90
Do u want to continue?y
Decide your operation

1.Accept
2.Display
3.Quick Sort in ascending order
4.Display top 5 after applying quick_sort 3

at down=15 and up= 6 pass is 40.9 30.1 20.46 50.6 60.9 10.99 70.88

at down=4 and up= 3 pass is 10.99 30.1 20.46 40.9 60.9 50.6 70.88

at down=1 and up= 0 pass is 10.99 30.1 20.46 40.9 60.9 50.6 70.88

at down=3 and up= 2 pass is 10.99 20.46 30.1 40.9 60.9 50.6 70.88

at down=6 and up= 5 pass is 10.99 20.46 30.1 40.9 50.6 60.9 70.88

Do u want to continue?y
Decide your operation

1.Accept
2.Display
3.Quick Sort in ascending order
4.Display top 5 after applying quick_sort 4

at down=7 and up= 6 pass is 70.88 20.46 30.1 40.9 50.6 60.9 10.99

at down=1 and up= 0 pass is 70.88 20.46 30.1 40.9 50.6 60.9 10.99

at down=6 and up= 5 pass is 70.88 60.9 30.1 40.9 50.6 20.46 10.99

at down=2 and up= 1 pass is 70.88 60.9 30.1 40.9 50.6 20.46 10.99

at down=5 and up= 4 pass is 70.88 60.9 50.6 40.9 30.1 20.46 10.99

at down=3 and up= 2 pass is 70.88 60.9 50.6 40.9 30.1 20.46 10.99
Do u want to continue?y
Decide your operation

1.Accept
2.Display
3.Quick Sort in ascending order
4.Display top 5 after applying quick_sort 2
Sorted elements are:
70.88 60.9 50.6 40.9 30.1 20.46 10.99
Top 5 % are
70.88  60.9  50.6  40.9  30.1  Do u want to continue?
*/

