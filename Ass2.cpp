//============================================================================
// Name        : Assignment_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class matrix{

  int srow_A,scol_A,srow_B,scol_B,srow_res,scol_res,A[10][10],B[10][10],res[10][10],i,j,k,flag;//Variables declared private
  public: //memeber functions made public
    char flag_;
	void accept_A();
	void accept_B();
	void display();
	void display_A();
	void display_B();
	void transpose();
	void add();
	void multiply();
	void upper();
	void sum_diagonal();
};

void matrix::accept_A(){

	cout<<"Enter the row and column size of your matrix A";
	cin>>srow_A>>scol_A;//cin>>x,b; works in eclipse but is almost as good as decrepated.
 cout<<"Please enter the matrix:";
	for(i=0;i<srow_A;i++){
		for(j=0;j<scol_A;j++){
			cin>>A[i][j];
		}
	}
}

void matrix::accept_B(){
	cout<<"Enter the row and column size of your matrix B";
	cin>>srow_B>>scol_B;
	cout<<"Please enter the matrix:";
		for(i=0;i<srow_B;i++){
			for(j=0;j<scol_B;j++){
				cin>>B[i][j];
			}
		}

}

void matrix::display_A(){

	for(i=0;i<srow_A;i++){
			for(j=0;j<scol_A;j++){
				cout<<A[i][j]<<" ";
			}
			cout<<"\n";
		}
}

void matrix::display_B(){
	cout<<"The matrix taken as B is:\n";
	for(i=0;i<srow_B;i++){
			for(j=0;j<scol_B;j++){
				cout<<B[i][j]<<" ";
			}
			cout<<"\n";
		}
}

void matrix::display(){

for(i=0;i<srow_res;i++){
	for(j=0;j<scol_res;j++){
			cout<<res[i][j]<<" ";
	}cout<<"\n";
}

}

void matrix::upper(){
    flag=0;
    cout<<"\nChecking if A is an upper triangular...\n";
	for(i=0;i<srow_A;i++){
		j=i;
		if(A[i][j]!=0){
			flag=1;
			break;
		}
	}

	for(i=1;i<scol_A;i++){
		for(j=0;j<i;j++){

			if(A[i][j]!=0){
				flag=1;
                 break;
			}
	    }
	}

	if(flag==0){

		cout<<"Matrix is upper triangular!!:D";

	}

	else{
		cout<<"Matrix is not upper triangular";
	}
}

void matrix::add(){
srow_res=0;
scol_res=0;
 if(srow_A==srow_B && scol_A==scol_B){
	 srow_res=srow_A;
	 scol_res=scol_A;
	 for(i=0;i<srow_A;i++){
		 for(j=0;j<scol_A;j++){

			 res[i][j]=A[i][j]+B[i][j];

		 }

	 }
	 cout<<"The addition result is:";
	 display();
 }
 else{
	 cout<<"Sorry, addition isn't possible. ";
	 cout<<"Why don't you display a matrix of the same size as A?\n";
	 accept_B();
	 display_B();
	 add();
 }

}

void matrix::multiply(){
int sum=0;
if(scol_A==srow_B){
 srow_res=srow_A;
 scol_res=scol_A;
 for(i=0;i<srow_A;i++){
	for(j=0;j<scol_B;j++){
		for(k=0;k<scol_A;k++){
			sum=sum+A[i][k]*B[k][j];
		}
		res[i][j]=sum;
	}
 }
 cout<<"the result of multiplication is:";
 display();
}
else{
	cout<<"\n multiplication isn't possible.";
}
}

void matrix::transpose(){

if(srow_A==scol_A){
	for(i=0;i<srow_A;i++){
		for(j=0;j<i;j++){
		    int temp;
			temp=A[i][j];
			A[i][j]=A[j][i];
			A[j][i]=temp;
		}
	}
	if(flag_='n'){//checks value of flag given by user, to not print the transpose of A again.
	cout<<"\nThe matrix transpose of A is:\n";
	display_A();
	}
}
else{
	int Trans[scol_A][srow_A];
	for(i=0;i<srow_A;i++){
			for(j=0;j<scol_A;j++){
				Trans[j][i]=A[i][j];
			}
		}

    for(i=0;i<scol_A;i++){
        for(j=0;j<srow_A;j++){
			cout<<Trans[i][j]<<" ";
	    }cout<<"\n";
    }
}
}

void matrix::sum_diagonal(){
int sum=0;
cout<<"\nComputed sum of diagonal elements of matrix A:";
i=0;
j=scol_A-1;
while(i<srow_A&&j>=0){

			if(i!=j){
            sum=sum+A[i][j];//both the conditions on i and j switch together,
                           //so we cannot use nested for loops.Break isn't necessary
           	}
			i++;
			j--;
}
for(i=0;i<srow_A;i++){

	sum=sum+A[i][i];

}
cout<<" "<<sum;
}

int main() {
	matrix mat,data;
	char ch;
	do{
    char flag=mat.flag_='n';
	mat.accept_A();
	cout<<"The matrix taken as A is:\n";
    mat.display_A();
    mat.upper();
    mat.sum_diagonal();
    mat.transpose();
    mat.accept_B();
    mat.display_B();
    cout<<"Do you want to perform matrix operations?";
    cin>>flag;
    if(flag='y'){
    mat.transpose();
    mat.add();
    mat.multiply();}


    cout<<"Do u want to continue?y/n";
    cin>>ch;
	}while(ch=='y');
	return 0;
}
/*
OutPut:
Enter the row and column size of your matrix A
3
3
Please enter the matrix:
1
2
3
4
5
6
7
8
9
The matrix taken as A is:
1 2 3 
4 5 6 
7 8 9 

Checking if A is an upper triangular...
Matrix is not upper triangular
Computed sum of diagonal elements of matrix A: 25
The matrix transpose of A is:
1 4 7 
2 5 8 
3 6 9 
Enter the row and column size of your matrix B
2
2
Please enter the matrix:1
2
3
4
The matrix taken as B is:
1 2 
3 4 
Do you want to perform matrix operations?y

The matrix transpose of A is:
1 2 3 
4 5 6 
7 8 9 
Sorry, addition isn't possible. Why don't you display a matrix of the same size as A?
Enter the row and column size of your matrix B3
3
Please enter the matrix:
1
3
5
7
9
1
1
3
5
The matrix taken as B is:
1 3 5 
7 9 1 
1 3 5 
The addition result is:
 2  5  8 
11 14  7 
 8 11 14 
the result of multiplication is:
18   48  70 
115 190 245 
317 437 525 
Do u want to continue?y/ny
Enter the row and column size of your matrix A 
1
2
Please enter the matrix:1
2
The matrix taken as A is:
1 2 

Checking if A is an upper triangular...
Matrix is not upper triangular
Computed sum of diagonal elements of matrix A: 31 
2 
Enter the row and column size of your matrix B 
1
2
Please enter the matrix: 
3
4
The matrix taken as B is:
3 4 
Do you want to perform matrix operations?y
1 
2 
The addition result is:4 6 

 multiplication isn't possible.Do u want to continue?y/nn

END OF PROGRAM
*/
