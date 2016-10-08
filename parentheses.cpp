//============================================================================
// Name        : stack_final.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
using namespace std;

class stack {
	int MAXSIZE;
	int top;
	char st[20];
public:
	void stackRev();
	void push(char c);
    char pop();
	//void display_top();
    int isEmpty();
	int isFull();
	void palindrome();
	void toLower();
	void parenthesis();
	stack() {
	     top=-1;
	     MAXSIZE=20;
	};

};
void stack:: push(char c) {
	if(isFull()==1) {
		top++;
		st[top]=c;
	}
	else {
		cout<<"Stack is full,last entered data isn't recorded.";
	}
}

char stack:: pop() {
	char data;
	if(isEmpty()==0) {
		data=st[top];
		top--;
		return data;
	}
	else {
		cout<<"Stack is empty";
		return 0;
	}

}
int stack:: isEmpty() {
    if(top==-1)
        return 1;
    else
        return 0;
}
int stack:: isFull() {
    if(top==MAXSIZE-1)
	   return 0;
    else
       return 1;
}
void stack::parenthesis() {// not working for {}{}{}
	int count=0,flag=0;
	char ch;
	cout<<"Enter combination of parenthesis";
	cin.getline(st,20,'#');
	int size=strlen(st);
	for(int i=0;i<size;i++) {
		if(st[i]=='{'||st[i]=='['||st[i]=='(') {
			push(st[i]);
			count=count+1;
			flag=0;
		}


	}
	for(int i=0;i<size;i++) {
		 if(st[i]==']') {
			 ch=pop();
			 if(ch!='['){
			   flag=1;
			   break;
			 }
		 }
		 if(st[i]==')') {
					 ch=pop();
					 if(ch!='('){
					   flag=1;
					   break;
					 }
				 }

		 if(st[i]=='}') {
					 ch=pop();
					 if(ch!='{'){
					   flag=1;
					   break;
					 }
				 }

	}
	if(flag==0&&isEmpty()==0)
		cout<<"Well-formed";
	else if(flag==1 ||isEmpty()==1)
		cout<<"\nNot well formed";
}
int main() {
	    int choice;
	    stack st1;
	    char ch;
	    do {

	    st1.parenthesis();
		cout<<"\nDo u want to continue?y/n";
		cin>>ch;
	    }while(ch=='y');
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}






