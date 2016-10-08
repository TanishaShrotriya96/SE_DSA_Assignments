#include<iostream>
using namespace std;
#define max 10

class sort {
float a[max];
int size;
public :
void bubble();
void display();
void select();
void accept();
void bubble_des();
void selection_des();
};
void sort:: accept() {
	int i;
	cout<<"enter size of array\n";
	cin>> size;
	cout<<"Enter array:\n";
	for(i=0;i<size;i++) {
		cin>>a[i];
	}
}
void sort:: bubble() {
        int i,k,j;
        float temp;
        for(i=0;i<size;i++) {
         for(j=0;j<size-1;j++) {
           if(a[j]>a[j+1]) {
             temp=a[j];
             a[j]=a[j+1];
             a[j+1]=temp;
           }
         }
        cout<<"parse is\n"<<i<<" => ";
        for(k=0;k<size;k++){
           cout<<a[k]<<" ";
        }
        cout<<"\n";
        }
}
void sort:: bubble_des() {
        int i,k,j;
        float temp;
        for(i=0;i<size;i++) {
         for(j=0;j<size-1;j++) {
           if(a[j]<a[j+1]) {
             temp=a[j];
             a[j]=a[j+1];
             a[j+1]=temp;
           }
         }
        cout<<"parse is\n"<<i<<" => ";
        for(k=0;k<size;k++){
           cout<<a[k]<<" ";
        }
        cout<<"\n";
        }
}
void sort:: select() {
     int k,i,j,min;
     float temp;
     for(i=0;i<size;i++) {
        min=i;
        for(j=i+1;j<size;j++) {
           if(a[min]>a[j])
              min=j;
        }
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
        cout<<"parse is\n"<<i<<"=>";
        for(k=0;k<size;k++){
           cout<<a[k]<<" ";
        }
        cout<<"\n";
     }
}
void sort:: selection_des() {
     int k,i,j,min;
     float temp;
     for(i=0;i<size;i++) {
        min=i;
        for(j=i+1;j<size;j++) {
           if(a[min]<a[j])
              min=j;
        }
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
        cout<<"parse is\n"<<i<<"=>";
        for(k=0;k<size;k++){
           cout<<a[k]<<" ";
        }
        cout<<"\n";
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
cout<<"1.Accept array for student %\n2.Apply Bubble Sort to show array in Ascending order";
cout<<"\n3.Apply Selection Sort to show array in ascending order\n4.Display top 5 % with bubble";
cout<<"\n5.Display top 5 % with selection";
cin>>choice;
switch(choice) {
case 1:num.accept();
       break;
case 2:num.bubble();
       break;
case 3:num.select();
       break;
case 4:num.bubble_des();
       num.display();
       break;
case 5:num.selection_des();
       num.display();
       break;

default:cout<<"Error in choice!";break;
}
cout<<"\nDo u want to continue?";
cin>>ch;
}while(ch=='y');

return 0;
}
/*OUTPUT
Decide your operation
1.Accept array for student %
2.Apply Bubble Sort to show array in Ascending order
3.Apply Selection Sort to show array in ascending order
4.Display top 5 % with bubble
5.Display top 5 % with selection
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
1.Accept array for student %
2.Apply Bubble Sort to show array in Ascending order
3.Apply Selection Sort to show array in ascending order
4.Display top 5 % with bubble
5.Display top 5 % with selection2
parse is
0 => 30.46 20.18 50.99 60.8 10.9 40.56 70.88
parse is
1 => 20.18 30.46 50.99 10.9 40.56 60.8 70.88
parse is
2 => 20.18 30.46 10.9 40.56 50.99 60.8 70.88
parse is
3 => 20.18 10.9 30.46 40.56 50.99 60.8 70.88
parse is
4 => 10.9 20.18 30.46 40.56 50.99 60.8 70.88
parse is
5 => 10.9 20.18 30.46 40.56 50.99 60.8 70.88
parse is
6 => 10.9 20.18 30.46 40.56 50.99 60.8 70.88
Do u want to continue?y
Decide your operation
1.Accept array for student %
2.Apply Bubble Sort to show array in Ascending order
3.Apply Selection Sort to show array in ascending order
4.Display top 5 % with bubble
5.Display top 5 % with selection1
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
1.Accept array for student %
2.Apply Bubble Sort to show array in Ascending order
3.Apply Selection Sort to show array in ascending order
4.Display top 5 % with bubble
5.Display top 5 % with selection3
parse is
0=>10.9 30.46 20.18 50.99 60.8 70.88 40.56
parse is
1=>10.9 20.18 30.46 50.99 60.8 70.88 40.56
parse is
2=>10.9 20.18 30.46 50.99 60.8 70.88 40.56
parse is
3=>10.9 20.18 30.46 40.56 60.8 70.88 50.99
parse is
4=>10.9 20.18 30.46 40.56 50.99 70.88 60.8
parse is
5=>10.9 20.18 30.46 40.56 50.99 60.8 70.88
parse is
6=>10.9 20.18 30.46 40.56 50.99 60.8 70.88
Do u want to continue?y
Decide your operation
1.Accept array for student %
2.Apply Bubble Sort to show array in Ascending order
3.Apply Selection Sort to show array in ascending order
4.Display top 5 % with bubble
5.Display top 5 % with selection1
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
1.Accept array for student %
2.Apply Bubble Sort to show array in Ascending order
3.Apply Selection Sort to show array in ascending order
4.Display top 5 % with bubble
5.Display top 5 % with selection4
parse is
0 => 70.88 30.46 50.99 60.8 20.18 40.56 10.9
parse is
1 => 70.88 50.99 60.8 30.46 40.56 20.18 10.9
parse is
2 => 70.88 60.8 50.99 40.56 30.46 20.18 10.9
parse is
3 => 70.88 60.8 50.99 40.56 30.46 20.18 10.9
parse is
4 => 70.88 60.8 50.99 40.56 30.46 20.18 10.9
parse is
5 => 70.88 60.8 50.99 40.56 30.46 20.18 10.9
parse is
6 => 70.88 60.8 50.99 40.56 30.46 20.18 10.9
Sorted elements are:
70.88 60.8 50.99 40.56 30.46 20.18 10.9
Top 5 % are
70.88 60.8 50.99 40.56 30.46
Do u want to continue?y
Decide your operation
1.Accept array for student %
2.Apply Bubble Sort to show array in Ascending order
3.Apply Selection Sort to show array in ascending order
4.Display top 5 % with bubble
5.Display top 5 % with selection1
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
1.Accept array for student %
2.Apply Bubble Sort to show array in Ascending order
3.Apply Selection Sort to show array in ascending order
4.Display top 5 % with bubble
5.Display top 5 % with selection5
parse is
0=>70.88 30.46 20.18 50.99 60.8 10.9 40.56
parse is
1=>70.88 60.8 20.18 50.99 30.46 10.9 40.56
parse is
2=>70.88 60.8 50.99 20.18 30.46 10.9 40.56
parse is
3=>70.88 60.8 50.99 40.56 30.46 10.9 20.18
parse is
4=>70.88 60.8 50.99 40.56 30.46 10.9 20.18
parse is
5=>70.88 60.8 50.99 40.56 30.46 20.18 10.9
parse is
6=>70.88 60.8 50.99 40.56 30.46 20.18 10.9
Sorted elements are:
70.88 60.8 50.99 40.56 30.46 20.18 10.9
Top 5 % are
70.88 60.8 50.99 40.56 30.46
Do u want to continue?n
*/
