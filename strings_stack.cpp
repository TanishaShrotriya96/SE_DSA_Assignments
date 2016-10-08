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
	char st[50];
public:
	void stackRev();
	void push(char c);
    char pop();
	//void display_top();
    int isEmpty();
	int isFull();
	void palindrome();
	void toLower();

	stack() {
	     top=-1;
	     MAXSIZE=50;
	};

};
void stack::toLower() {
	        int size,i,j=0;
	        char str2[50],str1[50];
	        cout<<"Enter String, to exit enter # and enter";
	        cin.getline(str2,50,'#');
	        size=strlen(str2);

			for(i=0;i<size;i++) {
				if(str2[i]!=' '&&str2[i]!='\t'&&ispunct(str2[i])==0&&str2[i]!='\n') {
					st[j]=tolower(str2[i]);
					j++;
				}
			}st[j]='\0';
			cout<<st;
			palindrome();

}
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
void stack:: stackRev() {
	    int size;

        cin.getline(st,MAXSIZE,'#');
        size=strlen(st);
		for(int i=0;i<size ;i++) {
		    push(st[i]);
	    }
		for(int i=0;i<size;i++) {
	        cout<<pop();
		}

}

void stack::palindrome() {
	   /* char str[20];
	    for(int i=0;i<strlen(st);i++) {
		        str[i]=pop();
			}
	    cout<<strcmp(st,str);*/
	        char str[50];

		    int size=strlen(st);
		    for(int i=0;i<size;i++) {
		    		    push(st[i]);
		    	    }
		    for(int i=0;i<size;i++) {
			        str[i]=pop();
				}

		    int status=strcmp(st,str);   /* if Return value if < 0 then it indicates string1 is less than string2
		                                    if Return value if > 0 then it indicates string2 is less than string1
		                                    if Return value if = 0 then it indicates string1 is equal to string2*/

		    if(status==0)
		    	cout<<"\nString is Palindrome";
		    else
		    	cout<<"\nString is not a Palindrome";
}


int main() {
	    int choice;
	    stack st1;
	    char ch;
	    do {
	    cout<<"Enter operation to do:\n MENU:\n 1.Reverse\n2.Palindrome\n3.Truncate";
		cin>>choice;
		switch(choice) {
		    case 1:cout<<"To reverse\n";
		           cout<<"Enter String, to exit enter space and enter\n";
		    	   st1.stackRev();break;
		    case 2:cout<<"Enter String, to exit enter space and enter\n";
		    	   st1.stackRev();
		           st1.palindrome();break;
		    case 3:st1.toLower();break;
		    default:cout<<"Error";break;
		}
		cout<<"\nDo u want to continue?y/n";
		cin>>ch;
	    }while(ch=='y');
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
