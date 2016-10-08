#include<iostream>
using namespace std;
#define max 10

class sort {
float a[max];
int size;
public :

void display();
void accept();
void shell();
void insertion();
void in_asc();
void shell_des();

};
void sort::in_asc() {
	int i,j,x;
    float temp;
  for(i=1;i<size;i++) {
	  temp=a[i];
	  j=i-1;
  while((j>=0)&&(a[j]<=temp)) {
	  a[j+1]=a[j];
	  j=j-1;
  }
    a[j+1]=temp;
    cout<<"while\n"<<j<<" >=0 ";
               for(x=0;x<size;x++){
                  cout<<a[x]<<" ";
               }
               cout<<"\n";
  }
    cout<<"while\n"<<i<<"  ";
            for(x=0;x<size;x++){
               cout<<a[x]<<" ";
            }
            cout<<"\n";

}
void sort::shell_des() {
	int i,j,k,d,x;
float temp;
d=size/2;
for(i=d;i>=1;i=i/2) {
 for(j=i;j<size;j++) {
  temp=a[j];
  k=j-i;
  while((k>=0)&&(a[k]<temp)) {
  a[k+i]=a[k];
  k=k-i;
  cout<<"while\n"<<k<<" >=0 ";
        for(x=0;x<size;x++){
           cout<<a[x]<<" ";
        }
        cout<<"\n";
  }
  a[k+i]=temp;
 cout<<"value of j is\n"<<j<<" => ";
        for(x=0;x<size;x++){
           cout<<a[x]<<" ";
        }
        cout<<"\n";
 }
  cout<<"parse is\n"<<i<<" => ";
        for(x=0;x<size;x++){
           cout<<a[x]<<" ";
        }
        cout<<"\n";
}


}
void sort:: insertion() {
  int i,j,x;
 float temp;
  for(i=1;i<size;i++) {
	  temp=a[i];
	  j=i-1;
  while((j>=0)&&(a[j]>=temp)) {
	  a[j+1]=a[j];
	  j=j-1;
  }
    a[j+1]=temp;
    cout<<"while\n"<<j<<" >=0 ";
               for(x=0;x<size;x++){
                  cout<<a[x]<<" ";
               }
               cout<<"\n";
  }
    cout<<"while\n"<<i<<"  ";
            for(x=0;x<size;x++){
               cout<<a[x]<<" ";
            }
            cout<<"\n";
}

void sort::shell() {
int i,j,k,d,x;
float temp;
d=size/2;
for(i=d;i>=1;i=i/2) {
 for(j=i;j<size;j++) {
  temp=a[j];
  k=j-i;
  while((k>=0)&&(a[k]>temp)) {
  a[k+i]=a[k];
  k=k-i;
  cout<<"while\n"<<k<<" >=0 ";
        for(x=0;x<size;x++){
           cout<<a[x]<<" ";
        }
        cout<<"\n";
  }
  a[k+i]=temp;
 cout<<"value of j is\n"<<j<<" => ";
        for(x=0;x<size;x++){
           cout<<a[x]<<" ";
        }
        cout<<"\n";
 }
  cout<<"parse is\n"<<i<<" => ";
        for(x=0;x<size;x++){
           cout<<a[x]<<" ";
        }
        cout<<"\n";
}

}
void sort:: accept() {
	int i;
	cout<<"enter size of array\n";
	cin>> size;
	cout<<"Enter array:\n";
	for(i=0;i<size;i++) {
		cin>>a[i];
	}
}

void sort:: display() {
        int i;
        cout<<"Sorted elements are:\n";
        for(i=0;i<size;i++) {

             cout<<a[i]<<" ";
	}
        cout<<"\nTop 5 % are\n";
        for(i=0;i<5;i++) {

             cout<<a[i]<<" ";
	}
}
int main() {
sort num;
char ch;
int choice;
do{
cout<<"Decide your operation\n";
cout<<"\n1.Accept\n2.Apply Shell Sort\n3.Insertion Sort\n4.Descending insertion\n5.Descending Shell\n";
cin>>choice;
switch(choice) {
case 1:num.accept();
       break;
case 2:num.shell();
       break;
case 3:num.insertion();
       break;
case 4:num.in_asc();
       num.display();
	   break;
case 5:num.shell_des();	   
       num.display();
       break;
default:cout<<"\nError in choice!";break;
}
cout<<"\nDo u want to continue?";
cin>>ch;
}while(ch=='y');

return 0;
}
/*
Decide your operation

1.Accept
2.Apply Shell Sort
3.Insertion Sort
4.Descending insertion
5.Descending Shell
1
enter size of array
7
Enter array:
70.88
30.46
20.18
50.99
60.8
10.9
40.56

Do u want to continue?y
Decide your operation

1.Accept
2.Apply Shell Sort
3.Insertion Sort
4.Descending insertion
5.Descending Shell
2
while
-3 >=0 70.88 30.46 20.18 70.88 60.8 10.9 40.56 
value of j is
3 => 50.99 30.46 20.18 70.88 60.8 10.9 40.56 
value of j is
4 => 50.99 30.46 20.18 70.88 60.8 10.9 40.56 
while
-1 >=0 50.99 30.46 20.18 70.88 60.8 20.18 40.56 
value of j is
5 => 50.99 30.46 10.9 70.88 60.8 20.18 40.56 
while
0 >=0 50.99 30.46 10.9 70.88 60.8 20.18 70.88 
while
-3 >=0 50.99 30.46 10.9 50.99 60.8 20.18 70.88 
value of j is
6 => 40.56 30.46 10.9 50.99 60.8 20.18 70.88 
parse is
3 => 40.56 30.46 10.9 50.99 60.8 20.18 70.88 
while
-1 >=0 40.56 40.56 10.9 50.99 60.8 20.18 70.88 
value of j is
1 => 30.46 40.56 10.9 50.99 60.8 20.18 70.88 
while
0 >=0 30.46 40.56 40.56 50.99 60.8 20.18 70.88 
while
-1 >=0 30.46 30.46 40.56 50.99 60.8 20.18 70.88 
value of j is
2 => 10.9 30.46 40.56 50.99 60.8 20.18 70.88 
value of j is
3 => 10.9 30.46 40.56 50.99 60.8 20.18 70.88 
value of j is
4 => 10.9 30.46 40.56 50.99 60.8 20.18 70.88 
while
3 >=0 10.9 30.46 40.56 50.99 60.8 60.8 70.88 
while
2 >=0 10.9 30.46 40.56 50.99 50.99 60.8 70.88 
while
1 >=0 10.9 30.46 40.56 40.56 50.99 60.8 70.88 
while
0 >=0 10.9 30.46 30.46 40.56 50.99 60.8 70.88 
value of j is
5 => 10.9 20.18 30.46 40.56 50.99 60.8 70.88 
value of j is
6 => 10.9 20.18 30.46 40.56 50.99 60.8 70.88 
parse is
1 => 10.9 20.18 30.46 40.56 50.99 60.8 70.88 

Do u want to continue?y
Decide your operation

1.Accept
2.Apply Shell Sort
3.Insertion Sort
4.Descending insertion
5.Descending Shell
7

Error in choice!
Do u want to continue?y
Decide your operation

1.Accept
2.Apply Shell Sort
3.Insertion Sort
4.Descending insertion
5.Descending Shell
1
enter size of array
7
Enter array:
70.88
30.46
20.18
50.99
60.88
10.9
40.65

Do u want to continue?y
Decide your operation

1.Accept
2.Apply Shell Sort
3.Insertion Sort
4.Descending insertion
5.Descending Shell
3
while
-1 >=0 30.46 70.88 20.18 50.99 60.88 10.9 40.65 
while
-1 >=0 20.18 30.46 70.88 50.99 60.88 10.9 40.65 
while
1 >=0 20.18 30.46 50.99 70.88 60.88 10.9 40.65 
while
2 >=0 20.18 30.46 50.99 60.88 70.88 10.9 40.65 
while
-1 >=0 10.9 20.18 30.46 50.99 60.88 70.88 40.65 
while
2 >=0 10.9 20.18 30.46 40.65 50.99 60.88 70.88 
while
7  10.9 20.18 30.46 40.65 50.99 60.88 70.88 

Do u want to continue?y
Decide your operation

1.Accept
2.Apply Shell Sort
3.Insertion Sort
4.Descending insertion
5.Descending Shell
4
while
-1 >=0 20.18 10.9 30.46 40.65 50.99 60.88 70.88 
while
-1 >=0 30.46 20.18 10.9 40.65 50.99 60.88 70.88 
while
-1 >=0 40.65 30.46 20.18 10.9 50.99 60.88 70.88 
while
-1 >=0 50.99 40.65 30.46 20.18 10.9 60.88 70.88 
while
-1 >=0 60.88 50.99 40.65 30.46 20.18 10.9 70.88 
while
-1 >=0 70.88 60.88 50.99 40.65 30.46 20.18 10.9 
while
7  70.88 60.88 50.99 40.65 30.46 20.18 10.9 
Sorted elements are:
70.88 60.88 50.99 40.65 30.46 20.18 10.9 
Top 5 % are
70.88 60.88 50.99 40.65 30.46 
Do u want to continue?y
Decide your operation

1.Accept
2.Apply Shell Sort
3.Insertion Sort
4.Descending insertion
5.Descending Shell
1
enter size of array
5
Enter array:
99.9
92.8
94
88.6 
96.55

Do u want to continue?y
Decide your operation

1.Accept
2.Apply Shell Sort
3.Insertion Sort
4.Descending insertion
5.Descending Shell
5
value of j is
2 => 99.9 92.8 94 88.6 96.55 
value of j is
3 => 99.9 92.8 94 88.6 96.55 
while
0 >=0 99.9 92.8 94 88.6 94 
value of j is
4 => 99.9 92.8 96.55 88.6 94 
parse is
2 => 99.9 92.8 96.55 88.6 94 
value of j is
1 => 99.9 92.8 96.55 88.6 94 
while
0 >=0 99.9 92.8 92.8 88.6 94 
value of j is
2 => 99.9 96.55 92.8 88.6 94 
value of j is
3 => 99.9 96.55 92.8 88.6 94 
while
2 >=0 99.9 96.55 92.8 88.6 88.6 
while
1 >=0 99.9 96.55 92.8 92.8 88.6 
value of j is
4 => 99.9 96.55 94 92.8 88.6 
parse is
1 => 99.9 96.55 94 92.8 88.6 
Sorted elements are:
99.9 96.55 94 92.8 88.6 
Top 5 % are
99.9 96.55 94 92.8 88.6 
Do u want to continue?n
*/